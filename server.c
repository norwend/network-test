#include "ndr_net.h"

#ifdef __linux__
const int NDR_PROTOCOL = AF_INET;
#elif __APPLE__
const int NDR_PROTOCOL = PF_INET;
#endif

int main(void) {
    int server = ndrSocket(NDR_PROTOCOL, SOCK_STREAM, 0);
    struct sockaddr_in addr = {0};
    addr.sin_family = NDR_PROTOCOL;
    addr.sin_port = htons(228);
    ndrBind(server, (const struct sockaddr*)&addr,
                              sizeof addr);
    ndrListen(server, 5);
    socklen_t addrlen = sizeof addr;
    int fd = ndrAccept(server, (struct sockaddr*)&addr, &addrlen);
    

    
    ssize_t nread;
    char buf[1024];
    while (1) {
        nread = read(fd, buf, 1024);
        if (nread == -1) {
            perror("Reading failure");
            exit(EXIT_FAILURE);
        } else if (nread == 0) {
            printf("EOF");
            return 0;
        }
        write(STDOUT_FILENO, buf, nread);
        write(fd, buf, nread);
    }
    close(fd);
    close(server);
    return 0;
}
