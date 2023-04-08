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
        vector <Card> &cards;
        string lastTurn;
        string log;

        /*private methods - to initialize the game: */
        
        /*
        this method will initial the cards
        */
        void initCards();
        
        /*
        this method will shuffle the main deck of cards
        */
        void shuffleCards(vector <Card> &cards);

        /*
        this method will deal the deck of cards into 2 and give each player half of the deck
        */
        void dealCards(vector <Card> &cards);

        /*constructor: */
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
        void playAll(); //playes the game untill the end

        /*
        this method prints the name of the winning player
        */
        void printWiner(); // rints the name of the winning player

        /*
        this method prints all the turns played one line per turn
        */
        void printLog(); //prints all the turns played one line per turn

        /*
        this method prints basic statistics for each player
        */
        void printStats(); 
    };
}