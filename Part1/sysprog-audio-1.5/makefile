OPT=-g -Wall -I./include
OBJ= obj/lecteur.o obj/audio.o

lecteur: $(OBJ)
	$(CC) -o $@ $^

obj/lecteur.o: src/lecteur.c
	$(CC) -o $@ -c $< $(OPT)

obj/audio.o: src/audio.c include/audio.h
	$(CC) -o $@ -c $< $(OPT)
clean:
	rm -rf obj/*.o
	rm ./lecteur
