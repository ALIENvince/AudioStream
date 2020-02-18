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
    int file_fd = aud_readinit(track,&s_rate,&s_size,&channel);

    if(file_fd == -1 ) {
	fprintf(stderr,"Can't open the file");
	exit(1);
    }

    /* Modification des valeurs pour les filtres */

    /*-------------------------------------------*/


    /* Création du descripteur de fichier d'ouverture*/
    int device_fd = aud_writeinit(s_rate,s_size,channel);

    if(device_fd == -1) {
	fprintf(stderr,"Can't write");
	exit(1);
    }

    /* Boucle de lecture et ecriture*/
    ssize_t read_value;
    //ssize_t write_value;

    char buffer[s_size];

    do
    {
	read_value = read(file_fd, buffer,s_size);
	write(device_fd, buffer, s_size);
    }
    while( read_value != 0 );

	close(file_fd);
	close(device_fd);
    return 0;

}
