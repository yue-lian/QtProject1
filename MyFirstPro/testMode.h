//TestMode.h
#ifndef _OI_MYFIRSTPRO_TESTMODE_H
#define _OI_MYFIRSTPRO_TESTMODE_H

#include <iostream>
#include <QPushButton>
#include <QDebug>
#include <QWidget>
#include <QMessageBox>
#include <QMainWindow>
#include <QApplication>
#include <QCloseEvent>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPixmap>
#include <QMovie>
#include <QLineEdit>
#include <QString>




class TestMode:public QMainWindow
{
	Q_OBJECT
public:
	TestMode(QWidget* patent = nullptr);



};

//7.1 静态布局
//用户改变窗口大小后，静态布局没有响应


//7.2 动态布局
//解决静态布局的缺陷
//1)按照水平方向从左到右布局--QHBoxLayout
//2)按照竖直方向从上到下布局--QVBoxLayout
//3)在一个网格中进行布局，类似HTML的table--QGridLayout

class LayoutTest:public QMainWindow
{
	Q_OBJECT

public:
	LayoutTest(QWidget* parent = nullptr);
	void QHBoxLayoutTest();//水平
	void QVBoxLayoutTest();//上下
	void QGridLayoutTest();//网格

	

};

//八、常用控件

//8.1 QLabel控件
//显示文本、图片、动画
class QLabelTest:public QMainWindow
{
	Q_OBJECT

public:
	QLabelTest(QWidget* parent = nullptr);
	void setTextTest();
	void setImageTest();
	void setMovieTest();

};



//8.2 QlineEdit
class QlineEditTest:public QMainWindow
{
	Q_OBJECT

public:
	QlineEditTest(QWidget* parent = nullptr);
};


//8.3 其他

//8.4 自定义控件

//





























#endif // !_OI_MYFIRSTPRO_TESTMODE_H

