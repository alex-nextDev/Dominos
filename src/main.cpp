//
//  main.cpp
//  Correction Domino
//
//  Created by Alexandre Leuthreau on 10/03/2022.
//

#include <iostream>
#include <array>

using namespace std;

struct Domino
{
    int valG;
    int valD;
};

const int NB_DOMINOS = 28;

struct Jeu
{
    array<Domino, NB_DOMINOS>j;
    int effectif;
};

Domino creerUnDomino(int g, int d)
{
    Domino d1;
    d1.valG = g;
    d1.valD = d;
    return d1;
}

void afficherUnDomino(const Domino &d)
{
    cout<<"("<<d.valG<<":"<<d.valD<<")"<<endl; 
}

void creerJeu(Jeu &j)
{ 
    int k = 0; //indice du tableau
    
    for(int g = 0; g <= 6; g++)
    {
        for(int d = g; d <= 6; d++)
        {
            j.j[k] = creerUnDomino(g, d); //remplir le jeu de dominos
            k++;
        }
        
        j.effectif = NB_DOMINOS; // dire qu'il y a 28 dominos dans le jeu
    }
    
}

/*
 
 i  j
 
 0  0
 0  1
 0  2
 0  3
 0  4
 0  5
 0  6
 0  7
 0  8
 0  9
 1  1
 1  2
 .  .
 .  .
 .  .
 
 
 */



void afficherUnJeu(const Jeu &j)
{
    for(int i = 0; j.effectif; i++)
    {
        afficherUnDomino(j.j[i]);
    }
    
    
}


int valGauche(const Domino &d)
{
    return  d.valG;
    
}

void valDroite(const Domino &d, int &droite)
{
    droite = d.valD;
}

Domino retournerUnDomino(const Domino &d)
{
    Domino d1;
    d1.valG = d.valD;
    d1.valD = d.valG;
    return d1;
    
}

bool estDouble(const Domino &d)
{
    return d.valG == d.valD;
    
}


int points(const Domino &d)
{
    return d.valG + d.valD;
    
}

int pointsJeu(const Jeu &j)
{
    int totalPoints = 0;
    
    for(int i = 0; i < j.effectif; i++) //j.effectif -> nb total dans un jeu
    {
        totalPoints = totalPoints + points(j.j[i]);
    }
    
    return totalPoints;
}


int pointsJeuRec(const Jeu &j, int nb) //nb indice du nombre de dominos dans jeu
{
    if(nb == 1)
    {
        return points(j.j[nb - 1]); 
        
    }
    else
    {
        return points(j.j[nb - 1]) + pointsJeuRec(j, nb-1);
    }
    
    
}





int main(int argc, const char * argv[]) {
    
    return 0;
}
