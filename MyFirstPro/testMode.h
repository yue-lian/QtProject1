//TestMode.h
#ifndef _OI_MYFIRSTPRO_TESTMODE_H
#define _OI_MYFIRSTPRO_TESTMODE_H

#include <iostream>
#include <QPushButton>
#include <QDebug>
#include <QWidget>
#include <QMessageBox>
#include <QMainWindow>




class TestMode:public QMainWindow
{
	Q_OBJECT
public:
	TestMode(QWidget* patent = nullptr);

	void test(QWidget*patent = nullptr) ;

private:

};

































#endif // !_OI_MYFIRSTPRO_TESTMODE_H

