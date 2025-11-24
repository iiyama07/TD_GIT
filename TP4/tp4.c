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
    printf("5. Afficher la note maximale d'un controle\n");
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
void saisirNotes(int nbEleves, int notes[30][3]) {
    for (int i = 0; i < nbEleves; i++) {
        printf("Eleve %d :\n", i + 1);
        for (int j = 0; j < 3; j++) {
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

// Étape 5 : afficherNotes
void afficherNotes(int nbEleves, int notes[30][3]) {
    printf("\nEleve  C1  C2  C3\n");
    for (int i = 0; i < nbEleves; i++) {
        printf("%5d", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("%5d", notes[i][j]);
        }
        printf("\n");
    }
}

// Étape 6 : calculerMoyenneEleve
float calculerMoyenneEleve(int notes[30][3], int indiceEleve) {
    int somme = 0;
    for (int j = 0; j < 3; j++) {
        somme += notes[indiceEleve][j];
    }
    return somme / 3.0f;
}

// Étape 7 : calculerMoyenneGenerale
float calculerMoyenneGenerale(int nbEleves, int notes[30][3]) {
    float somme = 0.0f;

    for (int i = 0; i < nbEleves; i++) {
        somme += calculerMoyenneEleve(notes, i);
    }

    return somme / nbEleves;
}

// Étape 8 : trouverMeilleureNoteControle
int trouverMeilleureNoteControle(int nbEleves, int notes[30][3], int indiceControle) {
    int max = 0;

    for (int i = 0; i < nbEleves; i++) {
        if (notes[i][indiceControle] > max) {
            max = notes[i][indiceControle];
        }
    }

    return max;
}

int main() {
    int nbEleves = 0;
    int notes[30][3];

    int quitter = 0;
    while (!quitter) {
        afficherMenu();
        int choix = lireChoix();

        switch (choix) {
            case 1: 
                nbEleves = saisirNombreEleves();
                saisirNotes(nbEleves, notes);
                break;

            case 2:
                if (nbEleves > 0)
                    afficherNotes(nbEleves, notes);
                else
                    printf("Aucune note saisie pour le moment.\n");
                break;

            case 3:
                if (nbEleves > 0) {
                    int eleveChoisi = -1;
                    while (eleveChoisi < 1 || eleveChoisi > nbEleves) {
                        printf("Saisir le numero de l'eleve (1-%d) : ", nbEleves);
                        scanf("%d", &eleveChoisi);
                        if (eleveChoisi < 1 || eleveChoisi > nbEleves) {
                            printf("Numero invalide.\n");
                        }
                    }
                    float moyenne = calculerMoyenneEleve(notes, eleveChoisi - 1);
                    printf("Moyenne de l'eleve %d : %.2f\n", eleveChoisi, moyenne);
                } else {
                    printf("Aucune note saisie pour le moment.\n");
                }
                break;

            case 4:
                if (nbEleves > 0) {
                    float moyenneClasse = calculerMoyenneGenerale(nbEleves, notes);
                    printf("Moyenne generale de la classe : %.2f\n", moyenneClasse);
                } else {
                    printf("Aucune note saisie pour le moment.\n");
                }
                break;

            case 5:
                if (nbEleves > 0) {
                    int controle = -1;
                    while (controle < 1 || controle > 3) {
                        printf("Choisir le controle (1 = C1, 2 = C2, 3 = C3) : ");
                        scanf("%d", &controle);
                        if (controle < 1 || controle > 3) {
                            printf("Indice invalide.\n");
                        }
                    }

                    int meilleure = trouverMeilleureNoteControle(nbEleves, notes, controle - 1);
                    printf("Meilleure note du controle C%d : %d\n", controle, meilleure);
                } else {
                    printf("Aucune note saisie pour le moment.\n");
                }
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
