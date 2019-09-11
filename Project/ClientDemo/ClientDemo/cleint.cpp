#include <WinSock2.h>
#include<iostream>
#include<string>
#include <stdio.h>

using namespace std;
#pragma comment (lib, "ws2_32.lib")

int main()
{
    WORD socketVersion = MAKEWORD(2, 2);
    WSAData data;

    if (WSAStartup(socketVersion, &data) != 0)
    {
        printf("WSAStartup success!");
        return 1;
    }

    SOCKET clientSocket;
    while (true)
    {
        clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

        if (clientSocket == INVALID_SOCKET)
        {
            printf("socket invalid!\n");
            closesocket(clientSocket);
            WSACleanup();
            return 1;
        }

        sockaddr_in sock_in;
        sock_in.sin_family = AF_INET;
        sock_in.sin_port = htons(8888);
        sock_in.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
        int nRet = connect(clientSocket, (sockaddr *)&sock_in, sizeof(sock_in));
        if (nRet == SOCKET_ERROR)
        {
            printf("connect error!\n");
            closesocket(clientSocket);
            WSACleanup();
            return 1;
        }

        string strInputData;
        std::getline(std::cin, strInputData);
        const char * pchMsg;
        pchMsg = strInputData.c_str();
        int nRet1 = send(clientSocket, pchMsg, strlen(pchMsg), 0);
        if (nRet1 == INVALID_SOCKET)
        {
            printf("send fail!\n");
        }

        char revData[100];
        int nNum = recv(clientSocket, revData, 100, 0);
        if (nNum > 0)
        {
            revData[nNum] = '\0';
            printf("recv data is %s\n", revData);
        }
        else
        {
            printf("send fail!\n");
        }
    }

    closesocket(clientSocket);
    WSACleanup();
    getchar();
    return 0;
}