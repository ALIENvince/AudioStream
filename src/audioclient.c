#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 1234



int main(int argc, char * argv [] ) {
	int sock;
	struct sockaddr_in dest;
	char buf[BUFSIZE];

	if(sock=socket(AF_INET,SOCK_DGRAM,0) < 0 ) {
		perror("Creation Socket Error");
	}

	dest.sin_family = AF_INET;
	dest.sin_post = htons(PORT);
	dest.sin_addr = inet_addr("127.0.0.1");

	while(1) {


		//sendto
		int err = sendto(sock,buf,strlen(buf)+1,0,(struct sockaddr*) &dest, sizeof(struct
					sockadrr_in));
		if(err<0) {
			perror("Sending Datagramme Error");
			exit(1);
		}
		printf("%d",err);
		//recvfrom
		int len = recvfrom(sock,buf,strlen(buf)+1,0,
				//close
				}



}
