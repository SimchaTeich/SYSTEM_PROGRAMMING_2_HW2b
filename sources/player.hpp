#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
//#include <queue>
//#include <stack>
//#include "card.hpp"

using std::string;
//using std::queue;
//using std::stack;

namespace ariel
{
    class Player
    {
    // private:
    //     string _name;
    //     queue<Card> _cardsStack;     // act like queue but call "stack"..
    //     queue<string> _cardsWasWin;
    //     queue<string> _cardWasDraw;
    //     int _cardesTaken;            // score

    public:
        Player(const string& name);
        //~Player();

        //void insertCard(const Card& card);
        //Card playCard();
        //void winTurn(int score, const string& card);  // append score to _cardesTaken
        //void drawTurn(const string& card);            // updates _cardWasDraw

        // getters
        //string name() const;
        int stacksize() const;
        int cardesTaken() const;
        //queue<string> cardsWasDraw() const;
        //queue<string> cartdWasWin() const;
    };
};

#endif // !PLAYER_HPP