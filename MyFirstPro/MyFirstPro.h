#ifndef _OI_MYFIRSTPRO_MYFIRSTPRO_H
#define _OI_MYFIRSTPRO_MYFIRSTPRO_H

#include <QtWidgets/QWidget>
#include "ui_MyFirstPro.h"
#include <QPushButton>
#include <iostream>
#include "QObject"
#include <QVBoxLayout>
#include <QLabel>
#include <QApplication>
//1.
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


//2.
class Test01 :public QWidget
{
    Q_OBJECT
public:
    Test01();
    void test2();


signals:
    void sendSignal();

public slots:
    void receiveSlot() { 
        //std::cout << "我收到了信息" << std::endl; 
        qDebug() << "这是 Qt 的调试信息";
    };
};

//3.
class Test02:public QWidget
{
public:
    void lambdaTest();
public:
    QWidget* window;
};






















#endif // !_OI_MYFIRSTPRO_MYFIRSTPRO_H

