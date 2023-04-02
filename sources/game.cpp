#include "game.hpp"
using ariel::Card;


ariel::Game::Game(Player& player1, Player& player2)
    : _player1(player1), _player2(player2)
{
    initCards();
    divideCardsToPlayers();
};


void ariel::Game::playTurn(){};
void ariel::Game::playAll(){};
void ariel::Game::printLastTurn() const {};
void ariel::Game::printLog() const{};
void ariel::Game::printWiner() const{};
void ariel::Game::printStats() const{};


//  helpers
void ariel::Game::initCards()
{
    for(int i = 1; i <= 13; i++)
    {
        this->_cardsStack.push(Card(i, "Spades"));
        this->_cardsStack.push(Card(i, "Clubs"));
        this->_cardsStack.push(Card(i, "Hearts"));
        this->_cardsStack.push(Card(i, "Diamonds"));
    }
};


void ariel::Game::divideCardsToPlayers()
{

};
//void Game::writeTurnLog(const Card& c1, const Card& c2){};
