#include <stdio.h>
#include "fichier.h"

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