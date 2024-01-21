//
// Created by Tolepbek Temirlan on 29.10.2021.
//

#pragma once

#include "Card.h"
#include "W4Framework.h"

class Player {
public:
    static Player &instance() {
        static Player instance;
        return isntance;
    }

    Player();
    virtual ~Player() = default;

    std::vector<sptr<Card>> getCurrentHand();
    void setCurrentHand(std::vector<sptr<Card>>);
private:
    std::vector<sptr<Card>> m_Cards;

};