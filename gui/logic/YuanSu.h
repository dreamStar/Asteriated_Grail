#ifndef YUANSU_H
#define YUANSU_H
#include "Role.h"
class YuanSu : public Role
{
    Q_OBJECT
public:
    YuanSu();
    void normal();
    void magicAction();
public slots:
    void decipher(QString command);
    void onOkClicked();
    void onCancelClicked();
    void cardAnalyse();
    void YuanSuFaShu1();
    void YuanSuFaShu2();
    void YuanSuDianRan();
    void YueGuang();
private:
    Card* magicCard;
    int magicTargetID;
    bool wind,earth,ignite;
};

#endif // YUANSU_H
