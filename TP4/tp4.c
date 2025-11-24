#include <stdio.h>

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

#include <stdio.h>

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

int main() {
    afficherMenu();
    int choix = lireChoix();
    printf("Vous avez choisi : %d\n", choix); 
    int nbEleves = saisirNombreEleves();
    printf("Nombre d'eleves saisi : %d\n", nbEleves);  
    return 0;
}
