#ifndef CARD_HPP
#define CARD_HPP

#include <string>

using std::string;

constexpr int ACE_VAL = 1;
constexpr int PRINCE_VAL = 11;
constexpr int QUEEN_VAL = 12;
constexpr int KING_VAL = 13;


namespace ariel
{
    class Card
    {
     private:
         int _value;
         string _color;
         string _type;
         string _specialName;

    public:
        Card(int value, const string& type);

        int getValue() const;
        string cardString() const;
        void printCard() const;
    };
};

#endif // !CARD_HPP