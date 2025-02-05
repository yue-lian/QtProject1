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
#include <QSpinBox>
#include <QSlider>
#include <QPointF>
#include <QPainter>
#include <QMenuBar>
#include <QFileDialog>
#include <QTextEdit>
#include <QTimer>
#include <QToolBar>
#include <QStatusBar>
#include <QDateTime>
#include <QActionGroup>
#include <QStringList>
#include <QStringConverter>
#include <QTextStream>




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



//8.2 QLineEdit
class QLineEditTest:public QMainWindow
{
	Q_OBJECT

public:
	QLineEditTest(QWidget* parent = nullptr);
};


//8.3 其他
/*

1. QLabel--显示文本、图像
2. QPushButton--按钮，用于触发点击事件
3. QLineEdit--单行文本输入（密码输入框、限制字符类型）
4. QTextEdit--多行文本输入
5. QComboBox--下拉选择框
6. QCheckBox--复选框
7. QRadiobutton--单选框
8. QSlider--滑动条控件
9. QProgressBar--显示任务进度
10. QListView / QTableView--显示列表和表格视图
11. QTreeView--显示树形结构的数据
12. QTabWidget--显示创建选项卡界面
13. QSpinBox / QDoubleSpinBox--选择整数或浮动数值
14. QFileDialog--用于打开或保存文件对话框
15. QDialog--显示模态/非模态对话框
16. QMenuBar / QToolBar--创建应用程序的菜单栏和工具栏


*/


//8.4 自定义控件

class SmallWidget:public QWidget
{
	Q_OBJECT

public:
	explicit SmallWidget(QWidget* parent);

private:
	QSpinBox* spin;
	QSlider* slider;

};


//九、Qt消息事件机制
//9.2事件处理函数
/*
		1.keyPressEvent()：键盘按键按下事件
		2.keyReleaseEvent()：键盘按键松开事件
		3.mouseDoubleClickEvent()：鼠标双击事件
		4.mouseMoveEvent()：鼠标移动事件
		5.mousePressEvent()：鼠标按键按下事件
		6.mouseReleaseEvent() ：鼠标按键松开事件
*/
class EventTest : public QLabel
{
public:
	EventTest();
	EventTest(QWidget* parent);
protected:
	void mouseMoveEvent(QMouseEvent* event = nullptr);
	void mousePressEvent(QMouseEvent* event = nullptr);
	void mouseReleaseEvent(QMouseEvent* event = nullptr);


};

//9.3事件分发函数event()

class EventDistributeFunctionTest:public QWidget
{
	Q_OBJECT

public:
	EventDistributeFunctionTest(QWidget* parent = nullptr);
protected:
	/*
	事件分发
	1.在 event() 中处理不同事件类型
	2.拦截并修改鼠标事件
	3.拦截键盘按下事件
	*/
	bool event(QEvent* event)override;

	


};

//9.4事件过滤器的使用
/*
基本步骤
1.创建一个事件过滤器（重写eventFilter）
2.安装事件过滤器installEventFilter
3.事件处理eventFilter
*/

class EventFilterTest :public QObject
{
	Q_OBJECT

public:
	EventFilterTest();
	bool eventFilter(QObject* obj, QEvent* event)override;

private:

};

/*
简单文本编辑器
	目标：使用QMainWindow来创建一个基本的文本编辑器，具有菜单栏、工具栏、状态栏等。
涉及知识点：
	信号与槽：处理菜单栏项选择（如新建、打开、保存等）。
	QMainWindow：搭建应用程序的框架。
	QDialog：使用文件对话框来打开和保存文件。
	QLabel、QLineEdit：用于显示文件路径和文本编辑。
*/


class TextEdit:public QMainWindow
{
	Q_OBJECT
public:
	TextEdit(QWidget *parent = nullptr);
	void runTest();
	bool confirmSave();
	void closeEvent(QCloseEvent* event);
	void updateWindowTitle();
	//选择编码并存储
	void setEncoding(QAction* action);
	////读取文件时按选定编码转换
	//void loadFile(const QString &filePath);
	//void saveFile(const QString &filePath);
signals:

public slots:
	void openFile();
	bool saveFile();
	void newFile();
public:
	QTextEdit* textEdit;
	QString currentFilePath;  // 记录当前文件路径
	bool isEdited = false;//编辑状态信号
	QString currentEncoding = "UTF-8";  // 默认 UTF-8

};
















#endif // !_OI_MYFIRSTPRO_TESTMODE_H

