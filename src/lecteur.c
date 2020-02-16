#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include "../include/audio.h"

int main(int argc, char * argv []) {
	
	char * track = argv[1]; 

	int s_rate;	
	int s_size;
	int channel;
	
	/* Création du descripteur de fichier de lecture*/
	int read_fd = aud_readinit(track,&s_rate,&s_size,&channel);

	if(read_fd == -1 ) {
		fprintf(stderr,"Can't open the file");
		exit(1);
	}
	
	/* Modification des valeurs pour les filtres */

	/*-------------------------------------------*/
	

	/* Création du descripteur de fichier d'ouverture*/
	int write_fd = aud_writeinit(s_rate,s_size,channel);

	if(write_fd == -1) {
		fprintf(stderr,"Can't write");
		exit(1);
	}
	
	/* Boucle de lecture et ecriture*/
	int read_value;
	int write_value;

	char buffer[s_size];

	while( (read_value == s_size) && (write_value == s_size) ) {
		read_value = read(read_fd, buffer,s_size);
		write_value = write(read_fd,buffer,s_size);		
	}

	close(read_fd);
	close(write_fd);
	return 0;



}
