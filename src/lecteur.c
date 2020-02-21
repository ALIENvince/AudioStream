#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include "../include/audio.h"

int print_playbar(int* sample_count, int s_rate, int s_size, int data_len);

/**
 * Requires char buffer of size 60 minimum
 * prints the playbar status of the track
 * including :
 * current timer
 * end time
 * progress bar
 */
int print_playbar(int* sample_count, int s_rate, int s_size, int samplecount) {
    int sec = 0;
    int min = 0;
    //int progress = 0;

sec = ((s_size/4) * (*sample_count) / s_rate) % 60;
min = ((s_size/4) * (*sample_count) / s_rate) / 60;

int max_sec =  (samplecount/4 / s_rate) % 60;
int max_min =  (samplecount/4 / s_rate) / 60;

//progress = (50 * *sample_count) / max_sample;
char progress_buffer[50];


printf("%c[2K\r %02d:%02d[%s]%02d:%02d", 27, min, sec, progress_buffer, max_min , max_sec);
fflush(stdout);

return 0;
}

int main(int argc, char * argv []) {

    char * track = argv[1]; 

    int s_rate;	
    int s_size;
    int channel;
    int samplecount;

    /* Création du file descriptor de notre fichier audio*/
    int file_fd = aud_readinit(track,&s_rate,&s_size,&channel,&samplecount);

    printf("%d", samplecount);

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


    /* Création du file descriptor du lecteur audio*/
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
    int sample = 0;

    do
    {
	read_value = read(file_fd, buffer,s_size);
	write(device_fd, buffer, s_size);
	sample++;

	if(count >= s_rate / 4 ) {
	    print_playbar(&sample, s_rate, s_size, samplecount);
	    count = 0;
	}
	else count++;
    }
    while( read_value != 0 );

    close(file_fd);
    close(device_fd);

    return 0;

}
