/*
 -----------------------------------------------------------------------------------
 Laboratoire : 08
 Fichier     : solitaire.cpp
 Auteur(s)   : Sami Ould Ahmed, André Marques Nora
 Date        : 17.12.2019

 But         : Création du jeu le solitaire dans sa version à 32 billes
          
 Remarque(s) : Aucune.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include "solitaire.h"
//#include <cstdlib>
//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <array>
//#include <vector>
//#include <stdlib.h>

using namespace std;
// GESTION DU JEU
array<char, 4> Moove{ 'r','l','u','d' };
enum possibleStatus { unusable, emptycell, position };
string userEntry;
vector<string> possibleMooves;
//Plateau de 9 par 9 -> 81 cellules possible -> taill 80 car il y a la position 0
array<possibleStatus, 80> plate;

// AFFICHAGE
void showInterface() {
   system("CLS");

   for (size_t i = 0; i < plate.size(); i++){
      
      switch (plate.at(i)){
		
         case unusable: cout << string(4, ' '); break;	
         case emptycell: cout << " .. "; break;	
         case position: cout << ' ' << i << ' '; break;
      
      }
		
      if (i % 10 == 9) {
			
         cout << endl;
		
      }
	
   }
}


void initializePlate() {
	
   for (size_t i = 0; i < plate.size(); i++) {
		
      if (i != 44) {
			
         if (i / 3 < 10 || i / 3 > 19 || i % 10 == 0 || i % 10 > 7) {
				
            if (i % 10 < 3 || i % 10 > 5 || i < 10) {
					
               plate.at(i) = unusable;
				
            }
				
            else {
					
               plate.at(i) = position;
				
            }
			
         }
			
         else {
				
            plate.at(i) = position;
			
         }
		
      }
		
      else {
			
         plate.at(i) = emptycell;
		
      }
	
   }
	
   showInterface();
}

bool getPossibleMooves() {
	
   string eachPossibleMoove = "";
   possibleMooves.clear();
	
   for (size_t i = 0; i < plate.size(); i++) {
		
      if (plate.at(i) == emptycell) {
			
         if (i - 2 > 0 && plate.at(i - 1) == position && plate.at(i - 2) == position) {
				
            eachPossibleMoove += 'r';				
            eachPossibleMoove += to_string(i - 2);
				
            if (eachPossibleMoove != "") {
					
               possibleMooves.push_back(eachPossibleMoove);					
               eachPossibleMoove = "";
				
            }

			
         } 
         
         if (i + 2 < 81 && plate.at(i + 1) == position && plate.at(i + 2) == position) {
				
            eachPossibleMoove += 'l';				
            eachPossibleMoove += to_string(i + 2);
				
            if (eachPossibleMoove != "") {
					
               possibleMooves.push_back(eachPossibleMoove);					
               eachPossibleMoove = "";
				
            }
			
         } 
         if (i - 20 > 0 && plate.at(i - 10) == position && plate.at(i - 20) == position) {
				
            eachPossibleMoove += 'd';
            eachPossibleMoove += to_string(i - 20);
				
            if (eachPossibleMoove != "") {
					
               possibleMooves.push_back(eachPossibleMoove);
               eachPossibleMoove = "";
				
            }
			
         }
         if (i + 20 < 81 && plate.at(i + 10) == position && plate.at(i + 20) == position) {
				
            eachPossibleMoove += 'u';
            eachPossibleMoove += to_string(i + 20);
	
            if (eachPossibleMoove != "") {
	
               possibleMooves.push_back(eachPossibleMoove);
               eachPossibleMoove = "";
		
            }
	
         }
	
      }
	
   }

   if (possibleMooves.size() > 0) {

      return true;
	
   }

   else { return false; }
   
}

void doTheMoove(string userEntry, int direction) {
	
   if (find(possibleMooves.begin(), possibleMooves.end(), userEntry) != possibleMooves.end()) {

      int position = stoi(userEntry.substr(1, 2));
      swap(plate[position], plate[position + direction]);
      plate.at(position + direction / 2) = emptycell;
      showInterface();

   }

   else { cout << "nope"; };

}

void endGame() {

   int ballLeft = count(plate.begin(), plate.end(), position);

   if (ballLeft > 5) {

      cout << "Vous pouvez faire mieux, il reste " << ballLeft << " billes" ;
	
   }

   else if (ballLeft > 1) {

      cout << "Pas mal, il ne reste que " << ballLeft << " billes ";
	
   }

   else if (plate.at(44) != position) {

      cout << "Bravo, vous avez gagne avec une seule bille restante.Au centre ce serait parfait";
	
   }

   else {

      cout << "Parfait, il ne reste qu'une bille au centre";
	
   }
}

void gameIntelligence() {
	
   int i = 0;			

   vector<string> win = { "l46", "u65", "l57", "r54", "d37", "l57", "d34", "r54", "r63", "u75", "r73", "d45", "u75", "l56", "l36", "d15", "r34", "r13", "r23", "d15", "l36", "u43", "r31", "u51", "l34", "r31", "d23", "r42"/*, "d44", "r52", "u64"*/ };


   while (userEntry != "q" && getPossibleMooves()) {

      string userEntry;
	
      if (i > 25) { cin >> userEntry; } else{ userEntry = win.at(i++); }
		
      switch (userEntry.at(0)) {
	
         case 'h': for (auto possibleMove : possibleMooves) { cout << possibleMove << ", "; }; cout << endl; break;	
         case 'd': doTheMoove(userEntry, 20); break;	
         case 'u': doTheMoove(userEntry, -20); break;	
         case 'l': doTheMoove(userEntry, -2); break;	
         case 'r': doTheMoove(userEntry, 2); break;
         default: cout << "whut" << endl;
		
      }
		
	
   };
	
	
   endGame();

}