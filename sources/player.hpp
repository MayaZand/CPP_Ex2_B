#pragma once
#include "card.hpp"
#include <string>
#include <vector>
using namespace std;

namespace ariel
{
    class Player
    {
        /*fields: */
        public:
        string playerName; 
        int numOfCardsTaken; 
        bool isInGame = false;
        vector <Card> playersStack;
    
        /*constructor*/
        Player(string name); 

        /*getters & setters*/
        string getName();

        /*methods*/
        
        /*
        @return the amount of cards left
        */
        int stacksize(); 
        
        /*
        @return the amount of cards this player has won
        */
        int cardesTaken(); 

        /*
        this method will update the number of cards that the player took
        */
        void updateCardsTaken();

        /*
        this method will update the deck of cards 
        */
        void updatePlayersStack();

        /*
        @return true if this player is already playing, and false otherwise
        */
        bool playerIsInGame();

        /*
        this method will update the status of each player when he joins or leaves the game
        */
        void updatePlayersStatus(bool status);



    };
}
