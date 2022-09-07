#ifndef CORE_H
#define CORE_H

//Structure stockant les informations d'un bateau
struct BATO {
	
	int longueur; //Longueur du bateau
	int ID; //ID du bateau sur la carte
	int state; //Etat du bateau (vivant, mort)
	
	};
	
typedef struct BATO bateau; //Création du type des bateaux

//Structure stockant les informations utiles à l'IA
struct ROBOT {

	int mode; //0 si Seek et 1 si Destroy
	int target[2]; //Stocke le y et x du premier touché de destroy
	int pas; //distance entre la cible du destroy et target
	int sens; //Sens de tir du destroy
	int lastrest;// Dernier restants du joueur adverse
	
	};

typedef struct ROBOT robot;
	
	
//Structure stockant les informations d'un joueur
struct PLAYER {
	
	int map[10][10]; //Carte du joueur
	bateau flotte[5]; //Liste de structures bateau pour stocker sa flotte de batteaux
	int restants; //Stocke le nombre de batteaux qu'il lui retse
	int touche; //égal à 1 s'il a été touché ce tour
	robot IA;//Spécifique à l'IA, stocke les informations dont elle a besoin
	};
	
typedef struct PLAYER player; //Création du type Player

//Creation d'une structure contenant deux players
struct TRANSFER {

	player J1;//Joueur 1
	player J2;//joueur 2
	
	};
	
typedef struct TRANSFER transfer;



/**
 * \fn player setup_player(void)
 * \brief Initialise les informations d'un player
 *
 * \param[in] void
 * \return la structure initialisée
 */
player setup_player(void);



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
player Placeur_bat(int Xa, int Ya, int Xb, int Yb, int Horizontal, int cpt, player J1);



	
	

/**
 * \fn int myrand(int inf, int sup);
 * \brief Donne un int entre les borns inférieures et supérieures
 *
 * \param[in] inf : borne inférieure
 * \param[in] isup : borne supérieure
 * \return un int aléatoire entre les deux
 */
int myrand(int inf, int sup);






/**
 * \fn player Game_checker(player J);
 * \brief Actualise l'état des batteaux du joueur et le nombre de ses batteaux restants
 *
 * \param[in] J : Joueur étudié
 * \return la version actualisée de J
 */
player Game_checker(player J);

















#endif
