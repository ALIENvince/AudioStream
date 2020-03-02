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
	addr.sin_addr.s_addr = htons1(INADDR_ANY);

	if( bind(mysocket,(struct sockaddr *) &addr, sizeof(struct sockaddre_in)) < 0 ) {
		perrot("Erreur pour donner un numéro de port a notre socket");
		exit(1);
	}

	while(1) {
		
	}


}
