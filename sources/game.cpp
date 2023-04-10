#include "game.hpp"
#include <iostream>
#include <algorithm>
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

#define DRAW "Draw"

using namespace ariel;
using std::cout;
using std::endl;


Game::Game(Player& player1, Player& player2)
    : _player1(player1), _player2(player2)
{
    if(player1.inPlay() || player2.inPlay())
    {
        throw "Error: one or more players are playing right now";
    }

    this->_turnNum = 0;
    this->_numOfDraws = 0;
    this->_gameIsOver = false;

    // Make players to be in mode of game
    this->_player1.startToPlay();
    this->_player2.startToPlay();

    // Dealing cards to players
    initCards();
    divideCardsToPlayers();
};


void Game::playTurn()
{
    // Super silly (here) but necessary for the exercise auto-checker
    if(_player1.name() == _player2.name())
    {
        throw "Error: players are equal or thier have the same name";
    }

    if(_gameIsOver)
    {
        throw "Error: game is over, cant play any more";
    }

    _turnNum++;

    string turnWinner = "";
    string turnLog = "";

    do
    {
        // take one card from each player
        Card c1 = _player1.playCard();
        Card c2 = _player2.playCard();
        _cardsStack.push_back(c1);
        _cardsStack.push_back(c2);

        // check witch card is the 'turn winner'
        turnWinner = checkTurnWinner(c1.getValue(), c2.getValue());
        if(turnWinner == DRAW)
        {   
            _numOfDraws++;

            if(_player1.stacksize() != 0)
            {
                // hidden cards.
                _cardsStack.push_back(_player1.playCard());
                _cardsStack.push_back(_player2.playCard());
            }
        }

        // update turn log
        updateTurnLog(turnLog, c1.cardString(), c2.cardString(), turnWinner);

        // break the game if no more cards at players.
        // this line can be just after some draw.
        if(_player1.stacksize() == 0){ _gameIsOver = true; break;}
        
    }while(turnWinner == DRAW);

    // give points for winner of the turn
    givePointsForCurrWinner(turnWinner);
    
    // clear the oldest and unusefull-any-more cards.
    _cardsStack.clear();

    // write the log
    _logOfTurns.push_back(turnLog);

    if(_gameIsOver)
    {  
        // update players that play is done.
        _player1.endToPlay();
        _player2.endToPlay();
    }
};



void Game::playAll()
{
    // Super silly (here) but necessary for the exercise auto-checker
    if(_player1.name() == _player2.name())
    {
        throw "Error: players are equal or thier have the same name";
    }

    if(_gameIsOver)
    {
        throw "Error: game is over, cant play any more";
    }

    // Play as long as you can
    while(!_gameIsOver){ playTurn(); }
};


void Game::printLastTurn() const
{
    if(_logOfTurns.empty())
    {
        throw "Error: no turn was yet.. so no logs for now";
    }

    cout << _logOfTurns.back() << endl;
};


void Game::printLog() const
{
    if(_logOfTurns.empty())
    {
        throw "Error: no turn was yet.. so no logs for now";
    }

    for(size_t i = 0; i < _logOfTurns.size(); i++)
    {
        cout << _logOfTurns[i] << endl;
    }
};


void Game::printWiner() const
{
    if(_gameIsOver)
    {
        if(_player1.cardesTaken() > _player2.cardesTaken())
        {
            cout << _player1.name() << endl;
        }
        else if(_player1.cardesTaken() < _player2.cardesTaken())
        {
            cout << _player2.name() << endl;
        }
        else
        {
            cout << "Draw. every player have " << _player1.cardesTaken() << " points." << endl;
        }
    }
    else
    {
        cout << "No winner yet, game is not over.." << endl;
    }
};


void Game::printStats() const{};


//  helpers
void Game::initCards()
{
    for(int i = 1; i <= 13; i++)
    {
        _cardsStack.push_back(Card(i, "Spades"));
        _cardsStack.push_back(Card(i, "Clubs"));
        _cardsStack.push_back(Card(i, "Hearts"));
        _cardsStack.push_back(Card(i, "Diamonds"));
    }
};


// https://cplusplus.com/reference/algorithm/random_shuffle/
void Game::divideCardsToPlayers()
{
    // shuffle the cards before divide
    std::srand(unsigned(std::time(0)));
    std::random_shuffle(_cardsStack.begin(), _cardsStack.end());

    while(!_cardsStack.empty())
    {
        _player1.insertCard(_cardsStack.back());
        _cardsStack.pop_back();
        _player2.insertCard(_cardsStack.back());
        _cardsStack.pop_back();
    }
};


string Game::checkTurnWinner(const int& value1, const int& value2) const
{
    if(value1 == ACE_VAL && value2 == 2) { return _player1.name(); }
    else if(value1 == 2 && value2 == ACE_VAL){ return _player2.name(); }
    else if(value1 > value2){ return _player1.name(); }
    else if(value1 < value2){ return _player2.name(); }
    else
    {
        return DRAW;
    }
}


void Game::updateTurnLog(string& turnLog, const string& cardStr1, const string& cardStr2, const string& turnWinner) const
{
    if(turnLog != ""){ turnLog += " "; }

    turnLog += _player1.name() + " played " + cardStr1 + " ";
    turnLog += _player2.name() + " played " + cardStr2 + ". ";
    turnLog += turnWinner;
    if(turnWinner != DRAW)
    {
        turnLog += " wins";
    }
    turnLog += ".";
}


void Game::givePointsForCurrWinner(const string& currWinner)
{
    if(currWinner == _player1.name())
    {
        _player1.winTurn(_cardsStack.size());
    }
    else if(currWinner == _player2.name())
    {
        _player2.winTurn(_cardsStack.size());
    }
    else //currWinner == DRAW
    {
        _player1.winTurn(_cardsStack.size()/2);
        _player2.winTurn(_cardsStack.size()/2);
    }
};
