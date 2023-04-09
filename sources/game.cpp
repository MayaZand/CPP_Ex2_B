#include "game.hpp"
#include "player.hpp"
#include <iostream>
using namespace std;
using namespace ariel;

Game::Game(Player &player1, Player &player2): player1(player1), player2(player2)
{
    
    
    if (player1.playerIsInGame()==true)
    {
        throw exception();
    }

    if (player2.playerIsInGame()==true)
    {
        throw exception();
    }
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
    while (cards.size()!=0)
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
}


void Game::playTurn()
{
    /*error checks: */
    if (&player1 == &player2)
    {
        throw logic_error("p1 and p2 cant be the same player.");
    }

    if(numOfTurns>=26)
    {
        throw logic_error("the game is over after 26 turns.");
    }

    Card c1 = player1.playersStack.back(); //open a new card
    Card c2 = player2.playersStack.back(); //open a new card

    player1.playersStack.pop_back(); //removes this card from the deck of p1
    player2.playersStack.pop_back(); //removes this card from the deck of p2

    if (c1.cardCompare(c2)== 1) //option 1: player1 wins this turn
    {
        player1.numOfCardsTaken++;
        player1.numOfCardsTaken++; //player1 will take 2 cards
      
        this->lastTurn += player1.getName() + "played" + c1.toString() + "and" +  
        player2.getName() + "played"  + c2.toString() + "." + "-p1 wins";

        this->p1_won++; 
        this->numOfTurns++;
    }
    
    if (c1.cardCompare(c2)== -1) //option 2: player2 wins this turn
    {
        player2.numOfCardsTaken++;
        player2.numOfCardsTaken++; //player2 will take 2 cards
      
        this->lastTurn += player1.getName() + "played" + c1.toString() + "and" +  
        player2.getName() + "played"  + c2.toString() + "." + "-p2 wins";

        this->p2_won++; 
        this->numOfTurns++;
    }
    
    vector <Card> onTable;
    while (c1.cardCompare(c2)==0) //option 3: same card
    {
        this->lastTurn += "tie - both players played:" + c1.toString();
        

        onTable.push_back(player1.playersStack.back()); //put c1 on the table deck
        player1.playersStack.pop_back(); //get c1 out of player1 stack
        onTable.push_back(player2.playersStack.back()); //put c2 on the table deck
        player2.playersStack.pop_back(); //get c2 out of player2 stack

        Card newCard1 = player1.playersStack.back(); //open a new card (upsideDown)
        Card newCard2 = player2.playersStack.back(); //open a new card (upsideDown)

        player1.playersStack.pop_back(); //removes this card from the deck of p1
        player2.playersStack.pop_back(); //removes this card from the deck of p2
        

    }
    
    this->log += this->lastTurn + "\n"; //at the ent of this turn - updates log





















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

