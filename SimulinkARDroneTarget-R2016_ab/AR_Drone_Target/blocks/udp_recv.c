
#include "udp_recv.h"

#ifndef MATLAB_MEX_FILE

#include <sys/time.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "udp.h"

#define MAX_SIZE 32

int udp_init_recv = -1;
char buffer[MAX_SIZE];
struct udp_struct udp_recv_struct;

#endif

int udp_recv(int port, float blocking_time, uint8_t* buf){
#ifndef MATLAB_MEX_FILE
    
    if (udp_init_recv == -1){
        udp_init_recv = 0;
        
        udp_recv_struct.slen = sizeof(udp_recv_struct.si_other);

        if ((udp_recv_struct.s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1) return -1;
        
        struct timeval read_timeout;
        read_timeout.tv_sec = 0;
        read_timeout.tv_usec = blocking_time;
        if (setsockopt(udp_recv_struct.s, SOL_SOCKET, SO_RCVTIMEO, &read_timeout, sizeof read_timeout)==-1) return -2;
        
        //Bind the socket
        memset((char *) &udp_recv_struct.si_me, 0, sizeof(udp_recv_struct.si_me));
        udp_recv_struct.si_me.sin_family = AF_INET;
        udp_recv_struct.si_me.sin_port = htons(port);
        udp_recv_struct.si_me.sin_addr.s_addr = htonl(INADDR_ANY);
        if (bind(udp_recv_struct.s, (struct sockaddr*)&udp_recv_struct.si_me, sizeof(udp_recv_struct.si_me))==-1) return -2;
        
        udp_init_recv = 1;
        return udp_init_recv;
    }
    if (udp_init_recv != 1) return -4;
    
    //for(int i=0; i<MAX_SIZE; i++) buf[i] = 0;
    
    int n = recvfrom(udp_recv_struct.s, buf, MAX_SIZE, MSG_WAITALL, (struct sockaddr*)&udp_recv_struct.si_other, &udp_recv_struct.slen);
    
    return n;
    
#endif
    
    return 0;
}

void udp_recv_close(){
#ifndef MATLAB_MEX_FILE
    close(udp_recv_struct.s);
#endif
}