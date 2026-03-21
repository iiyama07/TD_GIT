
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

    // play un extrait et demander le titre
    char reponse[256];
    int score = 0;

    for (int i = 0; i < count; i++) {
        printf("\nExtrait %d/%d\n", i + 1, count);
        play_song_excerpt_at(song[i].file, 0, 10);

        printf("Quel est le titre de la chanson ? ");
        if (fgets(reponse, sizeof(reponse), stdin) == NULL) {
            printf("Erreur lecture reponse.\n");
            continue;
        }
        trim_newline(reponse);

        if (string_equals_normalized(reponse, song[i].title)) {
            printf("Bonne reponse !\n");
            score++;
        } else {
            printf("Mauvaise reponse. Le titre correct etait : %s\n", song[i].title);
        }
    }

    printf("\nJeu Termine. %s, votre score est %d/%d.\n", joueur.nom, score, count);

    return 0;
}