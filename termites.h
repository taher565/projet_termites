#ifndef TERMITES_H_INCLUDED
#define TERMITES_H_INCLUDED

const int TAILLE = 40;
const double POURCENTAGE_TERMITES = 1.;
const double POURCENTAGE_BRINDILLES = 5.;


enum {
    PLACE_TYPE_VIDE,
    PLACE_TYPE_BRINDILLE,
    PLACE_TYPE_TERMITE,
} type_place;
enum {
    DIRECTION_GAUCHE,
    DIRECTION_GAUCHE_HAUT,
    DIRECTION_HAUT,
    DIRECTION_DROITE_HAUT,
    DIRECTION_DROITE,
    DIRECTION_DROITE_BAS,
    DIRECTION_BAS,
    DIRECTION_GAUCHE_BAS,
    NB_DIRECTIONS
} directions;

struct Coord {
    int x;
    int y;
};
struct Place {
    int type;
    int indtermite;
};
struct Termite {
    Coord coord;
    int direction;
    int indice;
    int sablier;
    bool brindille;
    bool tourner_sur_place;
};
struct Terrain {
    Place places[TAILLE][TAILLE];
    Termite termites[TAILLE*TAILLE];
    int nbtermites;
};

bool aleatoire(double p);
int directionAleatoire();

Coord creerCoord(int i, int j);
Termite creerTermite(int indice, int x, int y);

void place_vide(Place &p);
bool contient_termite(Place &p);
bool contient_brindille(Place &p);

void initialiseTerrain(Terrain &t);

void afficheTermite(Termite m);
void afficheTerrain(Terrain t);

#endif // TERMITES_H_INCLUDED
