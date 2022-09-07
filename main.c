#include "CORE.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "unistd.h"
#include "IHM.h"
#include "IA.h"
#include "time.h"


int main(void)
{
	int fin = 0;
	int stock = 0;
	srand(time(NULL));
	transfer trans;
	player J1;
	player IA;
	
	while (fin == 0)
	{
		stock = 0;
		
		switch(press_start())
		{
			case 0 :
				return 0;
				break;
			
			case 1 :
				J1 = setup_player();
				IA = setup_player();
	
				J1 = RecupCoordBateau(J1, IA);	
				IA = setup_batteaux(IA);
	
				while(J1.restants != 0 && IA.restants != 0)
				{	
					affiche_tableaux(J1,IA);
	
					IA = Fire_hum(IA);
	
					trans = Fire_IA(J1, IA); J1 = trans.J1; IA = trans.J2;
		
					J1 = Game_checker(J1);
				}
	
				if(Game_over(J1,IA) == 0){fin = 1;}
				break;
			
			case 2 :
				J1 = setup_player();
				IA = setup_player();
	
				J1 = setup_batteaux(J1);	
				IA = setup_batteaux(IA);
	
				while(J1.restants != 0 && IA.restants != 0)
				{	
					
			
					trans = Fire_IA(IA, J1); IA = trans.J1; J1 = trans.J2;
	
					trans = Fire_IA(J1, IA); J1 = trans.J1; IA = trans.J2;
					
					affiche_tableaux_spoiled(J1,IA);					
		
					J1 = Game_checker(J1);
			
					IA = Game_checker(IA);
					
					printf("Tour %d.\n\n", stock++);
					
					sleep(1);
				}
	
				if(Game_over(J1,IA) == 0){fin = 1;}
				break;
			
			case 3 :
				J1 = setup_player();
				IA = setup_player();
	
				J1 = setup_batteaux(J1);	
				IA = setup_batteaux(IA);
	
				while(J1.restants != 0 && IA.restants != 0)
				{	
					affiche_tableaux_spoiled(J1,IA);
	
					IA = Fire_hum(IA);
	
					trans = Fire_IA(J1, IA); J1 = trans.J1; IA = trans.J2;
		
					J1 = Game_checker(J1);
				}
	
				if(Game_over(J1,IA) == 0){fin = 1;}
				break;
				
			default :
				J1 = setup_player();
				IA = setup_player();
	
				J1 = setup_batteaux(J1);	
				IA = setup_batteaux(IA);
	
				while(J1.restants != 0 && IA.restants != 0)
				{	
					affiche_tableaux(J1,IA);
	
					IA = Fire_hum(IA);
	
					trans = Fire_IA(J1, IA); J1 = trans.J1; IA = trans.J2;
		
					J1 = Game_checker(J1);
				}
	
				if(Game_over(J1,IA) == 0){fin = 1;}
				break;
		}
	}
										
	return 0;
}
 		
