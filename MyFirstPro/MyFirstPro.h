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
#include <QMenuBar>
#include <QMenu>
#include <QKeySequence>
#include <QMainWindow>
#include <QToolBar>
#include <QFile>
#include <QStatusBar>
#include <QProgressBar>
#include <QTimer>
#include <QDockWidget>
#include <QTextEdit>
#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>


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
    Q_OBJECT
public:
    void lambdaTest();
public:
    QWidget* window;
};

//4.QMainWindow
//4.1菜单栏
class Test03 :public QMainWindow
{
    Q_OBJECT
public:
    Test03(QWidget* parent = nullptr);

    //一、获取主窗口菜单栏指针
    //QMenuBar* menuBar() const;

    ////二、创建菜单
    ////将已有的菜单对象添加到菜单栏
    //QAction* addMenu(QMenu* menu);
    ////直接创建一个新菜单，title 是菜单的名字
    //QMenu* addMenu(const QString& title);
    ////创建带图标的菜单
    //QMenu* addMenu(const QIcon& icon, const QString& title);

    ////三、创建菜单项
    //QAction* addAction(const QString& text);
    //QAction* addAction(const QIcon& icon, const QString& text);
    //QAction* addAction(const QString& text, const QObject* receiver,
    //    const char* member, const QKeySequence& shortcut = 0);
    //QAction* addAction(const QIcon& icon, const QString& text, const QObject* receiver, const char* member, const QKeySequence& shortcut = 0);
    void showModalDialog();
    void showNonModalDialog();
    void test1();
};

class Test04 :public QMainWindow
{
    Q_OBJECT
public:
    Test04(QWidget* parent = nullptr);

    void textEditFunc();
    void openFile();
    void saveFile();
private:
    QTextEdit* textEdit;
};




















#endif // !_OI_MYFIRSTPRO_MYFIRSTPRO_H

