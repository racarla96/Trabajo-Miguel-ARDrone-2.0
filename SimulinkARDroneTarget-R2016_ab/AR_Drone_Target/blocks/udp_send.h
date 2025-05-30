#ifndef _UDP_SEND_H
#define _UDP_SEND_H

#include <stdint.h>

#ifndef MATLAB_MEX_FILE

#include "udp.h"

//struct udp_struct udp_send_struct;

#endif

int16_t udp_send(uint8_t* host, uint16_t port, uint8_t* buf, uint16_t len);
void udp_send_close();

#endif