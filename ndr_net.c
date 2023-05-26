#include "ndr_net.h"

int ndrSocket(int domain, int type, int protocol) {
    int res = socket(domain, type, protocol);
    if (res == -1) {
        perror("Socket creation failure");
        exit(EXIT_FAILURE);
    }
    return res;
}

int ndrBind(int socket, const struct sockaddr* address,
            socklen_t address_len) {
    int res = bind(socket, address, address_len);
    if (res != 0) { // instead of -1 I use != 0
        perror("Binding failure");
        exit(EXIT_FAILURE);
    }
    return res;
}

int ndrListen(int socket, int backlog) {
    int res = listen(socket, backlog);
    if (res == -1) {
        perror("Listen failure");
        exit(EXIT_FAILURE);
    }
    return res;
}

int ndrAccept(int sockfd, struct sockaddr* addr, socklen_t* addrlen) {
    int res = accept(sockfd, addr, addrlen);
    if (res == -1) {
        perror("Accept failure");
        exit(EXIT_FAILURE);
    }
    return res;    
}

int ndrConnect(int sockfd, const struct sockaddr* addr,
               socklen_t addrlen) {
    int res = connect(sockfd, addr, addrlen);
    if (res == -1) {
        perror("Connect failure");
        exit(EXIT_FAILURE);
    }
    return res;
}

int ndrInetPton(int af, const char* src, void* dst) {
    int res = inet_pton(af, src, dst);
    if (res == 0) {
        perror("Inet_pton failed: the specified string"
               " is not a network address");
        exit(EXIT_FAILURE);
    } else if (res == -1) {
        perror("Inet_pton failed");
        exit(EXIT_FAILURE);
    }
    return res;    
}
