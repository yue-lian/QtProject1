#ifndef _OI_MYFIRSTPRO_MYFIRSTPRO_H
#define _OI_MYFIRSTPRO_MYFIRSTPRO_H

#include <QtWidgets/QWidget>
#include "ui_MyFirstPro.h"
#include <QPushButton>

//窗口类
class MyFirstPro : public QWidget
{
    Q_OBJECT

public:
    MyFirstPro(QWidget* parent = nullptr);
    ~MyFirstPro();
    void test1();

private:
    Ui::MyFirstProClass ui;
};

#endif // !_OI_MYFIRSTPRO_MYFIRSTPRO_H


