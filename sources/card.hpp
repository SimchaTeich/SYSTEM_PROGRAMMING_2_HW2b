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
        /*
        The C'TOR.
        Input: value from 1 to 13,
               string type ("Spades", "Clubs",
               "Hearts" or "Diamonds")
        */
        Card(int value, const string& type);


        /*
        Return the value of the card.
        Posible value is from 1 to 13.
        Input: void
        Output: the integer value as exaplain abouv.
        */
        int getValue() const;


        /*
        Make a string format of the card,
        and returns it.
        Example 1: "8 of Spades"
        Example 2: "King of Diamonds"
        Example 3: "Ace of Hearts"
        Input: void
        Output: the string as exaplain abouv
        */
        string cardString() const;


        /*
        Just printing the card in format of
        function cardString.
        Input: void
        Output: void
        */
        void printCard() const;
    };
};

#endif // !CARD_HPP