#ifndef __UDP_H
#define __UDP_H

#ifndef MATLAB_MEX_FILE

#include<stdio.h>	//printf
#include<string.h> //memset
#include<stdlib.h> //exit(0);
#include<arpa/inet.h>
#include<sys/socket.h>

#define BUFLEN 512	//Max length of buffer
#define PORT 8888	//The port on which to listen for incoming data

struct udp_struct
{
  int16_t s;
  struct sockaddr_in si_me;
  struct sockaddr_in si_other;
  socklen_t slen;
};

#endif

#endif