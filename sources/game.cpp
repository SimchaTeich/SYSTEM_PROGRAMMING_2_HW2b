#include "game.hpp"


ariel::Game::Game(Player& player1, Player& player2)
    : _player1(player1), _player2(player2)
{};


void ariel::Game::playTurn(){};
void ariel::Game::playAll(){};
void ariel::Game::printLastTurn() const {};
void ariel::Game::printLog() const{};
void ariel::Game::printWiner() const{};
void ariel::Game::printStats() const{};


//  helpers
//void Game::initCards(){};
//void Game::divideCardsToPlayers(){};
//void Game::writeTurnLog(const Card& c1, const Card& c2){};
