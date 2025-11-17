#include <stdio.h>

int main() {
    int n;
    printf("Entrez une valeur pour n (entre 5 et 10) : ");
    scanf("%d", &n);

    while (n < 5 || n > 10) {
        printf("Erreur, veuillez entrer une valeur entre 5 et 10 : ");
        scanf("%d", &n);
    }

    int width = n * n;
    int max_height = 3 * (n - 1);
    char img[100][100];
    int i, j;

    for (i = 0; i < max_height; i++) {
        for (j = 0; j < width; j++) {
            img[i][j] = ' ';
        }
    }

    int mid = width / 2;

    for (i = 0; i < n; i++) {
        int left = mid - i;
        int right = mid + i;

        for (j = 0; j < width; j++) {
            if (j == left || j == right) {
                img[i][j] = 'A';
            } else if (j > left && j < right) {
                img[i][j] = 'S';
            }
        }
    }

    img[n-1][mid - n] = '_';
    img[n-1][mid + n] = '_';

    int cotegauche = mid - (n - 2);
    int cotedroit = mid + (n - 2);

    for (i = n; i < max_height && cotegauche < cotedroit; i++) {
        for (j = 0; j < width; j++) {

            if (j == cotegauche || j == cotedroit) {
                img[i][j] = '.';   
            } else if (j > cotegauche && j < cotedroit) {
                img[i][j] = 'S';   
            }
        }

        cotegauche++;      
        cotedroit--;
    }

    printf("\nImage (%d x %d) :\n", max_height, width);
    for (i = 0; i < max_height; i++) {
        for (j = 0; j < width; j++) {
            printf("%c", img[i][j]);
        }
        printf("\n");
    }

    return 0;
}
