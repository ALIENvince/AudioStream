#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 1234

int main(int argc, char * argv [] ) {
    int fd;
    int err;

    socklen_t rclen, flen;
    struct sockaddr_in addr;

    fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(fd < 0) {
	perror("Socket Creation Error");
	exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    const char* dotted = "127.0.0.1";
    addr.sin_addr.s_addr = inet_addr(*dotted);

    char msg[128] = "Hello !";
    char resp[128];

    err = sendto(fd, msg, strlen(msg)+1, 0, (struct sockaddr*) &addr, sizeof(struct sockaddr_in));

    if(err < 0 ) {
	perror("send Error");
	exit(4);
    }

    flen = sizeof(struct sockaddr_in);
    rclen = recvfrom(fd, msg, sizeof(msg), 0, (struct sockaddr*) &addr, &flen);

    if(rclen < 0) {
	perror("recv Error");
	exit(3);
    }
    printf("%d Recieved from %s:%d: %s", rclen, inet_ntoa(addr.sin_addr), ntohs(addr.sin_port), msg);

    close(fd);

}
