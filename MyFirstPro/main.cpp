#include "MyFirstPro.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyFirstPro w;
    
    //调用成员函数
    w.test1();
    //使默认不可见的窗口可见
    w.show();

    return a.exec();
}


