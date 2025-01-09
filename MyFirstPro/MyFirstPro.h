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


/*
定义场景：下课了，老师跟同学说肚子饿了（信号），学生请老师吃饭（槽）
首先定义一个学生类和老师类：
老师类中声明信号 饿了 hungry
*/
class Tescher:public QObject
{
    Q_OBJECT

public:

signals:
    void hungry();
public:

};

class Student : public QWidget
{
    Q_OBJECT
    //学生类 声明 槽
public slots:
    void treat();
private:

};

#endif // !_OI_MYFIRSTPRO_MYFIRSTPRO_H


