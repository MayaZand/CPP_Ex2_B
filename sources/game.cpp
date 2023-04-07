#include "game.hpp"
using namespace ariel;

Game::Game (Player player1, Player player2) //constructor of Player class
{
    this->player1 = player1;
    this->player2 = player2;
}
void Game::playTurn(){}

void Game::printLastTurn (){}

void Game::playAll(){} //playes the game untill the end

void Game::printWiner(){} // prints the name of the winning player

void Game::printLog(){} // prints all the turns played one line per turn

void Game::printStats(){} // for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )

