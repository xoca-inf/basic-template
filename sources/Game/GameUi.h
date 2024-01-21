//
// Created by Tolepbek Temirlan on 29.10.2021.
//
#pragma once

#include "W4Framework.h"
#include "FlowUi/Ui/WorldUi.h"

using namespace games::benice::ui;

class GameUi : public WorldUi {
public:
    GameUi(sptr<Node> root, sptr<Camera> camera, float distance, float baseOrder)
            : WorldUi(root,camera,distance, baseOrder){};
//    GameUi(float baseOrder) : DomUi(baseOrder){}
    void JackOfClubsClicked(std::function<void()> callback) {m_JackOfClubsCallback = callback;};
protected:
    void initContent() ;
private:
    std::function<void()> m_JackOfClubsCallback;
    sptr<Label> m_label;
};