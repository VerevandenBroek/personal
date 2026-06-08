#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <winsock2.h>

#pragma comment(lib, "Ws2_32.lib")

int main(void)
{
    WSADATA wsa;
    SOCKET sock;
    struct sockaddr_in serverAddr;
    char buffer[4096];
    int recvSize;

    // Winsock initialiseren
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        printf("WSAStartup failed\n");
        return 1;
    }

    // Socket maken
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET)
    {
        printf("socket failed\n");
        return 1;
    }

    // SERVER INSTELLEN → DIT DEED JE MISSEN!
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr("13.226.228.41");
    serverAddr.sin_port = htons(80);

    printf("Verbinden met example.com...\n");

    // Verbinden
    if (connect(sock, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0)
    {
        printf("connect failed\n");
        return 1;
    }

    // HTTP GET request verzenden
    char* msg =
        "GET / HTTP/1.1\r\n"
        "Host: neverssl.com\r\n"
        "Connection: close\r\n"
        "\r\n";

    send(sock, msg, strlen(msg), 0);

    printf("Verzonden:\n%s\n", msg);

    // Response ontvangen
    recvSize = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (recvSize > 0)
    {
        buffer[recvSize] = '\0';
        printf("Ontvangen van webserver:\n%s\n", buffer);
    }
    else
    {
        printf("Geen data ontvangen.\n");
    }

    closesocket(sock);
    WSACleanup();

    return 0;
}