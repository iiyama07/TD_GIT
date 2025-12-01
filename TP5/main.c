#include <stdio.h>
#include "fichier.h"

int main() {
    int conssomation [7];
    int quitter = 0;
    while (!quitter) {
        afficherMenu();
        int choix = lireChoix();

        switch (choix) {
            case 1: 

                break;

            case 2:

                break;

            case 3:
                quitter = 1;
                break;
        }
    }

    printf("Programme termine.\n");
    return 0;
}
