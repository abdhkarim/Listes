#ifndef __LISTES_H__
#define __LISTES_H__

// En tetes 
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

// Structures
typedef struct Liste{
	int data ;
	struct Liste *next ;
}Liste, *pListe ;



/* RAPPEL : pour faire de la compilation séparé, compilez comme ça 
	gcc -c votre_fichier

*/

// Affichage de la liste 
bool liste_est_vide(pListe liste);
void AfficherListe(pListe liste);
void AfficherListeRecursive(pListe liste);
void AfficherListeRecursiveInverse(pListe liste);
int LongueurListe(pListe liste);
bool est_present_listeRec(pListe liste, int x);

// Modification des listes 
pListe InsererDebut(pListe liste, int nouvelleVal);
pListe InsererFin(pListe liste, int valeur);
pListe InsererFinRec(pListe liste, int valeur);
pListe SupprimerElt(pListe liste, int valeur);
pListe InsererMilieu(pListe liste, int valeur);
int LongueurListeRec(pListe liste);


// Concaténation des listes 
pListe ConcatUneListe(pListe liste1, pListe liste2);
pListe ConcatUneListeSansRep(pListe liste1, pListe liste2);



#endif
