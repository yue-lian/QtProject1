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

//7.1 ��̬����
//�û��ı䴰�ڴ�С�󣬾�̬����û����Ӧ


//7.2 ��̬����
//�����̬���ֵ�ȱ��
//1)����ˮƽ��������Ҳ���--QHBoxLayout
//2)������ֱ������ϵ��²���--QVBoxLayout
//3)��һ�������н��в��֣�����HTML��table--QGridLayout

class LayoutTest:public QMainWindow
{
	Q_OBJECT

public:
	LayoutTest(QWidget* parent = nullptr);
	void QHBoxLayoutTest();//ˮƽ
	void QVBoxLayoutTest();//����
	void QGridLayoutTest();//����

	

};

//�ˡ����ÿؼ�

//8.1 QLabel�ؼ�
//��ʾ�ı���ͼƬ������
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


//8.3 ����

//8.4 �Զ���ؼ�

//





























#endif // !_OI_MYFIRSTPRO_TESTMODE_H

