
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "blindtest.h"

/* -------------------------------------------------- */
/* PROGRAMME PRINCIPAL                                */
/* -------------------------------------------------- */

int main() {

    srand(time(NULL));
    printf("--- Bienvenu dans......... Le Blind Test !!!!!!!!!!!          tadaaaaaaaaaaaaaaam---\n\n");

    // Charger les chansons
    Song song[150];
    int count = load_songs("songs.txt", song, 150);
    if (count <= 0) {
        printf("Aucune chanson chargee.\n");
        return 1;
    }
    // Melanger les chansons
    melanger(song, count);
    
    //joueur choisi un pseudo
    Joueur joueur;
    gestion_du_joueur(&joueur);

    //play un extrait

    for (int i = 0; i < count; i++) {
    printf("\nExtrait %d/%d : %s\n", i + 1, count, song[i].title);
    play_song_excerpt_at(song[i].file, 0, 10);  
    } 



    return 0;
}