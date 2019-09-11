#pragma once
#pragma warning(disable:4996)

#include <stdio.h>
#include <WinSock2.h>
#include<iostream>
#include<string>
#include <stdio.h>

#pragma comment(lib,"ws2_32.lib")

#define BUFFSIZE 255

int main()
{
    WSADATA wsaData;
    WORD nVersion = MAKEWORD(2, 2);

    if (WSAStartup(nVersion, &wsaData))
    {
        printf("WSAStart Success!\n");
        return 0;
    }

    // ������ָ���ķ����ṩ�߽��а�
    SOCKET hServer = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (hServer == INVALID_SOCKET)
    {
        printf("socket ʧ��\n");
        return 0;
    }

    sockaddr_in addrServer;
    addrServer.sin_family = AF_INET;
    addrServer.sin_port = htons(8888);
    addrServer.sin_addr.S_un.S_addr = INADDR_ANY;

    int nRet = bind(hServer, (sockaddr *)&addrServer, sizeof(addrServer));
    if (nRet == SOCKET_ERROR)
    {
        printf("bind ʧ��\n");
        closesocket(hServer);
        WSACleanup();
        return 0;
    }

    nRet = listen(hServer, 1);
    if (nRet == SOCKET_ERROR)
    {
        printf("listen ����\n");
        closesocket(hServer);
        WSACleanup();
        return 0;
    }

    SOCKET hClient;
    sockaddr_in addrClient;
    int nLen = sizeof(addrClient);

    char szBuff[BUFFSIZE];
    // ѭ�����տͻ�������
    while (TRUE)
    {

        // �������Կͻ��˵�����
        hClient = accept(hServer, (sockaddr *)&addrClient, &nLen);
        if (INVALID_SOCKET == hClient)
        {
            printf("accept ����\n");
            closesocket(hServer);
            WSACleanup();
            return 0;
        }

        memset(szBuff, 0, BUFFSIZE);

        //���յ����Կͻ��ֶ˵�����
        nRet = recv(hClient, szBuff, BUFFSIZE, 0);

        if (nRet == SOCKET_ERROR)
        {
            printf("revc ����\n");
            closesocket(hClient);
            closesocket(hServer);
            WSACleanup();
            return 0;
        }

        char chPrintfBuf[BUFFSIZE];
        sprintf(chPrintfBuf, "IP:%s,���յ�����Ϣ:%s\n", inet_ntoa(addrClient.sin_addr), szBuff);

        printf(chPrintfBuf);

        if (!strcmp(szBuff, "close"))
        {
            nRet = send(hClient, "close", strlen("close"), 0);
            break;
        }
        else
        {
            std::string strData;
            std::getline(std::cin, strData);
            sprintf(chPrintfBuf, "%s\n", strData.c_str());
            nRet = send(hClient, chPrintfBuf, strlen(chPrintfBuf), 0);
            if (nRet == SOCKET_ERROR)
            {
                printf("send ����!\n");
                closesocket(hClient);
                closesocket(hServer);
                WSACleanup();
                return 0;
            }
        }
    }

    closesocket(hClient);
    closesocket(hServer);
    WSACleanup();

    getchar();
    return 0;
}