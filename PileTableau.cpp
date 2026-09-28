#include "PileTableau.h"
#include <iostream>

using namespace std;

template <typename T>
TPile<T>::TPile()
{
    capacite = 4;
    taille = 0;
    tableau = new T[capacite];
}

template <typename T>
TPile<T>::~TPile()
{
    delete[] tableau;
}

template <typename T>
void TPile<T>::empiler(const T& valeur)
{
    if (taille == capacite)
    {
        agrandir();
    }

    tableau[taille] = valeur;
    taille++;
}

template <typename T>
T TPile<T>::depiler()
{
    if (estVide())
    {
        return T();
    }

    taille--;

    return tableau[taille];
}

template <typename T>
T TPile<T>::sommetValeur() const
{
    if (estVide())
    {
        return T();
    }

    return tableau[taille - 1];
}

template <typename T>
bool TPile<T>::estVide() const
{
    return taille == 0;
}

template <typename T>
int TPile<T>::getTaille() const
{
    return taille;
}

template <typename T>
void TPile<T>::afficher() const
{
    cout << "Pile : ";

    for (int i = taille - 1; i >= 0; i--)
    {
        cout << tableau[i];

        if (i > 0)
        {
            cout << ", ";
        }
    }

    cout << endl;
}

template <typename T>
void TPile<T>::agrandir()
{
    capacite = capacite * 2;

    T* nouveauTableau = new T[capacite];

    for (int i = 0; i < taille; i++)
    {
        nouveauTableau[i] = tableau[i];
    }

    delete[] tableau;

    tableau = nouveauTableau;
}
template class DLL_EXPORT TPile<char>;
