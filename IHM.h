#ifndef IHM_H
#define IHM_H

#include "CORE.h"



/**
 * \fn int press start(void)
 * \brief Ecran d'acceuil du jeu
 *
 * \param[in] none
 * \return 0 si le joueur veut jouer, sinon 1
 */
int press_start(void);


/**
 * \fn affiche_tableaux(player J1,player J2)
 * \brief Affiche les tableaux des joueurs J1 et une partie de J2
 *
 * \param[in] J1 : structure player du premeir joueur
 * \param[in] J2 : structure player du deuxième joueur
 * \return void
 */
void affiche_tableaux(player J1,player J2);


/**
 * \fn affiche_tableaux_spoiled(player J1,player J2)
 * \brief Affiche les tableaux des joueurs J1 et J2 au complet
 *
 * \param[in] J1 : structure player du premeir joueur
 * \param[in] J2 : structure player du deuxième joueur
 * \return void
 */
void affiche_tableaux_spoiled(player J1,player J2);

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
int InterCoordBateau(int Xa, int Ya, int Xb, int Yb, int hum);






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
int CheckValueCoord(int Xa,int Ya,int Xb,int Yb);





/**
 * \fn player RecupCoordBateau(player J1, player IA);
 * \brief Demande les coordonées de ses batteaux au joueur et les stocke dans sa flotte et le tableau
 *
 * \param[in] J1 : structure player du premeir joueur
 * \param[in] IA : structure player de l'IA
 * \return renvoie le J1 modifié
 */
player RecupCoordBateau(player J1, player IA);






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
int TailleBateau(int Xa, int Ya, int Xb, int Yb, int Horizontal);





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
int Superpo_bat(int Xa, int Ya, int Xb, int Yb, int Horizontal, int cpt, player J1);




/**
 * \fn player Fire_hum(player J);
 * \brief Demande au joueur ses coordonées de tir et les reporte dans la structure de J
 *
 * \param[in] J : structure player de celui sur lequel le joueur tire
 * \return renvoie le J modifié
 */
player Fire_hum(player J);


/**
 * \fn void Game_over(player J1, player J2);
 * \brief Affiche l'écran de game over, le gagnant et si le joueur veut rejouer.
 *
 * \param[in] J1 : structure player du premeir joueur
 * \param[in] J2 : structure player du deuxième joueur
 * \return 1 s'il veut jouer encore, sinon 0
 */
int Game_over(player J1, player J2);


#endif
