OPT = -g -Wall -I./include

bin/lecteur: obj/lecteur.o obj/audio.o
	$(CC) -o $@ $^
obj/audio.o: include/audio.h
	$(CC) -o $@ -c $^ $(OPT)
