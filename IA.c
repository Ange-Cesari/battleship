#include "IA.h"
#include "CORE.h"
#include "IHM.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"



/**
 * \fn player setup_batteaux(player IA);
 * \brief Place les batteaux aléatoirement
 *
 * \param[in] IA : structure player de l'IA
 * \return renvoie la struct de l'IA modifié
 */
player setup_batteaux(player IA)
{
	int cpt=0;
	int checked = 0;
	int fin=0;
	int Xa;
	int Xb;
	int Ya;
	int Yb;
	int Horizontal;

		while (cpt<5)
		{
			fin = 0;
			
			while(fin==0)
			{
				Xa = myrand(0,9);
				Ya = myrand(0,9);
				
				
				
				if (IA.map[Xa][Ya] == 0)
				{
					int a = myrand(1,4);
					
					if (a==1){Xb = Xa+1+IA.flotte[cpt].longueur; Yb = Ya;}
					
					else if (a==2){Xb = Xa+1-IA.flotte[cpt].longueur; Yb = Ya;}
					
					else if (a==3){Xb = Xa; Yb = Ya-1+IA.flotte[cpt].longueur;}
					
					else if (a==4){Xb = Xa; Yb = Ya-1-IA.flotte[cpt].longueur;}
					
					checked=CheckValueCoord(Xa,Ya,Xb,Yb);

					if (checked==4)
					{
						int var=InterCoordBateau(Xa,Ya,Xb,Yb,0);
						
						if(var==1)
						{
							Horizontal=0;				
						}

						else if (var == 2)
						{
							Horizontal=1;						
						}
				
						if (Superpo_bat(Xa, Ya, Xb, Yb, Horizontal, cpt, IA)==0 && TailleBateau(Xa,Ya,Xb,Yb,Horizontal) == IA.flotte[cpt].longueur)
						{
							IA = Placeur_bat(Xa, Ya, Xb, Yb, Horizontal, cpt, IA);
							fin=1;
							cpt++;
						}					
					}			
				}	
			}
		}
	
		
		return IA;
}






/**
 * \fn transfer Fire_IA(player J1, player J2)
 * \brief Demande à l'IA ses coordonées de tir et les reporte dans la structure de J et stocke dans l'IA des informations nécessaire au choxi des coordonées de tir
 *
 * \param[in] J1 : structure player de celui sur lequel l'IA tire
 * \param[in] J2 : structure player de l'IA
 * \return renvoie une structure transfer contenant les deux structures
 */
transfer Fire_IA(player J1, player J2)
{
	transfer returner;
	
	if(J2.IA.lastrest != J1.restants)
		{
			J2.IA.mode = 0;
			J2.IA.lastrest = J1.restants;
		}
	
	if (J2.IA.mode == 0) //Seek
	{
		int fin = 0;
		int Xa = 0;
		int Ya = 0;		
		
		while (fin == 0)
		{
			Xa = myrand(0,9);
			Ya = myrand(0,9);
			
			if ((Xa+Ya)%2 == 1 && J1.map[Ya][Xa] != 1 && J1.map[Ya][Xa] != 2)
			{
				if (J1.map[Ya][Xa] >2 && J1.map[Ya][Xa] <8)
				{
					J2.IA.mode = 1;
					J2.IA.target[1] = Xa;
					J2.IA.target[0] = Ya;
					J2.IA.pas = 0;
					J2.IA.sens = 0;
					J1.map[Ya][Xa] = 2;
					fin = 1;
				}
				
				else
				{
					J1.map[Ya][Xa] = 1;
					fin = 1;
				}
			}
		}
	}
	
	else //Destroy
	{
		int fin = 0;
		J2.IA.pas++;
		
		while (fin == 0)
		{
			
			switch (J2.IA.sens)
			{
				case 0 : 
					if((J2.IA.target[1] + J2.IA.pas) > 9)
					{
						J2.IA.sens++;
						J2.IA.pas = 0;
					}					
					else if(J1.map[J2.IA.target[0]][J2.IA.target[1]+J2.IA.pas] == 1)
					{
						J2.IA.pas++;
					}					
					else if(J1.map[J2.IA.target[0]][J2.IA.target[1]+J2.IA.pas] == 2)
					{
						J2.IA.pas++;
					}
					else if(J1.map[J2.IA.target[0]][J2.IA.target[1]+J2.IA.pas] == 0)
					{
						fin = 1;
						J1.map[J2.IA.target[0]][J2.IA.target[1]+J2.IA.pas] = 1;
						J2.IA.pas = 0;
						J2.IA.sens++;						
					}
					else if (J1.map[J2.IA.target[0]][J2.IA.target[1]+J2.IA.pas] <8)
					{
						fin = 1;
						J1.map[J2.IA.target[0]][J2.IA.target[1]+J2.IA.pas] = 2;
					}
					break;
			
				case 1 : 
					if((J2.IA.target[1] - J2.IA.pas) < 0)
					{
						J2.IA.sens++;
						J2.IA.pas = 0;
					}
					else if(J1.map[J2.IA.target[0]][J2.IA.target[1]-J2.IA.pas] == 1)
					{
						J2.IA.pas++;
					}
					else if(J1.map[J2.IA.target[0]][J2.IA.target[1]-J2.IA.pas] == 2)
					{
						J2.IA.pas++;
					}
					else if(J1.map[J2.IA.target[0]][J2.IA.target[1]-J2.IA.pas] == 0)
					{
						fin = 1;
						J1.map[J2.IA.target[0]][J2.IA.target[1]-J2.IA.pas] = 1;
						J2.IA.pas = 0;
						J2.IA.sens++;						
					}
					else if (J1.map[J2.IA.target[0]][J2.IA.target[1]-J2.IA.pas] <8)
					{
						fin = 1;
						J1.map[J2.IA.target[0]][J2.IA.target[1]-J2.IA.pas] = 2;
					}
					break;
			
				case 2 : 
					if((J2.IA.target[0] + J2.IA.pas) > 9)
					{
						J2.IA.sens++;
						J2.IA.pas = 0;
					}
					else if(J1.map[J2.IA.target[0]+J2.IA.pas][J2.IA.target[1]] == 1)
					{
						J2.IA.pas++;
					}										
					else if(J1.map[J2.IA.target[0]+J2.IA.pas][J2.IA.target[1]] == 2)
					{
						J2.IA.pas++;
					}
					else if(J1.map[J2.IA.target[0]+J2.IA.pas][J2.IA.target[1]] == 0)
					{
						fin = 1;
						J1.map[J2.IA.target[0]+J2.IA.pas][J2.IA.target[1]] = 1;
						J2.IA.pas = 0;
						J2.IA.sens++;						
					}
					else if (J1.map[J2.IA.target[0]+J2.IA.pas][J2.IA.target[1]] <8)
					{
						fin = 1;
						J1.map[J2.IA.target[0]+J2.IA.pas][J2.IA.target[1]] = 2;
					}
					break;
			
				case 3 : 
					if((J2.IA.target[0] - J2.IA.pas) < 0)
					{
						J2.IA.mode = 0;
						J2.IA.sens=0;
						J2.IA.pas = 0;
						fin = 1;
					}
					else if(J1.map[J2.IA.target[0]-J2.IA.pas][J2.IA.target[1]] == 1)
					{
						J2.IA.pas++;
					}										
					else if(J1.map[J2.IA.target[0]-J2.IA.pas][J2.IA.target[1]] == 2)
					{
						J2.IA.pas++;
					}
					else if(J1.map[J2.IA.target[0]-J2.IA.pas][J2.IA.target[1]] == 0)
					{
						fin = 1;
						J1.map[J2.IA.target[0]-J2.IA.pas][J2.IA.target[1]] = 1;
						J2.IA.pas = 0;
						J2.IA.sens=0;						
					}
					else if (J1.map[J2.IA.target[0]-J2.IA.pas][J2.IA.target[1]] <8)
					{
						fin = 1;
						J1.map[J2.IA.target[0]-J2.IA.pas][J2.IA.target[1]] = 2;
					}
					break;
			
				default :
					break;
			}
		}
		
	}
	
	returner.J1 = J1;
	returner.J2 = J2;
	
	return returner;
}






























