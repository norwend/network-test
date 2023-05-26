#include <string.h>

#include "ndr_net.h"

#ifdef __linux__
const int NDR_PROTOCOL = AF_INET;
#elif __APPLE__
const int NDR_PROTOCOL = PF_INET;
#endif

int main(void) {
    int fd = socket(NDR_PROTOCOL, SOCK_STREAM, 0);

    struct sockaddr_in addr = {0};
    addr.sin_family = NDR_PROTOCOL;
    addr.sin_port = htons(228);
    char ip_address[16];
    printf("Enter the IP address:\n");
    scanf("%s", ip_address);
    ndrInetPton(NDR_PROTOCOL, ip_address, &addr.sin_addr);
    ndrConnect(fd, (struct sockaddr*)&addr, sizeof addr);
    /* char message[256]; */
    /* printf("Enter your message:\n"); */
    /* getline(message, sizeof message, stdin); */
    char* message = NULL;
    size_t message_length = 0;
    ssize_t line_read;

    while ((line_read = getline(&message, &message_length, stdin)) != -1) {
        write(fd, message, strlen(message));
        char answer[256];
        ssize_t nread = read(fd, answer, 256);
        if (nread == -1) {
            perror("Reading failed");
            exit(EXIT_FAILURE);
        }
        if (nread == 0) {
            printf("EOF\n");
        }
        write(STDOUT_FILENO, answer, nread);
        
    }
    close(fd);
    return 0;
}
