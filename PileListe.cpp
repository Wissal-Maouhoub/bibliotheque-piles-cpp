#include "PileListe.h"
#include <iostream>

using namespace std;

template <typename T>
LPile<T>::LPile()
{
    sommet = nullptr;
    taille = 0;
}

template <typename T>
LPile<T>::~LPile()
{
    while (!estVide())
    {
        depiler();
    }
}

template <typename T>
void LPile<T>::empiler(const T& valeur)
{
    Noeud* nouveau = new Noeud(valeur);

    nouveau->suivant = sommet;
    sommet = nouveau;

    taille++;
}

template <typename T>
T LPile<T>::depiler()
{
    if (estVide())
    {
        return T();
    }

    Noeud* ancien = sommet;

    T valeur = ancien->valeur;

    sommet = sommet->suivant;

    delete ancien;

    taille--;

    return valeur;
}

template <typename T>
T LPile<T>::sommetValeur() const
{
    if (estVide())
    {
        return T();
    }

    return sommet->valeur;
}

template <typename T>
bool LPile<T>::estVide() const
{
    return sommet == nullptr;
}

template <typename T>
int LPile<T>::getTaille() const
{
    return taille;
}

template <typename T>
void LPile<T>::afficher() const
{
    cout << "Pile : ";

    Noeud* courant = sommet;

    while (courant != nullptr)
    {
        cout << courant->valeur;

        if (courant->suivant != nullptr)
        {
            cout << ", ";
        }

        courant = courant->suivant;
    }

    cout << endl;
}

template class DLL_EXPORT LPile<char>;
