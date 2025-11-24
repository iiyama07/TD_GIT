#include <stdio.h>

int MAX_ELEVES = 30;
int NB_NOTES = 3;

// Étape 1 : afficherMenu
void afficherMenu() {
    printf("===== Gestion des notes =====\n");
    printf("1. Saisir les notes des eleves\n");
    printf("2. Afficher les notes des eleves\n");
    printf("3. Calculer la moyenne d'un eleve\n");
    printf("4. Calculer la moyenne de la classe\n");
    printf("5. Afficher la note maximale\n");
    printf("6. Quitter\n");
}

// Étape 2 : lireChoix
int lireChoix() {
    int choix;
    printf("Votre choix : ");
    scanf("%d", &choix);
    return choix;
}

// Étape 3 : saisirNombreEleves 
int saisirNombreEleves() {
    int nb = 0; 
    while (nb < 1 || nb > 30) {
        printf("Nombre d'eleves (1-30) : ");
        scanf("%d", &nb);
        if (nb < 1 || nb > 30) {
            printf("Erreur : le nombre doit etre entre 1 et 30.\n");
        }
    }
    return nb;
}

// Étape 4 : saisirNotes
void saisirNotes(int nbEleves, int notes[MAX_ELEVES][NB_NOTES]) {
    for (int i = 0; i < nbEleves; i++) {
        printf("Eleve %d :\n", i + 1);
        for (int j = 0; j < NB_NOTES; j++) {
            int note = -1;
            while (note < 0 || note > 20) {
                printf("  Note %d (0-20) : ", j + 1);
                scanf("%d", &note);
                if (note < 0 || note > 20) {
                    printf("  Erreur : la note doit etre entre 0 et 20.\n");
                }
            }
            notes[i][j] = note;
        }
    }
}

int main() {
    int nbEleves = 0;
    int notes[MAX_ELEVES][NB_NOTES];

    int quitter = 0;
    while (!quitter) {
        afficherMenu();
        int choix = lireChoix();

        switch (choix) {
            case 1: 
                nbEleves = saisirNombreEleves();
                saisirNotes(nbEleves, notes);
                break;
            case 6:
                quitter = 1;
                break;
            default:
                printf("Option non reconnue.\n");
        }
    }

    printf("Programme termine.\n");
    return 0;
}
