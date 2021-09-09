#ifndef HAND_H
#define HAND_H

#include <vector>
#include "card.h"
#include "house.h"



using namespace std;

class Hand
{
public:
    Hand();
    // виртуальный деструктор
    virtual ~Hand();

    // добавляет карту в руку
    void Add(Card* pCard);

    // очищает руку от карт
    void Clear();

    //получает сумму очков карт в руке, присваивая тузу
    // значение 1 или 11 в зависимости от ситуации
    int GetTotal() const;

protected:
    vector<Card*> m_Cards;
};

#endif // HAND_H
