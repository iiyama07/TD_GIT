#include <stdio.h>

    int main()
    {
        int montantpret = 0;
        int taux = 0;
        int duree = 0;
        printf("Entrez le montant du pret : ");
        scanf("%d", &montantpret);
        printf("Entrez le taux d'interet (en pourcentage) : ");
        scanf("%d", &taux);
        printf("Entrez la duree du pret (en annees) : ");
        scanf("%d", &duree);
        int mensualite = (montantpret * (taux/12))/ (1-(1 + taux/12)^(-duree*12));
        printf("La mensualite est de %d euros.\n", mensualite);
        return 0;
    }

/*Saluuut c'est adaaaam*/