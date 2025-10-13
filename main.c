    #include <stdio.h>

    int main()
    {
        int nbseconde = 0;
        printf("Entrez un nombre de secondes : ");
        scanf("%d", &nbseconde);    
        int heures = nbseconde / 3600;
        int minutes = (nbseconde % 3600) / 60;
        int secondes = nbseconde % 60;
        printf("%d secondes correspondent a %d heures, %d minutes et %d secondes.\n", nbseconde, heures, minutes, secondes);
        return 0;
    }