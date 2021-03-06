#include "widget/GUI.h"
GUI* gui=NULL;
GUI::GUI(QObject *parent) :
    QObject(parent)
{
}
void GUI::reset()
{
    playerArea->reset();
    buttonArea->reset();
    handArea->reset();
    tipArea->reset();
    decisionArea->reset();
}

void GUI::setEnable(bool flag)
{
    handArea->setEnabled(flag);
    playerArea->setEnabled(flag);
    buttonArea->setEnabled(flag);
    decisionArea->setEnabled(flag);
}

void GUI::setHandArea(HandArea* handArea)
{
    this->handArea=handArea;
}

void GUI::setPlayerArea(PlayerArea* playerArea)
{
    this->playerArea=playerArea;
}

void GUI::setShowArea(ShowArea* showArea)
{
    this->showArea=showArea;
}

void GUI::setTeamArea(TeamArea* teamArea)
{
    this->teamArea=teamArea;
}

void GUI::setTipArea(TipArea* tipArea)
{
    this->tipArea=tipArea;
}
void GUI::setDecisionArea(DecisionArea* decisionArea)
{
    this->decisionArea=decisionArea;
}

void GUI::setButtonArea(ButtonArea* buttonArea)
{
    this->buttonArea=buttonArea;
}

void GUI::setLogArea(LogArea *logArea)
{
    this->logArea=logArea;
}

HandArea* GUI::getHandArea()
{
    return handArea;
}

PlayerArea* GUI::getPlayerArea()
{
    return playerArea;
}

ShowArea* GUI::getShowArea()
{
    return showArea;
}

TeamArea* GUI::getTeamArea()
{
    return teamArea;
}

TipArea* GUI::getTipArea()
{
    return tipArea;
}

DecisionArea* GUI::getDecisionArea()
{
    return decisionArea;
}

ButtonArea* GUI::getButtonArea()
{
    return buttonArea;
}

void GUI::logAppend(QString msg)
{
    logArea->append(msg);
}
