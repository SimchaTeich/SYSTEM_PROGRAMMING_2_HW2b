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
        int _numOfDraws;
        bool _gameIsOver;
        vector<string> _logOfTurns;


        /*
        Creates a deck of normal war cards, size 52.
        All cards save inside the _cardsStack.
        Function works exactly one time in game, before it begin.
        Input: void
        Ouput: void
        */
        void initCards();


        /*
        Function works one time immidiately after initCards function.
        All Cards in _cardsStack will shuffle and than
        divides equaly and inserted to each player.
        Input: void
        Output: void
        */
        void divideCardsToPlayers();


        /*
        Check witch player is the winner in turn,
        according to values of cards was play.
        Note: 2 wins Ace(=1), but Ace wins all the others.
        Input: two const references to card values.
               value1 and value2 for _player1 and player2 respectively.
        Output: string with name of player was win right now, or "Draw"
        */
        string checkTurnWinner(const int& value1, const int& value2) const;


        /*
        Append log into variable turnLog (from outside scope)
        with specifig contest.
        Input: turnLog for change it, cards strings and the name of the winner in last turn.
        Output: void
        */
        void updateTurnLog(string& turnLog, const string& cardStr1, const string& cardStr2, const string& turnWinner) const;
        
        
        /*
        Gives points of lats turn to the winner of the turn.
        Note: if currWinner is "Draw", every player gets
              half of __cardsStack size as score.
        Input: string of last-turn-winner name.
        Output: void.
        */
        void givePointsForCurrWinner(const string& currWinner);

    public:
        /*
        The C'TOR.
        Input: two referece of Player.
        */
        Game(Player& player1, Player& player2);


        /*
        Play one turn in the game.
        Note: all rules in link to the source
              task by lecturer, in README.md
        Note2: every turn was logged into _logOfTurns.
        Input: void
        Output: void
        */
        void playTurn();


        /*
        Plays all turn until game is over.
        Input: void
        Output: void
        */
        void playAll();


        /*
        Prints the last turn from _logOfTurns.
        Note: game was no turn yet, exception will throw.
        Input: void
        Output: void
        */
        void printLastTurn() const;


        /*
        Prints all _logOfTurns line by line.
        Input: void
        Output: void
        */
        void printLog() const;


        /*
        Prints the winer of the game.
        Winner is how have the mose cards was taken.
        Input: void
        Output: void
        */
        void printWiner() const;


        /*
        Prints some stats about the game.
        Input: void
        Output: void
        */
        void printStats() const;
    };
};

#endif // !GAME_HPP