#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <stack>
#include <queue>
#include "player.hpp"
#include "card.hpp"

using std::string;
using std::stack;
using std::queue;

namespace ariel
{
    class Game
    {
    private:
        Player _player1;
        Player _player2;
        stack<Card> _cardsStack;
        int _turnNum;               // turns counter
        bool _gameIsOver;
        int _winner;               // 0, 1 or 2.
        queue<string> _logOfTurns;

        void initCards();
        void createAllCards();
        void divideCardsToPlayers();
        void writeTurnLog(string newLog);

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