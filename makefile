OPT=-g -Wall -I./include
OBJ= obj/lecteur.o obj/audio.o obj/client.o obj/server.o

ALL:lecteur audioclient audioserver

lecteur: obj/lecteur.o obj/audio.o
	$(CC) -o $@ $^

obj/lecteur.o: src/lecteur.c
	$(CC) -o $@ -c $< $(OPT)

obj/audio.o: src/audio.c include/audio.h
	$(CC) -o $@ -c $< $(OPT)


audioclient: obj/client.o
	$(CC) -o $@ $^

obj/client.o: src/audioclient.c include/audioclient.h include/audio.h
	$(CC) -o $@ -c $< $(OPT)

audioserver: obj/server.o
	$(CC) -o $@ $^

obj/server.o: src/audioserver.c include/audioserver.h include/audio.h
	$(CC) -o $@ -c $< $(OPT)

clean:
	rm -rf obj/*.o
	rm ./lecteur
