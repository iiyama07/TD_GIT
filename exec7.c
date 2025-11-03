#include <stdio.h>

int main() {
    int distance_km = 100;
    int vitesse_kmh = 50;
    float temps = distance_km / vitesse_kmh; 
    int minutes = temps * 60;
    printf("minutes = %d\n", minutes); 
    return 0;
}
/*
Le problème dans ce code est que la variable 'temps' est déclarée comme un entier (int)
 Dans ce cas, la division de 100 par 50 donne 2, ce qui est correct, mais si les valeurs changeaient pour donner un résultat non entier, le résultat serait tronqué.
 Pour corriger il faut déclarer 'temps' comme un type flottant pour permettre une division décimale précise.
*/