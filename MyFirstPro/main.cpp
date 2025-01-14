#include "MyFirstPro.h"
#include <QtWidgets/QApplication>
#include <windows.h>

int main(int argc, char *argv[])
{
    // 设置控制台输出为 UTF-8
    //SetConsoleOutputCP(CP_UTF8);

    QApplication a(argc, argv);

    //MyFirstPro w;
    ////调用成员函数
    //w.test1();
    ////使默认不可见的窗口可见
    //w.show();

    //Test01 t01;
    //t01.test2();
    //t01.show();

    //Lambda表达式
    //用于定义匿名的函数对象
    // [=]()mutable int{}
    //[局部变量捕获列表]\(函数参数)、函数额外属性设置opt、函数返回值->retype、函数主体}
    
    //Test02 t02;
    //t02.lambdaTest();
    //t02.show();

    //菜单栏
    //Test03 t03;
    ////消息对话框
    //t03.test1();
    ////标准文件对话框
    //t03.show();

    //消息对话框
    Test04 t04;
    t04.textEditFunc();
    t04.show();


    return a.exec();
}


