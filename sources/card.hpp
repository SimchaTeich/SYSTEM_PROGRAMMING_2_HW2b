#ifndef CARD_HPP
#define CARD_HPP

#include <string>

using std::string;

namespace ariel
{
    class Card
    {
    // private:
    //     int _value;
    //     string _color;
    //     string _type;
    //     string _specialName;

    public:
        Card(int value, const string& color);

        //int getValue() const;
        //void printCard() const;
    };
};

#endif // !CARD_HPP