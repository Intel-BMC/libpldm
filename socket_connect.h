#ifndef SOCKET_CONNECT_H
#define SOCKET_CONNECT_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>



// Send a PLDM message over the socket
int socket_send_pldm_message(const uint8_t* data, size_t data_length);



#ifdef __cplusplus
}
#endif

#endif  // SOCKET_CONNECT_H