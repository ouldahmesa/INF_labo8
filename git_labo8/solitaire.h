/*
 -----------------------------------------------------------------------------------
 Laboratoire : 08
 Fichier     : solitaire.h
 Auteur(s)   : Sami Ould Ahmed, André Marques Nora
 Date        : 17.12.2019

 But         : Création du jeu le solitaire dans sa version à 32 billes
          
 Remarque(s) : Aucune.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef SOLITAIRE_H
#define SOLITAIRE_H
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <vector>
#include <stdlib.h>

   void showInterface();
   void initializePlate();
   bool getPossibleMooves();
   void doTheMoove(std::string userEntry, int direction);
   void endGame();
   void gameIntelligence();

#endif

