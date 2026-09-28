#ifndef PILE_LISTE_H
#define PILE_LISTE_H

#include "exports.h"

template <typename T>
class DLL_EXPORT LPile
{
private:

    struct Noeud
    {
        T valeur;
        Noeud* suivant;

        Noeud(const T& v)
        {
            valeur = v;
            suivant = nullptr;
        }
    };

    Noeud* sommet;
    int taille;

public:

    LPile();
    ~LPile();

    void empiler(const T& valeur);
    T depiler();
    T sommetValeur() const;

    bool estVide() const;
    int getTaille() const;
    void afficher() const;
};

#endif
