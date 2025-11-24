#include <stdio.h>

// Étape 1 : afficherMenu
void afficherMenu() {
    printf("===== Gestion des notes =====\n");
    printf("1. Saisir les notes des élèves\n");
    printf("2. Afficher les notes des élèves\n");
    printf("3. Calculer la moyenne d'un élève\n");
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

int main() {
    afficherMenu();
    int choix = lireChoix();
    printf("Vous avez choisi : %d\n", choix); 
    return 0;
}
