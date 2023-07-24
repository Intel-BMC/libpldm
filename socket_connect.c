#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "socket_connect.h"

#define PORT 5600
#define SERVER_ADDRESS "127.0.0.1"

static int sock = -1;

int initialize_socket_connection() {
    if (sock != -1) {
        return 0;  // Already initialized, return success
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket failed");
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

    return 0;
}

int socket_send_pldm_message(const uint8_t* data, size_t data_length) {
    if (sock == -1) {
        if (initialize_socket_connection() != 0) {
            return EXIT_FAILURE;
        }
    }

    if (send(sock, data, data_length, 0) < 0) {
        perror("send failed");
        close(sock);
        sock = -1;  // Set sock to -1 to indicate that the connection is closed
        return EXIT_FAILURE;
    }


    return 0;
}

int close_socket_connection() {
    if (sock != -1) {
        close(sock);
        sock = -1;  // Set sock to -1 to indicate that the connection is closed
        return 0;
    }
    
    return EXIT_FAILURE;
}