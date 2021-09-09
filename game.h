#ifndef GAME_H
#define GAME_H

#include "deck.h"
#include "house.h"
#include "player.h"

class Game
{
public:
    Game(const vector<string>& names);

    ~Game();

    // проводит игру в Blackjack
    void Play();

private:
    Deck m_Deck;
    House m_House;
    vector<Player> m_Players;
};


#endif // GAME_H
