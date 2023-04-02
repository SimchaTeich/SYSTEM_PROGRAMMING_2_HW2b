#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include <stdexcept>

using namespace ariel;


TEST_CASE("Create Player")
{
    // Init player.
    Player alice("Alice");
    CHECK(alice.stacksize() == 0);
    CHECK(alice.cardesTaken() == 0);

    // Try to create 'Anonymous' player.
    CHECK_THROWS(Player(""));
}


TEST_CASE("Create Game")
{
    // Init Players.
    Player alice("Alice");
    Player bob("Bob");
    Player eve("Eve");

    // Init Game
    Game g(alice, bob);

    // Check the initial stacksize and score.
    CHECK(alice.stacksize() == 26);
    CHECK(alice.cardesTaken() == 0);
    CHECK(bob.stacksize() == 26);
    CHECK(bob.cardesTaken() == 0);

    // Try to create game using the same player.
    CHECK_THROWS(Game(eve, eve));

    // Try to create game with player
    // that actualy play right now. (Alice..)
    CHECK_THROWS(Game(alice, eve));
}


TEST_CASE("Play one turn")
{
    // Init Players.
    Player alice("Alice");
    Player bob("Bob");

    // Init Game
    Game g(alice, bob);
    
    // Try to print the last turn,
    // BEFORE it was happend!
    CHECK_THROWS(g.printLastTurn());

    // Play the first turn
    g.playTurn();

    // Try to print the last turn,
    // AFTER it was happend!
    CHECK_NOTHROW(g.printLastTurn());

    // check how many cards left.
    CHECK(alice.stacksize() <= 25);
    CHECK(bob.stacksize() <= 25);
    CHECK_EQ(alice.stacksize(), bob.stacksize());

    // check the score right now (after the first turn)
    CHECK((alice.cardesTaken() >= 1 && bob.cardesTaken() == 0 ||
    alice.cardesTaken() == 0 && bob.cardesTaken() >= 1));
}


TEST_CASE("Play all turns")
{
   // Init Players.
    Player alice("Alice");
    Player bob("Bob");

    // Init Game
    Game g(alice, bob);

    // Finish the game
    g.playAll();

    // check stacks of players are empty.
    CHECK(alice.stacksize() == 0);
    CHECK(bob.stacksize() == 0);

    // check for can't play after the end.
    CHECK_THROWS(g.playTurn());
    CHECK_THROWS(g.playAll());
}


TEST_CASE("Play again")
{
    // Init Players.
    Player alice("Alice");
    Player bob("Bob");

    // Init Game
    Game g(alice, bob);

    // try to create one more game
    // with these players
    CHECK_THROWS(Game(alice, bob));

    // done the first game
    g.playAll();

    // play again :)
    CHECK_NOTHROW(Game(alice, bob));
}