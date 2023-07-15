#ifndef SOCKET_CONNECT_H
#define SOCKET_CONNECT_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

// Connect to the specified server and send data
int socket_connect(const uint8_t* data, size_t data_length);

#ifdef __cplusplus
}
#endif

#endif  // SOCKET_CONNECT_H