//
// Created by Tolepbek Temirlan on 29.10.2021.
//

#pragma once

#include "W4Framework.h"
#include "W4JSON.h"

W4_USE_UNSTRICT_INTERFACE

class Card {
public:
    Card(const std::string &cardName, std::string path) : m_cardName(cardName), m_textureResource(path) {}
    ~Card() = default;

    sptr<Card> createCard(std::string& name);

    sptr<Texture> getTexture();
private:
    std::string m_cardName;
    std::string m_textureResource;
};

