#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "socket_connect.h"

#define PORT 5600
#define SERVER_ADDRESS "127.0.0.1"

int socket_connect(const uint8_t* data, size_t data_length) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket failed");
        close(sock);
        return EXIT_FAILURE;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    if (inet_pton(AF_INET, SERVER_ADDRESS, &(server.sin_addr)) <= 0) {
        perror("inet_pton failed");
        close(sock);
        return EXIT_FAILURE;
    }

    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("connect failed");
        close(sock);
        return EXIT_FAILURE;
    }

    if (send(sock, data, data_length, 0) < 0) {
        perror("send failed");
        close(sock);
        return EXIT_FAILURE;
    }

    close(sock);
    return 0;
}