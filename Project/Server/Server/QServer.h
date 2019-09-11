#pragma once
#pragma comment(lib,"ws2_32.lib")
class QServer
{
public:
    QServer();
    ~QServer();

public:
    BOOL InitSocketLib();
    void UnInitSocketLib();
};

