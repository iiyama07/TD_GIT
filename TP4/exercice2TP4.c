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

// Etape 3 : montant_valide
int montant_valide(int montant) {
    if (montant <= 0 || montant > 1000 || montant % 5 != 0) {
        printf("Erreur : montant invalide\n");
        return 0;
    }
    return 1;
}

int main() {
    int choix = 0;

    while (choix != 2) {
        afficher_menu();
        scanf("%d", &choix);

        if (choix == 1) {
            int montant = saisir_montant();

            if (montant_valide(montant)) {
                printf("Montant valide : %d euros\n", montant);
            } else {
                printf("Veuillez reessayer.\n");
            }
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
