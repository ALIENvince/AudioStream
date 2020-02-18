#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include "../include/audio.h"

int main(int argc, char * argv []) {

    char * track = argv[1]; 

    int s_rate;	
    int s_size;
    int channel;
    int data_size;

    /* Création du descripteur de fichier de lecture*/
    int file_fd = aud_readinit(track,&s_rate,&s_size,&channel,&data_size);

    printf("%d", data_size);

    if(file_fd == -1 ) {
	fprintf(stderr,"Can't open the file");
	exit(1);
    }

    /* Modification des valeurs pour les filtres */
    //s_rate = s_rate*2;
    //s_rate = s_rate/2;
    //
    //channel = 1;
    //
    //s_size = 8;
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
    int count = 0;
    //threshold pour avoir 50 barres a la fin de la piste
    int threshold = data_size / 200 / s_size / 8;
    char playbar[256] = "";

    do
    {
	read_value = read(file_fd, buffer,s_size);
	write(device_fd, buffer, s_size);


	if(count >= threshold) {
	    //strcat(playbar, "|");
	    //printf("%c[2K\r", 27);
	    //printf("%s", playbar);
	    count = 0;
	}
	else count++;
    }
    while( read_value != 0 );

    close(file_fd);
    close(device_fd);

    return 0;

}
