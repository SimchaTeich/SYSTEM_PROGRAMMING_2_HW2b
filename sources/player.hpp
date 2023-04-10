#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <stack>
#include "card.hpp"

using std::string;
using std::stack;


namespace ariel
{
    class Player
    {
    private:
        string _name;
        bool _inPlay;
        stack<Card> _cardsStack;
        int _cardsWasWin;
        int _cardesTaken;            // score

    public:
        Player(const string& name);

        void startToPlay();
        void endToPlay();
        void insertCard(const Card& card);
        Card playCard();
        void winTurn(int score);    // append score to _cardesTaken and add 1 to _cardsWasWin 

        // getters
        string name() const;
        bool inPlay() const;
        int stacksize() const;
        int cardsWasWin() const;
        int cardesTaken() const;
    };
};

#endif // !PLAYER_HPP