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
        vector <Card> playersStack; //represents the stack of each player
    
        /*
        constructor:
        @param name is the name of the player.
        */
        Player(string name); 

        /*methods: */
        
        /*
        @return the name of the player
        */
        string getName();

        /*
        @return the amount of cards left to the player
        */
        int stacksize(); 
        
        /*
        @return the amount of cards this player has won
        */
        int cardesTaken(); 

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
