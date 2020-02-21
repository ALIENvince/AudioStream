# AudioStream
Audio Streaming project for UE System, univ-rennes1
Authors : JULLION Francois & FAYE Vincent

Question 1: Que se passe-t-il si on declare une fausse frequence ?
Le morceau va etre accelere ou ralenti en fonction de la frequence
d'echantillonage. Si le sample rate est double a 88.2kHz alors que le fichier
est en 44.1kHz le device audio va lire le fichier audio 2 fois plus vite qu'il
le devrait et on entendra une musique acceleree. C'est l'inverse si on divise
la frequence d'echantillonage par 2, la musique va etre ralenti.

Question 2: Que se passe-t-il si on declare a la sortie audio que le fichier
est mono ?
Le son est joue 2 fois plus lentement et est dephase.

Question 3: Le son est sature et inaudible. On lit des samples de 8 bits
encodes sur 16 bits le lecteur lis des valeurs qui ne representent pas le son
attendu.


IMPORTANT

Le fichier audio.c a ete modifie : ajout de data_len pour recuperer la taille
du fichier audio
Nous avons essayés d'implementer une bar de chargement lors de la lecture du son (Avec durée du son etc...)
C'est encore en progres, elle ne marche pas parfaitement
