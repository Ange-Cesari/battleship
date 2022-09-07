#include "IHM.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "CORE.h"


/**
 * \fn int press start(void)
 * \brief Ecran d'acceuil du jeu
 *
 * \param[in] none
 * \return 0 si le joueur veut jouer, sinon 1
 */
int press_start(void){


	char choix;
	
	system("clear");

	printf("\e[38;5;255m--------------------------------------------------------\n\n\n\n");
	printf("                         ACCUEIL		          \n\n\n\n");
	printf("--------------------------------------------------------\n");
	printf("          Appuyez sur '1' pour jouer en JcE           \n\n");
	printf("          Appuyez sur '2' pour jouer en EcE           \n\n");
	printf("    Appuyez sur '3' pour jouer en JcE en mode DEV     \n\n");	
	printf("Appuyez sur '4' pour jouer en JcE placement automatique\n\n");
	printf("                      q pour quitter					\n");
	printf("--------------------------------------------------------\n\n");
	printf(">");
	char a;
	do {a = scanf(" %c",&choix);}while (a<1);
	 
		 			
	if(choix=='q')
	 {
			return 0;
	 }
	 else if(choix > '0' && choix < '5'){return choix-'0';}
	 else {printf("\n\nCommande invalide, on considère que vous voulez quitter.\n\n"); return 0;}
}

/**
 * \fn affiche_tableaux_spoiled(player J1,player J2)
 * \brief Affiche les tableaux des joueurs J1 et J2 au complet
 *
 * \param[in] J1 : structure player du premeir joueur
 * \param[in] J2 : structure player du deuxième joueur
 * \return void
 */
void affiche_tableaux_spoiled(player J1,player J2){


	int j = 0;
	int i = 0;
	
	system("clear");

	printf("\e[38;5;255m\n\n\n                 PLAYER 1                                     PLAYER 2\n\n");	
			
	for(i=0;i<=10;i++)
	{
		if(i==0)
		{
			printf("        0  1  2  3  4  5  6  7  8  9                 0  1  2  3  4  5  6  7  8  9\e[0m");
		}
		
		else
		{
			for(j=0;j<=22;j++)
			{
				if(j==0 || j==12)
				{
					printf("     \e[38;5;255m%c\e[0m \e[48;5;020m",'A'+i-1);
				}
				
				else if (j<11)
				{
					switch(J1.map[i-1][j-1])
					{
						case 0:
							printf("\e[48;5;020m   ");			
							break;

						case 1:
							printf("\e[38;5;196m\e[48;5;020m-X-");				
							break;

						case 2:
							printf("\e[38;5;196m \e[48;5;240mX-");				
							break;

						default:

							if(J1.map[i-1][j-1]<=7)
							{
								printf(" \e[48;5;240m  ");
							}

							else
							{
								printf("%d ",J1.map[i-1][j-1]);
							}

					}
				}
				
				else if (j == 11)
				{
					printf("\e[0m        ");
				}
				
				else
				{
					switch(J2.map[i-1][j-13])
					{
						case 0:
							printf("\e[48;5;020m   ");			
							break;

						case 1:
							printf("\e[38;5;196m\e[48;5;020m-X-");				
							break;

						case 2:
							printf("\e[38;5;196m \e[48;5;240mX-");				
							break;

						default:

							if(J2.map[i-1][j-13]<=7)
							{
								printf(" \e[48;5;240m  ");
							}

							else
							{
								printf("%d ",J2.map[i-1][j-13]);
							}

					}
				}
				
				
			}
			if(i!=10)
			{
				printf("\e[0m\n       \e[48;5;020m");
				
				for (j=0;j<10;j++)
				{
					if (J1.map[i-1][j]>=2 && J1.map[i][j]>=2 ){if(J1.map[i-1][j]>2 && J1.map[i][j]>2 && J1.map[i-1][j]!=J1.map[i][j]){printf("\e[48;5;020m   ");}else{printf(" \e[48;5;240m  ");}}
					else {printf("\e[48;5;020m   ");}
				}
				
				printf("\e[0m               \e[48;5;020m");
				
				for (j=0;j<10;j++)
				{
					if (J2.map[i-1][j]>=2 && J2.map[i][j]>=2 ){if(J2.map[i-1][j]>2 && J2.map[i][j]>2 && J2.map[i-1][j]!=J2.map[i][j]){printf("\e[48;5;020m   ");}else{printf(" \e[48;5;240m  ");}}
					else {printf("\e[48;5;020m   ");}
				}
				
				printf("\e[0m");
			}
			else{printf("\e[0m");}									
		}
		printf("\n");
	}
	printf("\n\n\n\n\n\e[38;5;255m");
			
}

/**
 * \fn affiche_tableaux(player J1,player J2)
 * \brief Affiche les tableaux des joueurs J1 et une aprtie de J2
 *
 * \param[in] J1 : structure player du premeir joueur
 * \param[in] J2 : structure player du deuxième joueur
 * \return void
 */
void affiche_tableaux(player J1,player J2){


	int j = 0;
	int i = 0;
	
	system("clear");

	printf("\e[38;5;255m\n\n\n                 PLAYER 1                                     PLAYER 2\n\n");	
			
	for(i=0;i<=10;i++)
	{
		if(i==0)
		{
			printf("        0  1  2  3  4  5  6  7  8  9                 0  1  2  3  4  5  6  7  8  9\e[0m");
		}
		
		else
		{
			for(j=0;j<=22;j++)
			{
				if(j==0 || j==12)
				{
					printf("     \e[38;5;255m%c\e[0m \e[48;5;020m",'A'+i-1);
				}
				
				else if (j<11)
				{
					switch(J1.map[i-1][j-1])
					{
						case 0:
							printf("\e[48;5;020m   ");			
							break;

						case 1:
							printf("\e[38;5;196m\e[48;5;020m-X-");				
							break;

						case 2:
							printf("\e[38;5;196m \e[48;5;240mX-");				
							break;

						default:

							if(J1.map[i-1][j-1]<=7)
							{
								printf(" \e[48;5;240m  ");
							}

							else
							{
								printf("%d ",J1.map[i-1][j-1]);
							}

					}
				}
				
				else if (j == 11)
				{
					printf("\e[0m        ");
				}
				
				else
				{
					switch(J2.map[i-1][j-13])
					{
						case 0:
							printf("\e[48;5;020m   ");			
							break;

						case 1:
							printf("\e[38;5;196m\e[48;5;020m-X-");				
							break;

						case 2:
							printf("\e[38;5;196m \e[48;5;240mX-");				
							break;

						default:

							if(J2.map[i-1][j-13]<=7)
							{
								printf("\e[48;5;020m   ");
							}

							else
							{
								printf("%d ",J2.map[i-1][j-13]);
							}

					}
				}
				
				
			}
			if(i!=10)
			{
				printf("\e[0m\n       \e[48;5;020m");
				
				for (j=0;j<10;j++)
				{
					if (J1.map[i-1][j]>=2 && J1.map[i][j]>=2 ){if(J1.map[i-1][j]>2 && J1.map[i][j]>2 && J1.map[i-1][j]!=J1.map[i][j]){printf("\e[48;5;020m   ");}else{printf(" \e[48;5;240m  ");}}
					else {printf("\e[48;5;020m   ");}
				}
				
				printf("\e[0m               \e[48;5;020m");
				
				for (j=0;j<10;j++)
				{
					if(J1.map[i-1][j]==2 && J1.map[i][j] ==2){printf(" \e[48;5;240m  ");}else{printf("\e[48;5;020m   ");}
				}
				
				printf("\e[0m");
			}
			else{printf("\e[0m");}									
		}
		printf("\n");
	}
	printf("\n\n\n\n\n\e[38;5;255m");
			
}


/**
 * \fn player RecupCoordBateau(player J1, player IA);
 * \brief Demande les coordonées de ses batteaux au joueur et les stocke dans sa flotte et le tableau
 *
 * \param[in] J1 : structure player du premeir joueur
 * \param[in] IA : structure player de l'IA
 * \return le J1 modifié
 */
player RecupCoordBateau(player J1, player IA){

	int cpt=0;
	int checked = 0;
	int fin=0;
	int Xa;
	int Xb;
	char Ya;
	char Yb;
	int Horizontal;

		while (cpt<5)
		{
			fin = 0;
			
			while(fin==0)
			{
				affiche_tableaux(J1,IA);
				
				printf("Entrez les coordonées pour le batteau %d (de taille %d) sous la forme [lettre][chiffre] (la proue puis la poupe)\n\n",cpt, J1.flotte[cpt].longueur);
	
				printf("> ");
				int a;
				do {a = scanf(" %c%d",&Ya,&Xa);}while (a<2);
				
				printf("\n\n> ");
				do {a = scanf(" %c%d",&Yb,&Xb);}while (a<2);

				Ya=Ya-'A';
				Yb=Yb-'A';

				checked=CheckValueCoord(Xa,Ya,Xb,Yb);

				if (checked==4)
				{
					int Var=InterCoordBateau(Xa,Ya,Xb,Yb,1);
					
					if(Var==0)
					{
						fin=0;
					}
					
					else 
					{
						if(Var==1)
						{
							Horizontal=0;					
						}
		
						else
						{
							Horizontal=1;				
						}
						
						int stock = TailleBateau( Xa, Ya,  Xb, Yb, Horizontal);
						
						if( stock == J1.flotte[cpt].longueur)
						{
							int b = Superpo_bat(Xa, Ya, Xb, Yb, Horizontal, cpt, J1);
							
							if (b==1)
							{
								printf("Erreur, les batteaux ne peuvent se superposer.\n\n");
							}
							
							else
							{
								printf("Coordonées valides\n\n");
								J1 = Placeur_bat(Xa, Ya, Xb, Yb, Horizontal, cpt, J1);
								fin=1;
								cpt++;
							}
							
							
						}
					
						else
						{
							printf("Erreur, vous devez rentrer les coordonées pour un batteau de taille %d, vous avez entré celles d'un batteau de taille %d.\n\n",J1.flotte[cpt].longueur, stock);
						}						
					}			
						
				}				
				
				else
				{
					printf("Prière d'utiliser des lettres comprises entre A et J et des nombres compris entre 0 et 9.\n\n");
				}
			printf("Appuyez sur n'importe quelle touche pour continuer.\n\n> ");
			getchar();getchar();
			
			}

		}
		
		return J1;
}


/**
 * \fn int CheckValueCoord(int Xa,int Ya,int Xb,int Yb);
 * \brief Vérifie que a et b sont dans le tableau
 *
 * \param[in] Xa : Longitude du point a
 * \param[in] Ya : Latitude du point a
 * \param[in] Xb : Longitude du point b
 * \param[in] Yb : Latitude du point b
 * \return 4 si a et b sont dans le tableau, les autres valeurs possibles du return sont considérés comme message d'erreur
 */
int CheckValueCoord(int Xa,int Ya,int Xb,int Yb)
{
	int checked=0;
	if(0<=Xa && Xa<=9)
	{
		checked++;
	}
	
	if(0<=Ya && Ya<=9)
	{
	checked++;	
	}
	
	if(0<=Xb && Xb<=9)
	{
	checked++;	
	}
	
	if(0<=Yb && Yb<=9)
	{
	checked++;	
	}

	return checked;
}

/**
 * \fn int InterCoordBateau(int Xa, int Ya, int Xb, int Yb, int hum);
 * \brief Vérifie si le bateau est à la verticale, à l'horizontale ou en diagonale
 *
 * \param[in] Xa : Longitude du point a
 * \param[in] Ya : Latitude du point a
 * \param[in] Xb : Longitude du point b
 * \param[in] Yb : Latitude du point b
 * \param[in] hum : égal à 1 si s'adresse à un hummain
 * \return 0 si a et b sont confondus ou si le batteau est diagonal, 1 s'il est horizontal et 2 s'il est vertical
 */
int InterCoordBateau(int Xa, int Ya, int Xb, int Yb, int hum)
{
	
	if(Xa==Xb && Ya==Yb)
	{
		if (hum == 1){printf("Les coordonnées sélectionnées sont identiques. Veuillez réessayer.\n\n");}
		return 0;
	}
	
	else if(Ya==Yb)
	{
		return 2;	
	}
	
	else if(Xa==Xb)
	{
		return 1;
	}
	
	else
	{
		if (hum==1){printf("Les coordonnées sélectionnées sont incorrectes. Les positionnements doivent être horizontaux ou verticaux.\n\n");}
		return 0;	
	}
}
	
	
	
	
/**
 * \fn int TailleBateau(int Xa, int Ya, int Xb, int Yb, int Horizontal, int Vertical);
 * \brief calcule la distance entre a et b
 *
 * \param[in] Xa : Longitude du point a
 * \param[in] Ya : Latitude du point a
 * \param[in] Xb : Longitude du point b
 * \param[in] Yb : Latitude du point b
 * \param[in] Horizontal : égal à 1 si le batteau est horizontal
 * \return la distance entre a et b (la taille du batteau qu'ils désignent)
 */
int TailleBateau(int Xa, int Ya, int Xb, int Yb, int Horizontal)
{
	int bsize = 0;
	if(Horizontal==0)
	{
		bsize=Yb-Ya;

		if(bsize<0)
		{
			bsize*=-1;
		}
		bsize++;
	}
		
	else
	{
		bsize=Xb-Xa;
		
		if(bsize<0)
		{
			bsize*=-1;
			bsize+=1;
		}
		
		else
		{
			bsize+=1;
		}
	}
	
	return bsize;
}


/**
 * \fn player Superpo_bat(int Xa, int Ya, int Xb, int Yb, int Horizontal, int cpt, player J1);
 * \brief Vérifie qu'il n'y à pas superposition
 *
 * \param[in] Xa : Longitude du point a
 * \param[in] Ya : Latitude du point a
 * \param[in] Xb : Longitude du point b
 * \param[in] Yb : Latitude du point b
 * \param[in] Horizontal : égal à 1 si le batteau est horizontal
 * \param[in] cpt : numéro du bateau
 * \param[in] J1 : structure player du joueur 
 * \return 1 si superposition, 0 si RAS
 */
int Superpo_bat(int Xa, int Ya, int Xb, int Yb, int Horizontal, int cpt, player J1)
{
	int i;
	
	if (Horizontal==0)
	{
		if (Yb>Ya)
		{
			
			for(i=Ya; i<= Yb ; i++)
			{
				if (J1.map[i][Xa] != 0) {return 1;}
			}
		}
		else
		{
			for(i=Yb; i<= Ya ; i++)
			{
				if (J1.map[i][Xa] != 0) {return 1;}
			}
		}
	}
	
	else
	{
		if (Xb>Xa)
		{
			
			for(i=Xa; i<= Xb ; i++)
			{
				if (J1.map[Ya][i] != 0) {return 1;}
			}
		}
		else
		{
			for(i=Xb; i<= Xa ; i++)
			{
				if (J1.map[Ya][i] != 0) {return 1;}
			}
		}
	}
	
	return 0;
}


/**
 * \fn player int Fire_hum(player J);
 * \brief Demande au joueur ses coordonées de tir et les reporte dans la structure de J
 *
 * \param[in] J : structure player de celui sur lequel le joueur tire
 * \return renvoie le J modifié
 */
player Fire_hum(player J)
{
	int Yt = 0;
	char fauxgrec = 0;
	int Xt = 0;
	int fin=0;
	int stock = 0;
	J.touche = 0;
	
	while(fin==0)
	{
		printf("Entrez les coordonées de tir sous la forme [lettre][chiffre] \n\n");
		printf("> ");
		stock=0;
		Xt = 0;
		Yt = 0;
		
		do {stock=scanf(" %c%d",&fauxgrec,&Yt);}while(stock<2);		
		
		Xt=fauxgrec-'A';
		
		if(0<=Xt && Xt<=9)
		{
			if(0<=Yt && Yt<=9)
			{
				if(J.map[Xt][Yt]==1 || J.map[Xt][Yt]==2)
				{
					printf("Vous avez déjà tiré ici, tant pis pour vous.\n\n");
					fin  =1;
				}
				else
				{
					if(J.map[Xt][Yt] <= 7 && J.map[Xt][Yt] != 0)
					{
						J.touche = 1;
						
						J.map[Xt][Yt] = 2;
						
						printf("Touché !\n\n");
					}
					
					else
					{
						J.map[Xt][Yt] = 1;
						
						printf("plouf...\n\n");
					}
					
					fin = 1;
				}						
			}
			
			else
			{
				printf("Prière d'utiliser des lettres comprises entre A et J et des nombres compris entre 0 et 9.\n\n");
			}
		}
		
		else
		{
			printf("Prière d'utiliser des lettres comprises entre A et J et des nombres compris entre 0 et 9.\n\n");
		}
		
		J = Game_checker(J);
		
		printf("Appuyez sur n'importe quelle touche pour continuer.\n\n> ");
		getchar();getchar();
		
		}
		
		return J;
}







/**
 * \fn void Game_over(player J1, player J2);
 * \brief Affiche l'écran de game over, le gagnant et si le joueur veut rejouer.
 *
 * \param[in] J1 : structure player du premeir joueur
 * \param[in] J2 : structure player du deuxième joueur
 * \retun 1 s'il veut jouer encore, sinon 0
 */
int Game_over(player J1, player J2)
{
	char choix;
	char gagnant;
	if (J2.restants == 0)
	{
		gagnant = '1';
	}
	
	else
	{
		gagnant = '2';
	}
	
	system("clear");

	printf("\e[38;5;255m--------------------------------------------------------\n\n\n\n");
	printf("                        Game Over		          \n\n\n\n");
	printf("--------------------------------------------------------\n\n");
	if(J1.restants != J2.restants){printf("                 Le Joueur %c a gagné !           \n\n",gagnant);}
	else {printf("                       Egalité !           \n\n");}
	printf("--------------------------------------------------------\n");
	printf("                      A pour rejouer \n\n");
	printf("          n'importe quelle autre touche pour quitter    \n");
	printf("--------------------------------------------------------\n\n");
	printf(">");
	
	scanf("  %c",&choix);
	 
		 			
	if(choix=='A')
	 {
			return 1;
	 }
	 else{return 0;}
}










			
	
