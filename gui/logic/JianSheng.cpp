#include "JianSheng.h"

JianSheng::JianSheng()
{
    makeConnection();
setMyRole(this);
}

void JianSheng::LieFengJi()
{
    state=36;
    tipArea->setMsg(tr("是否发动烈风技？"));
    decisionArea->enable(0);
    decisionArea->enable(1);
}

void JianSheng::LianXuJi()
{
    //先借用基类的额外攻击行动状态
    state=10;
    onceUsed=true;
    gui->reset();
    handArea->setQuota(1);
    handArea->enableElement("wind");
    handArea->disableMagic();
    playerArea->setQuota(1);
    decisionArea->enable(3);
}

void JianSheng::JianYing(){
    attackAction();
    onceUsed2=true;
}

void JianSheng::onOkClicked()
{
    QList<Card*> selectedCards=handArea->getSelectedCards();
    QList<Player*> selectedPlayers=playerArea->getSelectedPlayers();
    Role::onOkClicked();
    QString command,text,cardID,targetID,sourceID;

    switch(state)
    {
//NORMALACTION
    case 1:
//追加行动
    case 10:
    case 12:
        if(selectedCards[0]->getSpecialityList().contains(tr("疾风技")))
            JiFengJi++;
        break;
//额外行动询问
    case 42:
        text=tipArea->getBoxCurrentText();        
        switch (text[0].digitValue()){
        case 1:
            JiFengJi--;           
            emit sendCommand("103;"+QString::number(myID)+";");
            attackAction();            
            break;
        case 2:            
            emit sendCommand("101;"+QString::number(myID)+";");
            LianXuJi();
            break;
        case 3:            
            emit sendCommand("102;"+QString::number(myID)+";");
            JianYing();
            break;
        }
        break;
    }
}
void JianSheng::askForSkill(QString skill)
{
    Role::askForSkill(skill);
    if(skill==tr("烈风技"))
        LieFengJi();
}

void JianSheng::additionalAction()
{
    Role::additionalAction();
    if(JiFengJi>0)
        tipArea->addBoxItem(tr("1.攻击行动（疾风技）"));
    if(!onceUsed&&usedAttack)
        tipArea->addBoxItem(tr("2.连续技"));
    if(!onceUsed2 && dataInterface->getMyself()->getEnergy()>0 &&usedAttack)
        tipArea->addBoxItem(tr("3.剑影"));
}
void JianSheng::turnBegin()
{
    Role::turnBegin();
    onceUsed2=false;
    JiFengJi=0;
}
