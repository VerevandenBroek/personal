#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <winsock2.h>

#pragma comment(lib, "Ws2_32.lib")

int main(void)
{
    WSADATA wsa;
    SOCKET listenSock, clientSock;
    struct sockaddr_in serverAddr;
    char buffer[1024];
    int recvSize;

    WSAStartup(MAKEWORD(2, 2), &wsa);

    listenSock = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(27015);

    bind(listenSock, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(listenSock, SOMAXCONN);

    printf("Server luistert op poort 27015...\n");

    while (1)
    {
        clientSock = accept(listenSock, NULL, NULL);
        printf("Client verbonden!\n");

        recvSize = recv(clientSock, buffer, sizeof(buffer) - 1, 0);
        buffer[recvSize] = '\0';
        printf("Ontvangen van client: %s\n", buffer);

        int fanSpeed = 1000;

        double temp = 0.0;
        if (sscanf(buffer, "TEMP=%lf", &temp) == 1)
        {
            if (temp < 20)  fanSpeed = 800;
            else if (temp < 25) fanSpeed = 1200;
            else fanSpeed = 2000;
        }

        int hum = 0;
        if (sscanf(buffer, "HUM=%d", &hum) == 1)
        {
            if (hum < 40) fanSpeed = 900;
            else if (hum < 60) fanSpeed = 1300;
            else fanSpeed = 1800;
        }

        char response[64];
        sprintf(response, "FAN=%d\n", fanSpeed);

        send(clientSock, response, strlen(response), 0);
        printf("Verstuurd: %s\n", response);

        closesocket(clientSock);
    }

    closesocket(listenSock);
    WSACleanup();
    return 0;
}