#include "player.hpp"

using namespace ariel;

Player::Player (string name)  
{
    this->playerName = name;
}

int Player::stacksize() 
{
    return this->playersStack.size();
}
   
int Player::cardesTaken() 
{
    return this->numOfCardsTaken;
}

string Player::getName()
{
    return playerName;
}

bool Player::playerIsInGame()
{
    return this->isInGame;
}

void Player::updatePlayersStatus(bool status)
{
    this->isInGame = status;
}

void Player::updateNumOfCardsTaken()
{
    this->numOfCardsTaken++;
}



