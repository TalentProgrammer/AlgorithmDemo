#include "stdafx.h"
#include "QServer.h"
#include "Winsock2.h"

QServer::QServer()
{
}


QServer::~QServer()
{
}

BOOL QServer::InitSocketLib()
{
    WORD nVersionRequest;
    WSADATA wsaData;
    int err;

    nVersionRequest = MAKEWORD(2, 2);

    err = WSAStartup(nVersionRequest, &wsaData);

    if (err != 0)
    {
        return FALSE;
    }

    if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
    {
        WSACleanup();
        return FALSE;
    }

    //sockaddr_in

    return TRUE;
}

void QServer::UnInitSocketLib()
{
    WSACleanup();
    return;
}
