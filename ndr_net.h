#ifndef NDR_NET_H
#define NDR_NET_H

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int ndrSocket(int, int, int);
int ndrBind(int, const struct sockaddr*, socklen_t);
int ndrListen(int socket, int backlog);
int ndrAccept(int, struct sockaddr*, socklen_t*);
int ndrConnect(int, const struct sockaddr*, socklen_t);
int ndrInetPton(int, const char*, void*);

#endif
