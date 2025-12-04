#include <stdio.h>
#include "fichier.h"
#include <windows.h>
#include <locale.h>

void afficherMenu() {
    printf("=============================\n");
    printf("  Suivi de consomation       \n");
    printf("=============================\n");
    printf("1. Ajouter une consomation\n");
    printf("2. Afficher le resume du jour\n");
    printf("3. Afficher le score de santé\n");
    printf("4. Sauvegarder et quitter\n");}

int lireChoix() {
    int choix;
    printf("Votre choix : ");
    scanf("%d", &choix);
    return choix;
}

void initialiser(int consommations[]) {
    for (int i = 0; i < 7; i++) {
        consommations[i] = 0;
    }
} 

void ajouterConsommation(int consommation[])
{
    int choix = 0 ;
    int unite = 0;
    printf("Quelle categoirie voulez vous modifier\n");
    printf("\n");
    printf("1.Eau 💧\n");
    printf("2.Cafe ☕\n");
    printf("3.Bonbons 🍬\n");
    printf("4.Gateau 🍰\n");
    printf("5.Legume 🥦\n");
    printf("6.Fruit 🍎\n");
    printf("7.Proteines 🍗\n");
    printf("Votre choix : ");
    scanf("%d", &choix);

    if (choix >= 1 && choix <= 7) {
        printf("Combien d'unitées ajouter ? : ");
        scanf("%d", &unite);
        consommation[choix - 1] += unite;
        printf("Consommation mise à jour.\n\n");
    } else {
        printf("Choix invalide.\n\n");
    }

}

void afficherResume(int consommation[]) {
    
   printf("\n--- Résumé du jour ---\n");

    const char* emojisBonbons[] = {"😇", "🙂", "😕", "😈"};
    const char* emojisLegumes[] = {"😭", "🙂", "😎"};
    const char* emojisFruits[] = {"😥", "🙂", "😄"};

    int scoreBonbons = humeurBonbons(consommation[2]);
    int scoreLegumes = humeurLegumes(consommation[4]);
    int scoreFruits = humeurFruits(consommation[5]);

int maximum[] = {8, 4, 10, 3, 5, 5, 4};

    printf("Eau       : %d 💧", consommation[0]);
    afficherBarre(consommation[0], maximum[0]);
    printf("\n");

    printf("Café      : %d ☕", consommation[1]);
    afficherBarre(consommation[1], maximum[1]);
    printf("\n");

    printf("Bonbons   : %d 🍬 %s", consommation[2], emojisBonbons[scoreBonbons]);
    afficherBarre(consommation[2], maximum[2]);
    printf("\n");

    printf("Gâteau    : %d 🍰", consommation[3]);
    afficherBarre(consommation[3], maximum[3]);
    printf("\n");

    printf("Légumes   : %d 🥦 %s", consommation[4], emojisLegumes[scoreLegumes]);
    afficherBarre(consommation[4], maximum[4]);
    printf("\n");

    printf("Fruits    : %d 🍎 %s", consommation[5], emojisFruits[scoreFruits]);
    afficherBarre(consommation[5], maximum[5]);
    printf("\n");

    printf("Protéïnes : %d 🍗", consommation[6]);
    afficherBarre(consommation[6], maximum[6]);
    printf("\n");

    printf("\n");
    Sleep(3000);
}


int charger(int consommation[]) {
    FILE * fichier = fopen("consommation.txt", "r");

    if (fichier == NULL) {
        return 0;
    }

    for (int i = 0; i < 7; i++) {
        if (fscanf(fichier, "%d", &consommation[i]) != 1) {
            fclose(fichier);
            return 0;
        }
    }

    fclose(fichier);
    return 1;
}

int sauvegarder(int consommation[]) {
    FILE * fichier = fopen("consommation.txt", "w");

    if (fichier == NULL) {
        return 0;
    }

    for (int i = 0; i < 7; i++) {
        fprintf(fichier, "%d ", consommation[i]);
    }
    fprintf(fichier, "\n");

    fclose(fichier);
    return 1;
}
int humeurBonbons(int nbBonbons) {
    if (nbBonbons <= 3) return 0;
    if (nbBonbons <= 7) return 1;
    if (nbBonbons <= 12) return 2;
    return 3;
}

int humeurLegumes(int nbLegumes) {
    if (nbLegumes == 0) return 0;
    if (nbLegumes <= 2) return 1;
    return 2;
}

int humeurFruits(int nbFruits) {
    if (nbFruits == 0) return 0;
    if (nbFruits <= 2) return 1;
    return 2;
}

void afficherBarre(int valeur, int max) {
    if (max <= 0) {
        max = 1;
    }

    if (valeur > max) {
        valeur = max;
    }
    if (valeur < 0) {
        valeur = 0;
    }

    int casesPleines = (valeur * 10) / max;

    printf(" [");
    for (int i = 0; i < 10; i++) {
        if (i < casesPleines) {
            printf("█");
        } else {
            printf("░");
        }
    }
    printf("]");
}

void afficherScoreEtObjectifs(int consommations[], int objectifs[]) {
    printf("\n--- Objectifs du jour ---\n\n");

    const char* categories[] = {
        "Eau", "Café", "Bonbons", "Gâteau", "Légumes", "Fruits", "Protéïnes"
    };

    int score = 0;
    
    printf("%-12s | %-12s | %s\n", "Catégorie", "Progrès", "Atteint ?");
    printf("----------------------------------------\n");

    for (int i = 0; i < 7; i++) {
        if (objectifs[i] > 0) {
            char progres[15];
            sprintf(progres, "%d / %d", consommations[i], objectifs[i]);
            printf("%-12s | %-12s | %s\n", categories[i], progres, (consommations[i] >= objectifs[i]) ? "✅" : "❌");
            if (consommations[i] >= objectifs[i]) {
                score += 25;
            }
        } else {
            printf("%-12s | %-12s | %s\n", categories[i], "Pas d'objectif", " ");
        }
    }

    score = calculerScoreSante(consommations, objectifs);

    printf("\nVotre score de santé pour aujourd'hui est de : %d / 100\n\n", score);
    Sleep(4000);
}

int calculerScoreSante(int consommations[], int objectifs[]) {
    int score = 50;

    if (consommations[0] >= objectifs[0]) score += 10;
    if (consommations[4] >= objectifs[4]) score += 10;
    if (consommations[5] >= objectifs[5]) score += 10;
    if (consommations[6] >= objectifs[6]) score += 10;

    if (consommations[2] > 5) {
        int malusBonbons = (consommations[2] - 5);
        if (malusBonbons > 15) {
            malusBonbons = 15;
        }
        score -= malusBonbons;
    }

    if (consommations[1] > 3) {
        int malusCafe = (consommations[1] - 3) * 2;
        if (malusCafe > 20) {
            malusCafe = 20;
        }
        score -= malusCafe;
    }

    if (score < 0) {
        score = 0;
    }
    if (score > 100) {
        score = 100;
    }
    
    return score;
}