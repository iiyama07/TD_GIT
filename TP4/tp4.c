#include <stdio.h>

// Étape 1 : fonction afficherMenu
void afficherMenu() {
    printf("===== Gestion des notes =====\n");
    printf("1. Saisir les notes des eleves\n");
    printf("2. Afficher les notes des eleves\n");
    printf("3. Calculer la moyenne d'un eleve\n");
    printf("4. Calculer la moyenne de la classe\n");
    printf("5. Afficher la note maximale\n");
    printf("6. Quitter\n");
}

int main() {
    // affichage menu
    afficherMenu();
    return 0;
}