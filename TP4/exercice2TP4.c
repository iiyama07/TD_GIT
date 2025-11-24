#include <stdio.h>
// Etape 1 : afficher_menu
void afficher_menu() {
    printf("===== DISTRIBUTEUR AUTOMATIQUE =====\n");
    printf("1. Retirer un montant\n");
    printf("2. Quitter\n");
    printf("Votre choix : ");
}
// Etape 2 : saisir_montant
int saisir_montant() {
    int montant;
    printf("Entrez le montant a retirer : ");
    scanf("%d", &montant);
    return montant;
}


int main() {
    int choix = 0;

    while (choix != 2) {
        afficher_menu();
        scanf("%d", &choix);

        if (choix == 1) {
            int montant = saisir_montant();
            printf("Vous avez saisi : %d euros\n", montant);
        }
        else if (choix == 2) {
            printf(">> Au revoir !\n");
        }
        else {
            printf(">> Choix invalide, recommencez.\n");
        }
    }

    return 0;
}
