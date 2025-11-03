#include <stdio.h>

int main() {
    int i = 0;
    while (i < 10) {
        printf("%d\n", i);
        i++;
    }
    return 0;
}
/*
Le problème dans ce code est que la variable 'i' n'est jamais incrémentée à l'intérieur de la boucle while.
 Par conséquent, la condition 'i < 10' reste toujours vraie, ce qui entraîne une boucle infinie.
 Pour corriger ce code, il faut ajouter une instruction pour incrémenter 'i' à chaque itération de la boucle, par exemple en ajoutant 'i++;' juste avant la fin de la boucle.
*/