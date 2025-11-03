#include <stdio.h>

// ici le comilateur ne dit malheureusement rien mais il devrait,
// executer pour essayer de comprendre ce qu'il se passe 
int main() {
    int tableau[5];
    int i = 12;
    for (int j = 0; j < 5; j++)
    {
        tableau[j] = 1;
    }
    printf("OK %d\n", tableau[4]);
    return 0;
}

/*

Le code tente d'accéder à un élément en dehors des limites du tableau (tableau[5] alors que les indices valides sont de 0 à 4).
 En C cela conduit à un comportement indéfini ce qui signifie que le programme peut se comporter de manière imprévisible. 
 Le compilateur ne signale pas cette erreur car il ne vérifie pas les limites des tableaux à la compilation. 
 Il faut donc mettre printf("OK %d\n", tableau[4]); a la place de printf("OK %d\n", tableau[5]);
*/