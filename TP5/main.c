#include <stdio.h>
#include "fichier.h"
#include <windows.h>
#include <locale.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF-8");

    int consommation [7];
    initialiser(consommation);

    if (charger(consommation)) {
        printf("Données chargées avec succès.\n\n");
    } else {
        printf("Pas de fichier trouvé.\n\n");
    }

    int quitter = 0;
    while (!quitter) {
        afficherMenu();
        int choix = lireChoix();

        switch (choix) {
            case 1: 
                ajouterConsommation(consommation);

                break;

            case 2:
                afficherResume(consommation);
                break;

            case 3:
                quitter = 1;
                break;
        }
    }

    printf("Programme termine.\n");
    return 0;
}
