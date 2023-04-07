#pragma once
#include <vector>
#include "player.hpp"
#include "card.hpp"

namespace ariel
{
    class Game
    {   
        Player player1; //private by default
        Player player2; //private by default
        vector <Card> cards; //vector that holds the cards

        public:
        Game (Player player1, Player player2); //constructor of Game class
    
        void playTurn();
    
        void printLastTurn ();

        void playAll(); //playes the game untill the end
    
        void printWiner(); // rints the name of the winning player
   
        void printLog(); //prints all the turns played one line per turn

        void printStats(); //for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
    };
}