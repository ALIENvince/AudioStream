#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include "../include/audio.h"

int main(int argc, char * argv []) {
	
	char * track = argv[0]; 

	int * s_rate = NULL;	
	int * s_size = NULL;
	int * channel = NULL;
	
	int fd = aud_readinit(track,s_rate,s_size,channel);

	if(fd == -1 ) {
		fprintf(stderr,"Can't open the file");
		exit(1);
	}

	return 0;



}
