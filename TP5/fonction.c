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
    printf("combien d'unite voulez vous ajoutez?  20\n");
    scanf("%d", &unite);
    printf("consommation mise a jour\n");

}