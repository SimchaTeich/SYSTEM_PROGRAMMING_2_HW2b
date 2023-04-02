#ifndef CARD_HPP
#define CARD_HPP

#include <string>

#define ACE_VAL 1
#define PRINCE_VAL 11
#define QUEEN_VAL 12
#define KING_VAL 13

using std::string;



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
        void printCard() const;
    };
};

#endif // !CARD_HPP