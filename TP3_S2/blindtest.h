#ifndef Blindtest
#define Blindtest

typedef struct {
    char file[256];
    char title[256];
    char artist[256];
} Song;


typedef struct {
    char nom[100];
    int score;
} Joueur;

typedef struct Liste_Joueur {
    char nom[100];
    int meilleur_score;
    struct Liste_Joueur *suivant;
} Liste_Joueur;

void trim_newline(char *s);

void normalize_string(char *dest, const char *src);

int string_equals_normalized(const char *a, const char *b);

void play_song_excerpt_at(const char *filename, int start, int seconds);

int load_songs(const char *filename, Song song[], int taille);

void melanger(Song song[], int count);

void gestion_du_joueur(Joueur *joueur);



#endif