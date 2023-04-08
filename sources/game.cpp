#include "game.hpp"
#include "player.hpp"
using namespace ariel;

Game::Game(Player &player1, Player &player2) 
{
    this->player1 = player1;
    this->player2 = player2;
    initCards();
    shuffleCards(cards);
    dealCards(cards);
    player1.updatePlayersStatus(true);
    player2.updatePlayersStatus(true);
}

void Game::initCards()                  
{
    for(int i=1; i<=13; i++)
    {
        Card card1 (SPADES, (Value)i);
        Card card2 (CLUBS, (Value)i);
        Card card3 (HEARTS, (Value) i);
        Card card4 (DIAMONDS, (Value) i);
        cards.push_back(card1);
        cards.push_back(card2);
        cards.push_back(card3);
        cards.push_back(card4);
    }
}
        

void Game::shuffleCards(vector <Card> &cards)
{
    random_shuffle(cards.begin(), cards.end());
}

void Game::dealCards(vector <Card> &cards)
{
    for(int i=0; i<cards.size()/2; i++)
    {
        player1.playersStack.push_back(cards.back());
        cards.pop_back();
    }
    
    for (int j=cards.size()/2; j<cards.size(); j++)
    {
        player2.playersStack.push_back(cards.back());
        cards.pop_back();
    }
}


void Game::playTurn()
{

}

void Game::printLastTurn ()
{

}

void Game::playAll()
{

}

void Game::printWiner()
{

}

void Game::printLog()
{

}

void Game::printStats()
{

}

