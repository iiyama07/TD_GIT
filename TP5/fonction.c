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
    printf("3 Sauvegarder et quitter\n");
}

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

    printf("Eau       : %d 💧\n", consommation[0]);
    printf("Café      : %d ☕\n", consommation[1]);
    printf("Bonbons   : %d 🍬 %s\n", consommation[2], emojisBonbons[scoreBonbons]);
    printf("Gâteau    : %d 🍰\n", consommation[3]);
    printf("Légumes   : %d 🥦 %s\n", consommation[4], emojisLegumes[scoreLegumes]);
    printf("Fruits    : %d 🍎 %s\n", consommation[5], emojisFruits[scoreFruits]);
    printf("Protéïnes : %d 🍗\n", consommation[6]);
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
