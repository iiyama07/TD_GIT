#include <stdio.h>

int main() {
    if (1) {
        printf("ok\n");
    } else{
        printf("nope\n");
    }
    return 0;
    
}
/*
 expected identifier or '(' before 'return'
     return 0;
     ^~~~~~
expected identifier or '(' before '}' token
 }
 ^
Il faut ajouter une accolade ouvrante apres le else pour corriger l'erreur.
*/