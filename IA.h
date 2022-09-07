#ifndef IA_H
#define IA_H

#include "CORE.h"


/**
 * \fn player setup_batteaux(player IA);
 * \brief Place les batteaux aléatoirement
 *
 * \param[in] IA : structure player de l'IA
 * \return renvoie la struct de l'IA modifié
 */
player setup_batteaux(player IA);



/**
 * \fn transfer Fire_IA(player J1, player J2)
 * \brief Demande à l'IA ses coordonées de tir et les reporte dans la structure de J et stocke dans l'IA des informations nécessaire au choxi des coordonées de tir
 *
 * \param[in] J1 : structure player de celui sur lequel l'IA tire
 * \param[in] J2 : structure player de l'IA
 * \return renvoie une structure transfer contenant les deux structures
 */
transfer Fire_IA(player J1, player J2);









































#endif
