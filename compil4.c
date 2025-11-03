#include <stdio.h>

int main() {
    printf("Test\n");
    return 0;
}
/*
 expected '=', ',', ';', 'asm' or '__attribute__' before '{' token
 int main {
          ^
Il manque des parenthèses après le main pour indiquer que c'est une fonction.
*/