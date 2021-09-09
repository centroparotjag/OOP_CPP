#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>
#include "genericplayer.h"

class House : public GenericPlayer
{
public:
    House(const string& name = "House");

    virtual ~House();

    // показывает, хочет ли дилер продолжать брать карты
    virtual bool IsHitting() const;

    // переворачивает первую карту
    void FlipFirstCard();
};


#endif // HOUSE_H
