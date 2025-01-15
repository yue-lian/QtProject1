//TestMode.cpp
#include "TestMode.h"
TestMode::TestMode(QWidget* parent) :QMainWindow(parent) {
	QMessageBox::warning(this, tr("stop!"), tr("You are winner!!"));
}



LayoutTest::LayoutTest(QWidget* parent):QMainWindow(parent)
{
	//�������Ĳ���
	QWidget* centralWidget = new QWidget(this);
	setCentralWidget(centralWidget);

}

void LayoutTest::QHBoxLayoutTest()
{
	//������ť
	QPushButton* button1 = new QPushButton("Button 1", this);
	QPushButton* button2 = new QPushButton("Button 2", this);
	QPushButton* button3 = new QPushButton("Button 3", this);
	QPushButton* button4 = new QPushButton("Button 4", this);

	//����ˮƽ����
	QHBoxLayout* layout = new QHBoxLayout();

	//�򲼾�����Ӱ�ť
	layout->addWidget(button1);
	layout->addWidget(button2);
	layout->addWidget(button3);
	layout->addWidget(button4);

	//���ò��ֵ����Ĳ���
	QWidget* centralWidget = this->centralWidget();
	centralWidget->setLayout(layout);
}

void LayoutTest::QVBoxLayoutTest()
{
	//������ť
	QPushButton* button1 = new QPushButton("Button 1", this);
	QPushButton* button2 = new QPushButton("Button 2", this);
	QPushButton* button3 = new QPushButton("Button 3", this);
	QPushButton* button4 = new QPushButton("Button 4", this);

	//����ˮƽ����
	QVBoxLayout* layout = new QVBoxLayout();

	//�򲼾�����Ӱ�ť
	layout->addWidget(button1);
	layout->addWidget(button2);
	layout->addWidget(button3);
	layout->addWidget(button4);

	//���ò��ֵ����Ĳ���
	QWidget* centralWidget = this->centralWidget();
	centralWidget->setLayout(layout);

}

void LayoutTest::QGridLayoutTest()
{
	//������ť
	QPushButton* button1 = new QPushButton("Button 1", this);
	QPushButton* button2 = new QPushButton("Button 2", this);
	QPushButton* button3 = new QPushButton("Button 3", this);
	QPushButton* button4 = new QPushButton("Button 4", this);

	//����ˮƽ����
	QGridLayout* layout = new QGridLayout();

	//�򲼾�����Ӱ�ť
	layout->addWidget(button1,0,0);
	layout->addWidget(button2);
	layout->addWidget(button3);
	layout->addWidget(button4,1,1);

	//���ò��ֵ����Ĳ���
	QWidget* centralWidget = this->centralWidget();
	centralWidget->setLayout(layout);

}

QLabelTest::QLabelTest(QWidget* parent):QMainWindow(parent)
{

}

void QLabelTest::setTextTest()
{
	QLabel* label = new QLabel(this);

	label->setText("HelloWorld��");

	//label->setText("<h1><a href=\"https://www.baidu.com\">�ٶ�һ��</a></h1>");
	//label->setOpenExternalLinks(true);
	//label->adjustSize();

}

void QLabelTest::setImageTest()
{
	QPixmap pixmap;
	pixmap.load(":/images/file-open.png");
	QLabel* label = new QLabel(this);
	label->setPixmap(pixmap);
	label->adjustSize();
}

void QLabelTest::setMovieTest()
{
	QMovie* movie = new QMovie(":/gif/cat");
	//QMovie* movie = new QMovie("C:\\Users\\senlz\\Pictures\\gif\\cxk.gif");
	movie->start();
	QLabel* label = new QLabel(this);
	label->setMovie(movie);
	label->adjustSize();

}

QlineEditTest::QlineEditTest(QWidget* parent):QMainWindow(parent)
{
	//����һ��QLineEdit
	QLineEdit* lineEdit = new QLineEdit(this);
	lineEdit->setPlaceholderText("please input text...");

	//����һ����ť
	QPushButton* button = new QPushButton("get text", this);

	//�������ֲ���ӿؼ�
	QGridLayout* layout = new QGridLayout(this);
	layout->addWidget(lineEdit,0,0);
	layout->addWidget(button,1,0);

	// ���ò��ֵļ��ͱ߾�
	layout->setSpacing(10);  // �ؼ�֮��ļ��
	layout->setContentsMargins(10, 10, 10, 10);  // ���ò������ܵı߾�

	// ���ô��ڵ����벼��
	QWidget* centralWidget = new QWidget(this);
	centralWidget->setLayout(layout);
	setCentralWidget(centralWidget);

	//����ť�����ʱ��ȡQLineEdit�е��ı�
	connect(button, &QPushButton::clicked, this, [lineEdit]() {
		QString text = lineEdit->text();//��ȡ������ı�
		qDebug() << "output:" << text;
		});
}
