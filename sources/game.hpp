#pragma once
#include <vector>
#include "player.hpp"
#include "card.hpp"


namespace ariel
{
    class Game
    {   
        /*fields - private by default: */
        Player &player1; 
        Player &player2; 
        vector <Card> cards;
        string lastTurn = "";
        string log = "";
        int numOfTurns = 0;
        int numOfDraws = 0;
        int p1_won = 0;
        int p2_won = 0;


        /*private methods - to initialize the game: */
        
        /*
        this method will initial the cards
        */
        void initCards();

        /*
        constructor (public):
        @param &player1 is the reference to the first player
        @param &player2 is the reference to the second player
        */
        public:
        Game (Player &player1, Player &player2);

        /*public methods: */

        /*
        this method will play one turn
        */
        void playTurn();

        /*
        this method will print the last turn stats
        */
        void printLastTurn ();

        /*
        this method will play the game untill the end
        */
        void playAll(); 

        /*
        this method prints the name of the winning player
        */
        void printWiner(); 

        /*
        this method prints all the turns played one line per turn
        */
        void printLog(); 

        /*
        this method prints basic statistics for each player
        */
        void printStats(); 
    };
}