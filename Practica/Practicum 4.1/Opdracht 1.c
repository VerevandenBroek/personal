#define _WINSOCK_DEPRECATED_NO_WARNINGS
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

    clientSock = accept(listenSock, NULL, NULL);
    printf("Client verbonden!\n");

    recvSize = recv(clientSock, buffer, sizeof(buffer) - 1, 0);
    buffer[recvSize] = '\0';
    printf("Ontvangen van client: %s\n", buffer);

    char* msg = "Hallo van de server!\n";
    send(clientSock, msg, strlen(msg), 0);

    closesocket(clientSock);
    closesocket(listenSock);
    WSACleanup();

    return 0;
}
