#ifndef FICHIER
#define FICHIER

void afficherMenu();

int lireChoix();

void initialiser(); 

void ajouterConsommation(int consommation[]);

void afficherResume(int consommation[]);

int charger(int consommation[]);

int sauvegarder(int consommation[]);

int humeurBonbons(int nbBonbons);

int humeurLegumes(int nbLegumes);

int humeurFruits(int nbFruits);

void afficherBarre(int valeur, int max);

void afficherScoreEtObjectifs(int consommations[], int objectifs[]);

int calculerScoreSante(int consommations[], int objectifs[]);

#endif
