OPT=-g -Wall -I./include
OBJ= obj/lecteur.o obj/audio.o obj/client.o obj/server.o

lecteur: $(OBJ)
	$(CC) -o $@ $^

obj/lecteur.o: src/lecteur.c
	$(CC) -o $@ -c $< $(OPT)

obj/audio.o: src/audio.c include/audio.h
	$(CC) -o $@ -c $< $(OPT)

obj/client.o: src/audioclient.c include/audioclient.h include/audio.h
	$(CC) -o $@ -c $< $(OPT)

obj/server.o: src/audioserver.c include/audioserver.h include/audio.h
	$(CC) -o $@ -c $< $(OPT)

clean:
	rm -rf obj/*.o
	rm ./lecteur
