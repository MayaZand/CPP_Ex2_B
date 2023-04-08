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


void Player::updateCardsTaken()
{
    
}

void Player::updatePlayersStack()
{
    //playersStack.pop_back();
}

bool Player::playerIsInGame()
{
    return this->isInGame;
}

void Player::updatePlayersStatus(bool status)
{
    this->isInGame = status;
}



