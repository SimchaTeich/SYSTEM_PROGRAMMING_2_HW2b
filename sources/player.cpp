#include "player.hpp"
//#include <exception>


ariel::Player::Player(const string& name)
{
    if(name == "")
    {
        throw "Error: can't create player with no name..";
    }
    
    this->_name = name;
    this->_inPlay = false;
    this->_cardsWasWin = 0;
    this->_cardsWasDraw = 0;
    this->_cardesTaken = 0;
};


void ariel::Player::insertCard(const Card& card)
{
    this->_inPlay = true;
    this->_cardsStack.push(card);
};


ariel::Card ariel::Player::playCard()
{
    ariel::Card curr = this->_cardsStack.top();
    this->_cardsStack.pop();
    if(this->_cardsStack.empty()) { this->_inPlay = false; }

    return curr;
};


void ariel::Player::winTurn(int score)
{
    this->_cardesTaken += score;
    this->_cardsWasWin++;
};


void ariel::Player::drawTurn(int score)
{
    this->_cardesTaken += score;
    this->_cardsWasDraw++;
};


string ariel::Player::name() const
{
    return this->_name;
};


bool ariel::Player::inPlay() const
{
    return this->_inPlay;
}


int ariel::Player::stacksize() const
{
    return this->_cardsStack.size();
};


int ariel::Player::cardsWasWin() const
{
    return this->_cardsWasWin;
};


int ariel::Player::cardsWasDraw() const
{
    return this->_cardsWasDraw;
};


int ariel::Player::cardesTaken() const
{
    return this->_cardesTaken;
}
