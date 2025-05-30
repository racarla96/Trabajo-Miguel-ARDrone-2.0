#include "udp_send.h"

#ifndef MATLAB_MEX_FILE
struct udp_struct udp_send_struct;
int udp_init_send = -1;
#endif
        
int16_t udp_send(uint8_t* host, uint16_t port, uint8_t* buf, uint16_t len){
#ifndef MATLAB_MEX_FILE
    if (udp_init_send == -1){
      udp_init_send = 0;
      udp_send_struct.slen=sizeof(udp_send_struct.si_other);

      if ((udp_send_struct.s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1) return -1;

      memset((char *) &udp_send_struct.si_other, 0, sizeof(udp_send_struct.si_other));
      udp_send_struct.si_other.sin_family = AF_INET;
      udp_send_struct.si_other.sin_port = htons(port);
      if (inet_aton(host, &udp_send_struct.si_other.sin_addr)==0) return -2;
      udp_init_send = 1;
    }
  if (udp_init_send != 1) return -10;
  if (sendto(udp_send_struct.s, buf, len, 0, (const sockaddr*)&udp_send_struct.si_other, udp_send_struct.slen)==-1) return -1;
#endif
  return 0;
}

void udp_send_close(){
#ifndef MATLAB_MEX_FILE
  close(udp_send_struct.s);
#endif
}

