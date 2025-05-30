#ifndef _UDP_RECV_H
#define _UDP_RECV_H

#include <stdint.h>

#ifndef MATLAB_MEX_FILE

#include "udp.h"

#endif

int udp_recv(int port, float blocking_time, uint8_t* buf);
void udp_recv_close();

#endif