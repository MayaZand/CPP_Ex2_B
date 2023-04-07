#pragma once
#include <string>
using namespace std;

namespace ariel
{
    class Player
    {
    
        string playerName; //private by default
    
        public:
        Player(); //default constructor
    
        Player(string name); //constructor of Player class
    
        int stacksize(); //returns the amount of cards left

        int cardesTaken(); //returns the amount of cards this player has won
    };
}
