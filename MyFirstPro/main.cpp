//main.cpp
#include <QtWidgets/QApplication>
#include <TestMode.h>
#include "MyFirstPro.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 设置控制台输出为 UTF-8
    //SetConsoleOutputCP(CP_UTF8);

    //1.15--

    //测试
    //TestMode tM;
    //tM.show();

    //七、布局
    //水平布局
    //LayoutTest layoutTest1;
    //layoutTest1.QHBoxLayoutTest();
    //layoutTest1.show();

    //垂直布局
    //LayoutTest layoutTest2;
    //layoutTest2.QVBoxLayoutTest();
    //layoutTest2.show();
    
    //网格布局
    //LayoutTest layoutTest3;
    //layoutTest3.QGridLayoutTest();
    //layoutTest3.show();

    //八、常用控件
    //8.1 QLabel
    //QLabelTest labelTest;
    
    //显示文字
    //labelTest.setTextTest();

    //显示图片
    //labelTest.setImageTest();

    //显示动画
    //labelTest.setMovieTest();

    //labelTest.show();

    //8.2 QLineEdit
    //显示文本框并获取
    //QLineEditTest lineEdit;
    //lineEdit.show();
    
    //8.4 自定义控件
    //SmallWidget widget(nullptr);
    //widget.show();
    
    //九、Qt消息事件机制
    //9.2

    EventTest* label = new EventTest;
    label->setWindowTitle("MouseEvent Demo");
    label->resize(300, 200);
    label->show();









    //1.9--1.14
            
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

    //Test04 t04;
    //t04.textEditFunc();
    //t04.show();



    return a.exec();
}


