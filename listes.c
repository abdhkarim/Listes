#include <stdio.h>
#include <string.h>
#include <stdlib.h>	
#include "listes.h"



/* --------------------------------------------------------------------------------------------------------- */
/*                                               Affichage des listes                                        */
/* --------------------------------------------------------------------------------------------------------- */

// Basique 
bool liste_est_vide(pListe liste)
{
	if(liste == NULL)
	{
		return 1;
	}
	return 0;
}

void AfficherListe(pListe liste)
{
	printf("[");
	// Tant que le pointeur de la liste n'est pas égal a NULL, on affiche la liste
	while (liste != NULL)
	{
		printf("%d -> ", liste->data);
		liste = liste->next; // on passe au maillon suivant
	}
	printf("NULL ");
	printf("]");


}

// Recursivité
void AfficherListeRecursive(pListe liste)
{
	
	// On affiche recursivement en montrant le maillon et en passant au suivant
	// La condition d'arret est que le maillon de la liste est égal a NULL (fin)
	if (liste != NULL)
	{
		printf("%d -> ", liste->data);
		AfficherListeRecursive(liste->next); // Appel recursif de la fonction
	}
	else 
	{
		printf(" NULL "); // Affichage de NULL
	}
	


}
void AfficherListeRecursiveInverse(pListe liste)
{ 
	printf("[");
	// On affiche l'inverse recursivement en appelant d'abord la fonction
	// C'est comme si on créait une pile et qu'on dépile des lors que le pointeur est egal a NULL
	if(liste!= NULL )
	{
		AfficherListeRecursiveInverse(liste->next); // Appel recursive pour afficher le premier qui finit en NULL
		printf("<- %d ", liste->data); // Affichage du dernier au premier
	}
	else {
		printf("NULL ");
	}
printf("]");

}




/* --------------------------------------------------------------------------------------------------------- */
/*                                            Modification des listes                                        */
/* --------------------------------------------------------------------------------------------------------- */

pListe InsererDebut(pListe liste, int nouvelleVal)
{
	// Cette fonction c'est pour mettre un nouveau maillon sur la tete
	
	//  4 -> 2 -> 5 -> 9 -> NULL
	// 	^	  
// Nouveau maillon sur la tete de la liste 


	pListe nvMaillon = malloc(sizeof(Liste));
	nvMaillon->data = nouvelleVal;

	if(liste!=NULL)
	{
		nvMaillon->next = liste;
	}
	else
	{
		nvMaillon->next = NULL;
	}
	return nvMaillon;
}


pListe InsererFin(pListe liste, int valeur)
{
	// Création du maillon
	pListe nvMaillon = malloc(sizeof(Liste));
	nvMaillon->data = valeur;
	nvMaillon->next = NULL;
	
	// On utilise le courant pour pouvoir se deplacer plus facilement et insérer le maillon en fin de ligne
	// On les fais pointer dans la même adresse
	pListe courant = liste; 
	if (courant == NULL)
	{
		return nvMaillon;
	}
	else 
	{
		while(courant->next != NULL) // je m'arrete lorsque je suis au dernier element, pas quand c'est NULL
		{
			courant = courant->next; // parcours 
		}
	}
	courant->next = nvMaillon;
	return liste; // sachant que liste est égal a courant hein
}

pListe InsererFinRec(pListe liste, int valeur)
{
	// Si le pointeur est egal a NULL -> Création du maillon et insertion
	// Remarque : si la liste est vide elle est directement créé (astucieux non ?)
	if(liste == NULL){
	pListe nvMaillon = malloc(sizeof(Liste));
	nvMaillon->data = valeur;
	nvMaillon->next = NULL;
	return nvMaillon; // il sera egal a tete->suiv
	}
	else 
	{
		liste->next = InsererFinRec(liste->next, valeur); /* Appel recursive afin de parcourir la liste jusqu'a atteindre
													le dernier elt de la liste */
	}
	return liste;
}

pListe SupprimerElt(pListe liste, int valeur) {
    // Vérifie si la liste est vide
    if (liste == NULL) {
        printf("Liste Vide pas de suppression\n");
        return NULL; // Retourne NULL car il n'y a rien à supprimer
    }

    // Vérifie si l'élément à supprimer est le premier de la liste
    if (liste->data == valeur) {
        pListe temp = liste; // Temporairement stocke le premier élément
        liste = liste->next; // Avance la liste pour exclure le premier élément
        free(temp); // Libère la mémoire de l'élément supprimé
        return liste; // Retourne la nouvelle liste sans le premier élément
    }

    // Initialise deux pointeurs pour parcourir la liste
    pListe courant = liste;       // Pointeur pour suivre l'élément actuel
    pListe suivant = liste->next; // Pointeur pour suivre l'élément suivant

    // Parcourt la liste jusqu'à trouver l'élément à supprimer ou atteindre la fin
    while (suivant != NULL) {
        // Vérifie si l'élément suivant est celui à supprimer
        if (suivant->data == valeur) {
            courant->next = suivant->next; // Élimine l'élément suivant de la liste
            free(suivant); // Libère la mémoire de l'élément supprimé
            break; // Sort de la boucle après suppression
        }
        // Avance les deux pointeurs pour continuer la recherche
        courant = courant->next;
        suivant = suivant->next;
		/* N.B : Si on veut supprimer une seule valeur de la liste, on a juste a ne pas mettre le parcours 
		après la suppression */
    }

    // Si l'élément à supprimer n'a pas été trouvé
    if (suivant == NULL) {
        printf("Non trouvé, pas de suppression pour l'élément !\n");
    }

    // Retourne la liste mise à jour
    return liste;
}


pListe InsererMilieu(pListe liste, int valeur) {
    // Si la liste est vide, crée un nouveau maillon et le retourne
    if (liste == NULL) {
        pListe nvMaillon = malloc(sizeof(Liste));
        nvMaillon->data = valeur;
        nvMaillon->next = NULL;
        return nvMaillon;
    }

    // Si la valeur à insérer est inférieure à la tête de la liste
    if (valeur < liste->data) {
        // Appelle une fonction (supposée existante) pour ajouter un maillon en tête
        return InsererDebut(liste, valeur);
    }

    // Sinon, procède à l'insertion dans le milieu ou à la fin
    // Ici, la mémoire est allouée car elle sera utilisée
    pListe nvMaillon = malloc(sizeof(Liste));
    nvMaillon->data = valeur;

	// Pointeurs sur l'elt actuel et l'elt suivant
    pListe courant = liste;		  // actuel
    pListe suivant = liste->next; // suivant

    // Trouve la position où insérer le nouveau maillon
    while (suivant != NULL && suivant->data < valeur) {
        courant = courant->next; // suivant de l'actuel
        suivant = suivant->next; // suivant du suivant
    }

    // Insère le nouveau maillon dans la liste
    courant->next = nvMaillon;
	nvMaillon->next = suivant;

    // Retourne la liste originale mise à jour
    return liste;
}


pListe ConcatUneListe(pListe liste1, pListe liste2)
{
	// Vérif. de condition
	if(liste1 == NULL)
	{
		AfficherListeRecursive(liste2);
	}
	if(liste2 == NULL)
	{
		AfficherListeRecursive(liste1);
	}
	pListe Concatenation = NULL;

	pListe courant = liste1;

	while(courant!=NULL)
	{
		Concatenation = InsererFin(Concatenation, courant->data);
		courant = courant->next;
	}
	courant =liste2;

	while(courant!=NULL)
	{
		Concatenation = InsererFin(Concatenation, courant->data);
		courant = courant->next;
	}
	// free(courant);
	return Concatenation;
	

}

pListe ConcatUneListeSansRep(pListe liste1, pListe liste2)
{
	// Vérif. de condition
	if(liste1 == NULL)
	{
		AfficherListeRecursive(liste2);
	}
	if(liste2 == NULL)
	{
		AfficherListeRecursive(liste1);
	}
	pListe Concatenation = NULL;

	pListe courant = liste1;

	while(courant!=NULL)
	{
		Concatenation = InsererFin(Concatenation, courant->data);
		courant = courant->next;
	}
	courant =liste2;

	while(courant!=NULL)
	{
		Concatenation = InsererFin(Concatenation, courant->data);
		courant = courant->next;
	}
	// free(courant);
	return Concatenation;
}

int LongueurListe(pListe liste)
{
	int cpt = 0;

	while(liste != NULL)
	{
		cpt++;
		liste = liste->next; // passe au suivant jusqu'a que ce soit egal a null
	}
	return cpt;
}

int LongueurListeRec(pListe liste)
{
	if (liste == NULL)
	{
		return 0;
	}
	return 1 + LongueurListeRec(liste->next);
}

bool est_present_listeRec(pListe liste, int x) {
    // Condition d'arrêt : fin de la liste
    if (liste == NULL) {
        return false;
    }

    // Vérifier si l'élément courant est celui recherché
    if (liste->data == x) {
        return true;
    }

    // Continuer la recherche récursivement dans le reste de la liste
    return est_present_listeRec(liste->next, x);
}
