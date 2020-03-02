#include <stiod.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 1234

int main(int argc, char * argv []) {
	int fd;
	int err;

	socklen_t rclen, flen;
	struct sockaddr_in addr;
	
	fd = socket(AF_INET,SOCK_DGRAM,0;
	if(fd < 0) {
		perror("Socket Creation Error");
		exit(1);
	}

	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);

	err = bind(fd,(struct sockaddr *) &addr, sizeof(struct sockaddr_in));
	if(err < 0) {
		perrot("Binding Error");
		exit(2);
	}

	char msg[128];
	char resp[128] = "Message recieved";
	
	while(1) {
		len = recvfrom(fd, msg, sizeof(msg), 0, (struct sockaddr*) &addr, flen);
		if(len < 0 ) { 
			perror("recv Error");
			exit(3);
		}
		printf("%d Recieved from %s:%d: %s", len, addrinet_ntoa(addr.sin_addr), ntohs(from.sin_port), msg));

		err = sendto(fd, resp, strlen(resp)+1, 0, (struct sockaddr*) &addr, sizeof(struct sockaddr_in));

		if(err < 0) {
			perror("send Error");
			exit(4);
		}
	}


}
