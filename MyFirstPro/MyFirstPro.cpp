#include "MyFirstPro.h"


MyFirstPro::MyFirstPro(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
}

MyFirstPro::~MyFirstPro()
{}

void MyFirstPro::test1()
{
    QPushButton* btn = new QPushButton;
    //设置父亲
    btn->setParent(this);
    //设置文字
    btn->setText("AONY");
    //移动位置
    btn->move(100, 100);

    //第二种创建
    QPushButton* btn2 = new QPushButton("孙悟空", this);
    btn2->move(100, 200);
    //重新指定窗口大小
    this->resize(600, 400);
    //设置窗口标题
    this->setWindowTitle("My First Project");
    //限制窗口大小
    this->setFixedSize(600, 400); 
}


