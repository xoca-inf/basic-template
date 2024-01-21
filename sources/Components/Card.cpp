//
// Created by Tolepbek Temirlan on 29.10.2021.
//

#include "Card.h"

sptr<Texture> Card::getTexture() {
    return Texture::get(m_textureResource);
}

sptr<Card> Card::createCard(std::string& name) {
    auto file = w4::filesystem::open("cardResources.json");
    auto json = nlohmann::json::parse(file->data(), file->data() + file->size());

    std::string cardName = name;
    std::string texturePath = json[name]["path"];
    auto card = make::sptr<Card>(cardName, texturePath);
    return card;
}

