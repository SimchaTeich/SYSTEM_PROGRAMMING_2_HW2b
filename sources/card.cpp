#include "card.hpp"
#include <iostream>

using namespace ariel;
using std::cout;
using std::endl;


Card::Card(int value, const string& type)
{
    this->_value = value;
    this->_type = type;

    // init the special card name by value
    if(ACE_VAL ==  this->_value){ this->_specialName = "Ace"; }
    else if(PRINCE_VAL ==  this->_value){ this->_specialName = "Prince"; }
    else if(QUEEN_VAL ==  this->_value){ this->_specialName = "Queen"; }
    else if(KING_VAL ==  this->_value){ this->_specialName = "King"; }

    // init the card color by type
    if("Spades" == this->_type || "Clubs" == this->_type){ this->_color = "black"; }
    else if("Hearts" == this->_type || "Diamonds" == this->_type){ this->_color = "red"; }
};


int Card::getValue() const
{
    return this->_value;
};


string Card::cardString() const
{
    string ret = (this->_specialName != "" ? this->_specialName : std::to_string(this->_value));
    ret += (" of " + this->_type);
    return ret;
};


void Card::printCard() const
{
    cout << cardString() << endl;
};
