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

// Etape 4 : calcul_distribution (billets 500, 200, 100, 50, 20, 10, 5)
void calcul_distribution(int montant) {
    int b500 = montant / 500;
    montant %= 500;

    int b200 = montant / 200;
    montant %= 200;

    int b100 = montant / 100;
    montant %= 100;

    int b50 = montant / 50;
    montant %= 50;

    int b20 = montant / 20;
    montant %= 20;

    int b10 = montant / 10;
    montant %= 10;

    int b5 = montant / 5;
    montant %= 5;

    printf("\nDistribution des billets :\n");
    printf("500euros : %d\n", b500);
    printf("200euros : %d\n", b200);
    printf("100euros : %d\n", b100);
    printf("50euros  : %d\n", b50);
    printf("20euros : %d\n", b20);
    printf("10euros : %d\n", b10);
    printf("5euros  : %d\n", b5);
}

int main() {
    int choix = 0;

    while (choix != 2) {
        afficher_menu();
        scanf("%d", &choix);

        if (choix == 1) {
            int montant = saisir_montant();

            if (montant_valide(montant)) {
                calcul_distribution(montant);
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
