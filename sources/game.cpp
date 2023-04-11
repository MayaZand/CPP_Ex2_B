#include "game.hpp"
#include "player.hpp"
#include <iostream>
#include <algorithm>
#include <random>
#include <cstdlib>
using namespace std;
using namespace ariel;

Game::Game(Player &player1, Player &player2) : player1(player1), player2(player2)
{
    if (player1.playerIsInGame() == true || player2.playerIsInGame() == true)
    {
        throw exception();
    }

    initCards();

    /*shuffeling the cards after initializing: */
    unsigned seed = (unsigned)time(NULL);
    auto rng = default_random_engine(seed);
    shuffle(cards.begin(), cards.end(), rng);

    /*dealing the deck of cards: */

    for (int i = 0; i < 26; i++)
    {
        player1.playersStack.push_back(cards.back());
        this->cards.pop_back();
        player2.playersStack.push_back(cards.back());
        this->cards.pop_back();
    }

    player1.updatePlayersStatus(true);
    player2.updatePlayersStatus(true);
}

void Game::initCards()
{
    for (int i = 1; i <= 13; i++)
    {
        Card card1(SPADES, (Value)i);
        Card card2(CLUBS, (Value)i);
        Card card3(HEARTS, (Value)i);
        Card card4(DIAMONDS, (Value)i);
        cards.push_back(card1);
        cards.push_back(card2);
        cards.push_back(card3);
        cards.push_back(card4);
    }
}

void Game::playTurn()
{
    if (this->numOfTurns >= 26)
    {
        throw logic_error("can't play more than 26 turns.");
    }

    if (&player1 == &player2)
    {
        throw logic_error("p1 and p2 can't be the same player.");
    }

    if (player1.stacksize() == 0 || player2.stacksize() == 0)
    {
        throw logic_error("can't play - player don't have cards.");
    }

    Card c1 = player1.playersStack.back(); // open a new card
    Card c2 = player2.playersStack.back(); // open a new card

    // For debugging purposes only
    // cout << "Stats:" << endl;
    // cout << "p1.cardesTaken() = " << player1.cardesTaken() << 
    // "; p1.stacksize() = " << player1.stacksize() << 
    // "; p2.cardesTaken() = " << player2.cardesTaken() << 
    // "; p2.stacksize() = " << player2.stacksize() << 
    // "; sum = " << (player1.cardesTaken() + player2.cardesTaken() + player1.stacksize() + player2.stacksize()) 
    // << endl;

    player1.playersStack.pop_back(); // removes this card from the deck of p1
    player2.playersStack.pop_back(); // removes this card from the deck of p2

    vector<Card> onTable;
    this->lastTurn = player1.getName() + " played " + c1.toString() + " and " +
                     player2.getName() + " played " + c2.toString();

    while (c1.cardCompare(c2) == 0) // option 1: draw
    {
        onTable.push_back(c1);
        onTable.push_back(c2);

        /*if no more cards left - deal the cards on table between the players:*/
        if (player1.stacksize() <= 2 || player2.stacksize() <= 2)
        {
            if (!onTable.empty())
            {
                player1.updateNumOfCardsTaken();
                onTable.pop_back();
                player2.updateNumOfCardsTaken();
                onTable.pop_back();
            }

            break;
        }

        this->lastTurn += "\ndraw - both players played:" + c1.toString() + "\n";

        onTable.push_back(player1.playersStack.back()); // put c1 on the table deck - upside down
        player1.playersStack.pop_back();                // get c1 out of player1 stack
        onTable.push_back(player2.playersStack.back()); // put c2 on the table deck - upside down
        player2.playersStack.pop_back();                // get c2 out of player2 stack

        // Pop new cards
        c1 = player1.playersStack.back();
        c2 = player2.playersStack.back();
        player1.playersStack.pop_back();
        player2.playersStack.pop_back();

        this->lastTurn += player1.getName() + " played " + c1.toString() + " and " + player2.getName() + " played " + c2.toString();

        this->numOfDraws++;
    }

    if (c1.cardCompare(c2) == 1) // option 2: player1 wins this turn
    {
        player1.updateNumOfCardsTaken();
        player1.updateNumOfCardsTaken(); // player1 will take the 2 cards

        if (!onTable.empty())
        {
            onTable.pop_back();
            player1.updateNumOfCardsTaken();
        }

        this->lastTurn += "-" + player1.getName() + " wins\n";

        this->p1_won++;
    }

    else if (c1.cardCompare(c2) == -1) // option 3: player2 wins this turn
    {
        player2.updateNumOfCardsTaken();
        player2.updateNumOfCardsTaken(); // player2 will take the 2 cards

        if (!onTable.empty())
        {
            onTable.pop_back();
            player2.updateNumOfCardsTaken();
        }

        this->lastTurn += "-" + player2.getName() + " wins\n";

        this->p2_won++;
    }

    this->log += this->lastTurn + "\n"; // at the end of each turn - update log
    this->numOfTurns++;
}

void Game::printLastTurn()
{
    cout << this->lastTurn << endl;
}

void Game::playAll()
{
    while (player1.stacksize() > 0 && player2.stacksize() > 0)
    {
        playTurn();
    }
    player1.updatePlayersStatus(false);
    player2.updatePlayersStatus(false);
}

void Game::printWiner()
{
    if (p1_won == 0 || p2_won == 0)
    {
        cout << " there is no winner yet! " << endl;
    }
    if (p1_won > p2_won)
    {
        cout << player1.getName() + " is the winner " << endl;
    }
    else if (p2_won > p1_won)
    {
        cout << player2.getName() + " is the winner " << endl;
    }
    else
        cout << " draw " << endl;
}

void Game::printLog()
{
    cout << this->log << endl;
}

void Game::printStats()
{
    cout << "Game Info: "
         << "\nplayer's name: " << player1.getName() << endl;
    cout << "Number of cards won: " << player1.cardesTaken() << endl;
    cout << "Number of cards left: " << player1.stacksize() << endl;

    cout << "\nplayer's name: " << player2.getName() << endl;
    cout << "Number of cards won: " << player2.cardesTaken() << endl;
    cout << "Number of cards left: " << player2.stacksize() << endl;

    cout << "\nTotal: " << to_string(numOfTurns) << " turns and " << to_string(numOfDraws) << " draws" << endl;
}
