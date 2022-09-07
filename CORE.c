#include "CORE.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"




/**
 * \fn player setup_player(player J)
 * \brief Initialise les informations d'un player
 *
 * \param[in] void
 * \return la structure initialisée
 */
player setup_player (void) {

	int i;
	int j;
	player J;
	
	J.restants = 5;
	J.touche = 0;
	J.IA.mode = 0;
	J.IA.target[0] = 0;
	J.IA.target[1] = 0;
	J.IA.pas = 0;
	J.IA.sens = 0;

	for(i=0;i<10;i++)
		{
		for(j=0;j<10;j++)
			{
				J.map[i][j]=0;
			}

		}		
		
	for(i=0;i<5;i++){
	
		if (i<=1){J.flotte[i].longueur = i+2;}
		else{J.flotte[i].longueur = i+1;}
		J.flotte[i].ID = i+3;
		J.flotte[i].state = 1;
	}
	
	return J;	
}


/**
 * \fn player Placeur_bat(int Xa, int Ya, int Xb, int Yb, int Horizontal, int cpt, player J1);
 * \brief Pose le bateau
 *
 * \param[in] Xa : Longitude du point a
 * \param[in] Ya : Latitude du point a
 * \param[in] Xb : Longitude du point b
 * \param[in] Yb : Latitude du point b
 * \param[in] Horizontal : égal à 1 si le batteau est horizontal
 * \param[in] cpt : numéro du bateau
 * \param[in] J1 : structure player du joueur 
 * \return la structure avec le bateau placé
 */
player Placeur_bat(int Xa, int Ya, int Xb, int Yb, int Horizontal, int cpt, player J1)
{
	int i;
	
	if (Horizontal==0)
	{
		if (Yb>Ya)
		{
			for(i=Ya; i<= Yb ; i++)
			{
				J1.map[i][Xa] = J1.flotte[cpt].ID;
			}
		}
		else
		{
			
			for(i=Yb; i<= Ya ; i++)
			{
				J1.map[i][Xa] = J1.flotte[cpt].ID;
			}
		}
	}
	
	else
	{
		if (Xb>Xa)
		{
			
			for(i=Xa; i<= Xb ; i++)
			{
				J1.map[Ya][i] = J1.flotte[cpt].ID;
			}
		}
		else
		{
			
			for(i=Xb; i<= Xa ; i++)
			{
				J1.map[Ya][i] = J1.flotte[cpt].ID;
			}
		}
	}
	
	return J1;
}

/**
 * \fn int myrand(int inf, int sup);
 * \brief Donne un int entre les borns inférieures et supérieures
 *
 * \param[in] inf : borne inférieure
 * \param[in] isup : borne supérieure
 * \return un int aléatoire entre les deux
 */
int myrand(int inf, int sup)
{
	int value;
	value = (rand()) % (sup-inf)+inf;
	return value;
}


/**
 * \fn player Game_checker(player J);
 * \brief Actualise l'état des batteaux du joueur et le nombre de ses batteaux restants
 *
 * \param[in] J : Joueur étudié
 * \return la version actualisée de J
 */
player Game_checker(player J)
{
	int stock = J.restants;
	J.restants=0;
	int i;
	int j;
	int k;
	for(i=0;i<=4;i++)
		{
			J.flotte[i].state=0;
			for(j=0;j<10;j++)
			{
				for(k=0;k<10;k++)
				{
					if(J.map[k][j]==J.flotte[i].ID)
					{
						J.flotte[i].state=1;
					}
				}
			}
			J.restants+=J.flotte[i].state;
		}
		
	if (stock != J.restants) {printf("Coulé !\n\n");}
	return J;
}





















