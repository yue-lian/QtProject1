#include "MyFirstPro.h"
#include "QObject"
#include <QVBoxLayout>
#include <QLabel>
#include <QApplication>



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

Test01::Test01()
{
    connect(this, &Test01::sendSignal, this, &Test01::receiveSlot);
}

void Test01::test2()
{
    emit sendSignal(); // 触发信号
    
}

void Test02::lambdaTest()
{

    /*
    QWidget：最基础的窗口控件，用于承载其他控件。
    QVBoxLayout：一个布局管理器，用于将控件垂直排列。
    QLabel：显示文本或图像的控件，在此用来显示数字。
    QPushButton：一个按钮控件，用于响应用户点击事件。*/
    window = new QWidget(this);

    QVBoxLayout* layout = new QVBoxLayout(window);
    QLabel* label = new QLabel("0", window);
    QPushButton* button = new QPushButton("增加", window);
    
    //重新指定窗口大小
    this->resize(600, 400);

    layout->addWidget(label);
    layout->addWidget(button);

    //使用lambda表达式，传递当前值
    QObject::connect(button, &QPushButton::clicked, [label]() {
        int currentValue = label->text().toInt();
        label->setText(QString::number(currentValue + 1));
        });


}


