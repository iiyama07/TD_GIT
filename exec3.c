#include <stdio.h>

int main() {
    int x;
    int y = x + 5;  
    printf("%d\n", y);
    return 0;
}
/*
Le problème dans ce code est que la variable 'x' est utilisée sans avoir été initialisée au préalable.
 Lorsque cette valeur indéterminée est utilisée dans l'expression 'x + 5', le résultat est également indéterminé.
 Donc il faut initialiser 'x' avant de l'utiliser, par exemple en lui assignant une valeur comme 'int x = 0;'
*/