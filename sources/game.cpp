#include "game.hpp"
#include <iostream>
#include <algorithm>
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

#define NO_ONE 0
#define PLAYER_1 1
#define PLAYER_2 2

using ariel::Card;
using std::cout;
using std::endl;


ariel::Game::Game(Player& player1, Player& player2)
    : _player1(player1), _player2(player2)
{

    if(player1.name() == player2.name())
    {
        throw "Error: can't create the Game. players are the same";
    }

    if(player1.inPlay() || player2.inPlay())
    {
        throw "Error: one or more players are playing right now";
    }

    this->_turnNum = 0;
    this->_gameIsOver = false;
    this->_turnWinner = "";
    this->_winner = NO_ONE;
    this->_player1.startToPlay();
    this->_player2.startToPlay();

    initCards();
    divideCardsToPlayers();
};


void ariel::Game::playTurn()
{
    if(_gameIsOver)
    {
        throw "Error: game is over, cant play any more";
    }

    this->_turnNum++;

    string name1 = this->_player1.name();
    string name2 = this->_player2.name();
    string turnLog = "";

    do
    {
        // break the game if no more cards at players.
        if(this->_player1.stacksize() == 0){ this->_gameIsOver=true; break;}


        Card c1 = this->_player1.playCard();
        Card c2 = this->_player2.playCard();
        this->_cardsStack.push_back(c1);
        this->_cardsStack.push_back(c2);
        int value1 = c1.getValue();
        int value2 = c2.getValue();

        this->_turnWinner = "";

        // check the curr state of turn
        if(value1 == 1 && value2 == 2) { this->_turnWinner = name1; }
        else if(value1 == 2 && value2 == 1){ this->_turnWinner = name2; }
        else if(value1 > value2){ this->_turnWinner = name1; }
        else if(value1 < value2){ this->_turnWinner = name2; }
        else
        {
            this->_turnWinner = "Draw.";
            this->_player1.drawTurn(1);
            this->_player2.drawTurn(1);

            if(this->_player1.stacksize() != 0)
            {
                // hidden cards.
                this->_cardsStack.push_back(this->_player1.playCard());
                this->_cardsStack.push_back(this->_player2.playCard());
            }
        }

        // update turn log
        turnLog += name1 + " played " + c1.cardString() + " " + name2 + " played " + c2.cardString() + ". " + this->_turnWinner + " ";
        if(this->_turnWinner != "Draw."){ turnLog += "wins. "; }

    }while(this->_turnWinner == "Draw.");


    // break the game if no more cards at players.
    if(this->_turnWinner == "Draw.")
    {
        this->_player1.winTurn(this->_cardsStack.size()/2);
        this->_player2.winTurn(this->_cardsStack.size()/2);
    }
    else if(this->_turnWinner == name1)
    {
        this->_player1.winTurn(this->_cardsStack.size());
    }
    else if(this->_turnWinner == name2)
    {
         this->_player2.winTurn(this->_cardsStack.size());
    }
    
    // clear the oldest and unusefull-any-more cards.
    this->_cardsStack.clear();
    if(turnLog != ""){ this->_logOfTurns.push_back(turnLog); }

    if(this->_gameIsOver)
    {  
        _player1.endToPlay();
        _player2.endToPlay();

        if(_player1.cardesTaken() > _player2.cardesTaken())
        {
            this->_winner = PLAYER_1;
        }
        else if(_player1.cardesTaken() < _player2.cardesTaken())
        {
            this->_winner = PLAYER_2;
        }
    }
};



void ariel::Game::playAll()
{
    if(_gameIsOver)
    {
        throw "Error: game is over, cant play any more";
    }

    while(!this->_gameIsOver)
    {
        playTurn();
    }
};


void ariel::Game::printLastTurn() const
{
    if(this->_logOfTurns.empty())
    {
        throw "Error: no turn was yet.. so no logs for now";
    }

    cout << this->_logOfTurns.back() << endl;
};


void ariel::Game::printLog() const
{
    for(size_t i = 0; i < this->_logOfTurns.size(); i++)
    {
        cout << this->_logOfTurns[i] << endl;
    }
};


void ariel::Game::printWiner() const
{
    if(_winner == PLAYER_1){cout << _player1.name() << endl;}
    else if(_winner == PLAYER_2){cout << _player2.name() << endl;}
    else{cout << "Draw. every player have " << _player1.cardesTaken() << " points." << endl;}
};


void ariel::Game::printStats() const{};


//  helpers
void ariel::Game::initCards()
{
    for(int i = 1; i <= 13; i++)
    {
        this->_cardsStack.push_back(Card(i, "Spades"));
        this->_cardsStack.push_back(Card(i, "Clubs"));
        this->_cardsStack.push_back(Card(i, "Hearts"));
        this->_cardsStack.push_back(Card(i, "Diamonds"));
    }
};


// randomality: random one player for each card,
//              and the second get the next card.
//              to do this 26 times.
// https://cplusplus.com/reference/algorithm/random_shuffle/
void ariel::Game::divideCardsToPlayers()
{
    // shuffle the cards before divide
    std::srand(unsigned(std::time(0)));
    std::random_shuffle(this->_cardsStack.begin(), this->_cardsStack.end());

    while(!this->_cardsStack.empty())
    {
        this->_player1.insertCard(this->_cardsStack.back());
        this->_cardsStack.pop_back();
        this->_player2.insertCard(this->_cardsStack.back());
        this->_cardsStack.pop_back();
    }
};
