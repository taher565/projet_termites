#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;


const int taille = 40;
const double pourcentage_termites = 1.;
const double pourcentage_brindille = 5.;
int nb_termites;

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
    Place terrain[taille][taille];
    Termite termites[taille][taille];
};


bool aleatoire(double p) {
    return rand() < p*(RAND_MAX + 1.);
}

Coord creer_coord(int i, int j) {
   Coord c;
   c.x = i;
   c.y = j;
   return c;
}
void creer_termite(Termite &t,int i,int j) {
    int ind_t;
    t.coord = creer_coord(i,j);
    t.indice=ind_t;
    t.direction=rand()%8;
    t.brindille=false;
    t.tourner_sur_place=false;
    t.sablier=0;
}

void place_vide(Place &p) {
    p.type=PLACE_TYPE_VIDE;
    p.indtermite=-1;
}

bool contient_termite(Place &p) {
    return p.indtermite != -1;
}
bool contient_brindille(Place &p) {
    p.type = PLACE_TYPE_BRINDILLE;
    return true;
}

int directionAleatoire() {
    return rand() % NB_DIRECTIONS;
}

void initialiseTerrain() {
    Terrain t;
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            if (aleatoire(pourcentage_termites/100.)) {
                // aleatoire est entre 0 et 1
                t.terrain[i][j].type = PLACE_TYPE_TERMITE;
                t.terrain[i][j].indtermite = directionAleatoire(); // n'imp
            } else {
                t.terrain[i][j].indtermite = DIRECTION_HAUT; // n'imp
                if (aleatoire(pourcentage_brindille/100)) {
                    t.terrain[i][j].type = PLACE_TYPE_BRINDILLE;
                } else {
                    t.terrain[i][j].type = PLACE_TYPE_VIDE;
                }
            }
        }
    }
}

void afficheDirection(int direction) {
    switch (direction) {
        case DIRECTION_GAUCHE:
        case DIRECTION_DROITE:
            cout << "-";
            break;
        case DIRECTION_HAUT:
        case DIRECTION_BAS:
            cout << "|";
            break;
        case DIRECTION_GAUCHE_HAUT:
        case DIRECTION_DROITE_BAS:
            cout << "\\";
            break;
        case DIRECTION_GAUCHE_BAS:
        case DIRECTION_DROITE_HAUT:
            cout << "/";
            break;
        default:
            cout << "D";
    }
}
void afficheTerrain(Place t[taille][taille]) {
    for(int i = 0; i < taille; i++) {
        if (i) cout << endl;
        for(int j = 0; j < taille; j++) {
            int type_place = t[i][j].type;
            switch (type_place){
                case PLACE_TYPE_VIDE:{
                    cout<<"-";
                break;
                }
                case PLACE_TYPE_BRINDILLE:{
                    cout<<"0";
                break;
                }
                case PLACE_TYPE_TERMITE:{
                    afficheDirection(t[i][j].indtermite);
                break;
                }
                default:
                    cout<<"?";
            }
        }
    }
}

int main() {
    srand(time(NULL));
    initialiseTerrain();
    Terrain t;
    afficheTerrain(t.terrain);
    return 0;
}
