#pragma once

#include <QtWidgets/QWidget>
#include "ui_MyFirstPro.h"
#include <QPushButton>

class MyFirstPro : public QWidget
{
    Q_OBJECT

public:
    MyFirstPro(QWidget *parent = nullptr);
    ~MyFirstPro();
    void test1();

private:
    Ui::MyFirstProClass ui;
};
