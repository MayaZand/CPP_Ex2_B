#include "player.hpp"

using namespace ariel;

Player::Player(){} //default constructor

Player::Player (string name)  //constructor of Player class
{
    this->playerName = name;
}

int Player::stacksize() // returns the amount of cards left
{
    return 1;
}
   
int Player::cardesTaken() // returns the amount of cards this player has won
{
    return 1;
}
