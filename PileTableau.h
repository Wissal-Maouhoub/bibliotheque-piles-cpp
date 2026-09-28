#ifndef PILE_TABLEAU_H
#define PILE_TABLEAU_H

#include "exports.h"

template <typename T>
class DLL_EXPORT TPile
{
private:
    T* tableau;
    int capacite;
    int taille;

    void agrandir();

public:
    TPile();
    ~TPile();

    void empiler(const T& valeur);
    T depiler();
    T sommetValeur() const;

    bool estVide() const;
    int getTaille() const;
    void afficher() const;
};

#endif
