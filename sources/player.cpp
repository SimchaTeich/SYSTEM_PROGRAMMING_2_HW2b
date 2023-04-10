#include "player.hpp"
#include <iostream>

using namespace ariel;

Player::Player(const string& name)
{
    if(name == "")
    {
        throw "Error: can't create player with no name..";
    }
    
    this->_name = name;
    this->_inPlay = false;
    this->_cardsWasWin = 0;
    this->_cardesTaken = 0;
};


void Player::startToPlay()
{
    this->_inPlay = true;
}


void Player::endToPlay()
{
    this->_inPlay = false;
}


void Player::insertCard(const Card& card)
{
    this->_cardsStack.push(card);
};


Card Player::playCard()
{
    Card curr = this->_cardsStack.top();
    this->_cardsStack.pop();

    return curr;
};


void Player::winTurn(int score)
{
    this->_cardesTaken += score;
    this->_cardsWasWin++;
};


string Player::name() const
{
    return this->_name;
};


bool Player::inPlay() const
{
    return this->_inPlay;
}


int Player::stacksize() const
{
    return this->_cardsStack.size();
};


int Player::cardsWasWin() const
{
    return this->_cardsWasWin;
};


int Player::cardesTaken() const
{
    return this->_cardesTaken;
}
