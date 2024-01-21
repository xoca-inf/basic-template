//
// Created by Tolepbek Temirlan on 29.10.2021.
//

#include "GameUi.h"
#include "Settings/ResourceLibary.h"

void GameUi::initContent() {
    auto mainRect = getRect();

    auto content = make::sptr<UiRect>(Offset(0.0, OffsetType::PERCENT, PivotAt::LEFT),
                                          Offset(0.0, OffsetType::PERCENT, PivotAt::RIGHT),
                                          Offset(0.0, OffsetType::PERCENT, PivotAt::TOP),
                                          Offset(0.0, OffsetType::PERCENT, PivotAt::BOTTOM));

    mainRect->addChild(content);

    createItem(
            content,
            "contentRect",
            Offset(0.0, OffsetType::PERCENT, PivotAt::LEFT),
            Offset(0.0, OffsetType::PERCENT, PivotAt::RIGHT),
            Offset(0.0, OffsetType::PERCENT, PivotAt::TOP),
            Offset(0.0, OffsetType::PERCENT, PivotAt::BOTTOM),
            ResourceLibary::instance().getTexturePath("BackgroundImageGame"),
            1.0);
    auto m_contentRect = content->findChild("contentRect");
    m_contentRect->setFill(FillType::IGNORE_ASPECT, 4./2.);

    //DownloadButton
    createItem(
            m_contentRect,
            "downloadButton",
            Offset(2.5/6., OffsetType::PERCENT, PivotAt::LEFT),
            Offset(2.5/6., OffsetType::PERCENT, PivotAt::RIGHT),
            Offset(0.1, OffsetType::PERCENT, PivotAt::BOTTOM),
            Offset(0, OffsetType::PERCENT, PivotAt::BOTTOM),
            ResourceLibary::instance().getTexturePath("DownloadButton"),
            2.0);
    auto rect = m_contentRect->findChild("downloadButton");
    rect->setFill(FillType::IGNORE_ASPECT, 3./2.);
    auto item = getItem("downloadButton");
    item->setClickCallback([this](){});
    item->setClickable(true);

    //Awatar1
    createItem(
            m_contentRect,
            "awatar1",
            Offset(0, OffsetType::PERCENT, PivotAt::LEFT),
            Offset(0.05, OffsetType::PERCENT, PivotAt::LEFT),
            Offset(0.1, OffsetType::PERCENT, PivotAt::TOP),
            Offset(0.2, OffsetType::PERCENT, PivotAt::TOP),
            ResourceLibary::instance().getTexturePath("awatar1"),
            2.0);
    auto awatar1 = m_contentRect->findChild("awatar1");
    awatar1->setFill(FillType::IGNORE_ASPECT, 3./2.);

    //Awatar2
    createItem(
            m_contentRect,
            "awatar2",
            Offset(47.5/100., OffsetType::PERCENT, PivotAt::LEFT),
            Offset(52.5/100., OffsetType::PERCENT, PivotAt::LEFT),
            Offset(0, OffsetType::PERCENT, PivotAt::TOP),
            Offset(0.1, OffsetType::PERCENT, PivotAt::TOP),
            ResourceLibary::instance().getTexturePath("awatar2"),
            2.0);
    auto awatar2 = m_contentRect->findChild("awatar2");
    awatar1->setFill(FillType::IGNORE_ASPECT, 3./2.);

    //Awatar3
    createItem(
            m_contentRect,
            "awatar3",
            Offset(0.05, OffsetType::PERCENT, PivotAt::RIGHT),
            Offset(0, OffsetType::PERCENT, PivotAt::RIGHT),
            Offset(0.1, OffsetType::PERCENT, PivotAt::TOP),
            Offset(0.2, OffsetType::PERCENT, PivotAt::TOP),
            ResourceLibary::instance().getTexturePath("awatar3"),
            2.0);
    auto awatar3 = m_contentRect->findChild("awatar3");
    awatar3->setFill(FillType::IGNORE_ASPECT, 3./2.);

    //Awatar4
    createItem(
            m_contentRect,
            "awatar4",
            Offset(0.25, OffsetType::PERCENT, PivotAt::LEFT),
            Offset(0.3, OffsetType::PERCENT, PivotAt::LEFT),
            Offset(0.37, OffsetType::PERCENT, PivotAt::BOTTOM),
            Offset(0.27, OffsetType::PERCENT, PivotAt::BOTTOM),
            ResourceLibary::instance().getTexturePath("awatar4"),
            2.0);
    auto awatar4 = m_contentRect->findChild("awatar4");
    awatar3->setFill(FillType::IGNORE_ASPECT, 3./2.);

    //King_Of_Hearts*
    createItem(
            m_contentRect,
            "King_Of_Hearts",
            Offset(7.5/18., OffsetType::PERCENT, PivotAt::LEFT),
            Offset(8.5/18., OffsetType::PERCENT, PivotAt::LEFT),
            Offset(0.27,OffsetType::PERCENT,PivotAt::BOTTOM),
            Offset(0.12,OffsetType::PERCENT,PivotAt::BOTTOM),
            ResourceLibary::instance().getTexturePath("King_Of_Hearts"),
            2.0);
    auto King_Of_Hearts = m_contentRect->findChild("King_Of_Hearts");
    King_Of_Hearts->setFill(FillType::IGNORE_ASPECT, 3./2.);

    //Ten_Of_Clubs*
    createItem(
            m_contentRect,
            "Ten_Of_Clubs",
            Offset(8./18., OffsetType::PERCENT, PivotAt::LEFT),
            Offset(9./18., OffsetType::PERCENT, PivotAt::LEFT),
            Offset(0.27,OffsetType::PERCENT,PivotAt::BOTTOM),
            Offset(0.12,OffsetType::PERCENT,PivotAt::BOTTOM),
            ResourceLibary::instance().getTexturePath("Ten_Of_Clubs"),
            3.0);
    auto Ten_Of_Clubs = m_contentRect->findChild("Ten_Of_Clubs");
    Ten_Of_Clubs->setFill(FillType::IGNORE_ASPECT, 3./2.);

    //Seven_Of_Spades*
    createItem(
            m_contentRect,
            "Seven_Of_Spades",
            Offset(8.5/18., OffsetType::PERCENT, PivotAt::LEFT),
            Offset(9.5/18., OffsetType::PERCENT, PivotAt::LEFT),
            Offset(0.27,OffsetType::PERCENT,PivotAt::BOTTOM),
            Offset(0.12,OffsetType::PERCENT,PivotAt::BOTTOM),
            ResourceLibary::instance().getTexturePath("Seven_Of_Spades"),
            4.0);
    auto Seven_Of_Spades = m_contentRect->findChild("Seven_Of_Spades");
    Ten_Of_Clubs->setFill(FillType::IGNORE_ASPECT, 3./2.);

    //Five_Of_Hearts*
    createItem(
            m_contentRect,
            "Five_Of_Hearts",
            Offset(9./18., OffsetType::PERCENT, PivotAt::LEFT),
            Offset(10./18., OffsetType::PERCENT, PivotAt::LEFT),
            Offset(0.27,OffsetType::PERCENT,PivotAt::BOTTOM),
            Offset(0.12,OffsetType::PERCENT,PivotAt::BOTTOM),
            ResourceLibary::instance().getTexturePath("Five_Of_Hearts"),
            5.0);
    auto Five_Of_Hearts = m_contentRect->findChild("Five_Of_Hearts");
    Ten_Of_Clubs->setFill(FillType::IGNORE_ASPECT, 3./2.);

    //Jack_Of_Clubs*
    createItem(
            m_contentRect,
            "Jack_Of_Clubs",
            Offset(9.5/18., OffsetType::PERCENT, PivotAt::LEFT),
            Offset(10.5/18., OffsetType::PERCENT, PivotAt::LEFT),
            Offset(0.27,OffsetType::PERCENT,PivotAt::BOTTOM),
            Offset(0.12,OffsetType::PERCENT,PivotAt::BOTTOM),
            ResourceLibary::instance().getTexturePath("Jack_Of_Clubs"),
            6.0);
    auto Jack_Of_Clubs = m_contentRect->findChild("Jack_Of_Clubs");
    Ten_Of_Clubs->setFill(FillType::IGNORE_ASPECT, 3./2.);

    float l1 = 6./18., r1 = 7./18., t1 = 0.65, b1 = 0.5;
    float l2 = 8.5/18., r2 = 9.5/18., t2 = 0.80, b2 = 0.65;
    float l3 = 11./18., r3 = 12./18., t3 = 0.65, b3 = 0.5;



}
