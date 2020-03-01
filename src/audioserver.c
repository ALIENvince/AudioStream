#include <stiod.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 1234

int main(int argc, char * argv []) {
	int mysocket;
	struct sockaddr_in addr;

	if( (mysockey = socket(AF_INET,SOCK_DGRAM,0)) < 0 ) {
		perror("Erreur de creation de socket");
		exit(1);
	}

	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = 
}
