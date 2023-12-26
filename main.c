#include <stdio.h>
#include <string.h>
#include <stdlib.h>	
#include "listes.h"


int main ()
{

	pListe ma_liste1 = NULL;
	pListe ma_liste2 = NULL;
	pListe ma_liste3 = NULL;

	
	ma_liste1= InsererMilieu(ma_liste1,6);
	ma_liste1= InsererMilieu(ma_liste1,0);
	ma_liste1= InsererMilieu(ma_liste1,1);
	ma_liste1= InsererMilieu(ma_liste1,3);
	ma_liste1= InsererFin(ma_liste1,4);

	printf("Liste 1 :");
	printf("\n");
	AfficherListeRecursive(ma_liste1);
	printf("\n");
	printf("\n");
	
	ma_liste2= InsererMilieu(ma_liste2,2);
	ma_liste2= InsererMilieu(ma_liste2,10);
	ma_liste2= InsererMilieu(ma_liste2,4);
	ma_liste2= InsererMilieu(ma_liste2,8);
	ma_liste2= InsererFin(ma_liste2,7);

	printf("Liste 2 :");
	printf("\n");
	AfficherListeRecursive(ma_liste2);
	printf("\n");
	printf("\n");

	ma_liste3 = ConcatUneListe(ma_liste1, ma_liste2);


	printf("Après concatenation des deux listes :");
	printf("\n");
	AfficherListeRecursive(ma_liste3);
	printf("\n");
	printf("\n");

	int compteur = LongueurListeRec(ma_liste3);
	printf("la liste a pour longueur %d\n\n", compteur);

	int valeurRecherchee = 96;

	bool Trouve = est_present_listeRec(ma_liste3, valeurRecherchee);

	if (Trouve) {
        printf("La valeur %d est présente dans la liste.\n", valeurRecherchee);
    } else {
        printf("La valeur %d n'est pas présente dans la liste.\n", valeurRecherchee);
    }

	return 0;
}