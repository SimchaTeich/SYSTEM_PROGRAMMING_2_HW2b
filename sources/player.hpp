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
        int _cardesTaken;            // using for score

    public:
        /*
        The C'TOR.
        Input: string of the player name.
        */
        Player(const string& name);


        /*
        Updates the member _inPlay
        to be with True value.
        From now, the player CAN'T participant
        to other game, until the current game
        go to the end.
        Input: void
        Output: void
        */
        void startToPlay();


        /*
        Updates the member _inPlay
        to be with False value.
        From now, the player CAN participant
        to new game.
        Input: void
        Output: void
        */
        void endToPlay();


        /*
        Inserts a card into the _cardsStack.
        Input: const reference of Card.
        Output: void       
        */
        void insertCard(const Card& card);


        /*
        Remove the first Card from _cardsStack.
        Input: void
        Output: the first card (the head) in _cardsStack.
        */
        Card playCard();


        /*
        Updates about turn that last
        card from playCard was the winner.
        So, _cardsWasWin up with 1,
        and add the score to _cardesTaken.
        Input: integer value of score,
               actualy is the number of cards was taken
               int the last turn.
        Output: void
        */
        void winTurn(int score);

        // getters
        string name() const;
        bool inPlay() const;
        int stacksize() const;      // size of _cardsStack.
        int cardsWasWin() const;
        int cardesTaken() const;
    };
};

#endif // !PLAYER_HPP