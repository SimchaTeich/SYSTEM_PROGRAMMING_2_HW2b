#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <vector>
#include "player.hpp"
#include "card.hpp"

using std::string;
using std::vector;


namespace ariel
{
    class Game
    {
    private:
        Player& _player1;
        Player& _player2;
        vector<Card> _cardsStack;
        int _turnNum;              // turns counter
        string _turnWinner;
        bool _gameIsOver;
        vector<string> _logOfTurns;

        void initCards();
        void divideCardsToPlayers();
        string checkTurnWinner(const int& value1, const int& value2) const;
        void givePointsForCurrWinner(); // based on _turnWinner

    public:
        Game(Player& player1, Player& player2);

        void playTurn();
        void playAll();
        void printLastTurn() const;
        void printLog() const;
        void printWiner() const;
        void printStats() const;
    };
};

#endif // !GAME_HPP