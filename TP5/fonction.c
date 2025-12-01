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
    
    printf("\n--- Résumeé du jour ---\n");

    printf("Eau       : %d unités\n", consommation[0]);
    printf("Café      : %d unités\n", consommation[1]);
    printf("Bonbons   : %d unités\n", consommation[2]);
    printf("Gâteau    : %d unités\n", consommation[3]);
    printf("Légumes   : %d unités\n", consommation[4]);
    printf("Fruits    : %d unités\n", consommation[5]);
    printf("Protéïnes : %d unités\n", consommation[6]);
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
