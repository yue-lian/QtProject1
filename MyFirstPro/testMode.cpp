//TestMode.cpp
#include "TestMode.h"
TestMode::TestMode(QWidget* parent) :QMainWindow(parent) {
	QMessageBox::warning(this, tr("stop!"), tr("You are winner!!"));
}



LayoutTest::LayoutTest(QWidget* parent):QMainWindow(parent)
{
	//创建中心部件
	QWidget* centralWidget = new QWidget(this);
	setCentralWidget(centralWidget);

}

void LayoutTest::QHBoxLayoutTest()
{
	//创建按钮
	QPushButton* button1 = new QPushButton("Button 1", this);
	QPushButton* button2 = new QPushButton("Button 2", this);
	QPushButton* button3 = new QPushButton("Button 3", this);
	QPushButton* button4 = new QPushButton("Button 4", this);

	//创建水平布局
	QHBoxLayout* layout = new QHBoxLayout();

	//向布局中添加按钮
	layout->addWidget(button1);
	layout->addWidget(button2);
	layout->addWidget(button3);
	layout->addWidget(button4);

	//设置布局到中心部件
	QWidget* centralWidget = this->centralWidget();
	centralWidget->setLayout(layout);
}

void LayoutTest::QVBoxLayoutTest()
{
	//创建按钮
	QPushButton* button1 = new QPushButton("Button 1", this);
	QPushButton* button2 = new QPushButton("Button 2", this);
	QPushButton* button3 = new QPushButton("Button 3", this);
	QPushButton* button4 = new QPushButton("Button 4", this);

	//创建水平布局
	QVBoxLayout* layout = new QVBoxLayout();

	//向布局中添加按钮
	layout->addWidget(button1);
	layout->addWidget(button2);
	layout->addWidget(button3);
	layout->addWidget(button4);

	//设置布局到中心部件
	QWidget* centralWidget = this->centralWidget();
	centralWidget->setLayout(layout);

}

void LayoutTest::QGridLayoutTest()
{
	//创建按钮
	QPushButton* button1 = new QPushButton("Button 1", this);
	QPushButton* button2 = new QPushButton("Button 2", this);
	QPushButton* button3 = new QPushButton("Button 3", this);
	QPushButton* button4 = new QPushButton("Button 4", this);

	//创建水平布局
	QGridLayout* layout = new QGridLayout();

	//向布局中添加按钮
	layout->addWidget(button1,0,0);
	layout->addWidget(button2);
	layout->addWidget(button3);
	layout->addWidget(button4,1,1);

	//设置布局到中心部件
	QWidget* centralWidget = this->centralWidget();
	centralWidget->setLayout(layout);

}

QLabelTest::QLabelTest(QWidget* parent):QMainWindow(parent)
{

}

void QLabelTest::setTextTest()
{
	QLabel* label = new QLabel(this);

	label->setText("HelloWorld！");

	//label->setText("<h1><a href=\"https://www.baidu.com\">百度一下</a></h1>");
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

QLineEditTest::QLineEditTest(QWidget* parent):QMainWindow(parent)
{
	//创建一个QLineEdit
	QLineEdit* lineEdit = new QLineEdit(this);
	lineEdit->setPlaceholderText("please input text...");

	//创建一个按钮
	QPushButton* button = new QPushButton("get text", this);

	//创建布局并添加控件
	QGridLayout* layout = new QGridLayout(this);
	layout->addWidget(lineEdit,0,0);
	layout->addWidget(button,1,0);

	// 设置布局的间距和边距
	layout->setSpacing(10);  // 控件之间的间距
	layout->setContentsMargins(10, 10, 10, 10);  // 设置布局四周的边距

	// 设置窗口的中央布局
	QWidget* centralWidget = new QWidget(this);
	centralWidget->setLayout(layout);
	setCentralWidget(centralWidget);

	//当按钮被点击时获取QLineEdit中的文本
	connect(button, &QPushButton::clicked, this, [lineEdit]() {
		QString text = lineEdit->text();//获取输入的文本
		qDebug() << "output:" << text;
		});
}

SmallWidget::SmallWidget(QWidget* parent):QWidget(parent)
{
	//将组件放到父窗口parent
	spin = new QSpinBox(this);
	slider = new QSlider(Qt::Horizontal, this);

	//创建布局变量
	QHBoxLayout* layout = new QHBoxLayout;

	//将控件添加到布局中
	layout->addWidget(spin);
	layout->addWidget(slider);

	//将布局添加到窗口中
	setLayout(layout);

	connect(spin,
		static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
		slider, &QSlider::setValue);

	connect(slider, &QSlider::valueChanged,
		spin, &QSpinBox::setValue);


}


EventTest::EventTest()
{

}

EventTest::EventTest(QWidget* parent)
{
	setMouseTracking(true);  // 启用鼠标追踪
}

void EventTest::mouseMoveEvent(QMouseEvent* event)
{
	QPointF pos = event->position();  // 获取鼠标位置
	this->setText(QString("<center><h1>Move:(%1,%2)</h1></center>").
		arg(pos.x()).arg(pos.y()));
}

void EventTest::mousePressEvent(QMouseEvent* event)
{
	QPointF pos = event->position();  // 获取鼠标位置
	this->setText(QString("<center><h1>Press:(%1,%2)</h1></center>").
		arg(pos.x()).arg(pos.y()));
}

void EventTest::mouseReleaseEvent(QMouseEvent* event)
{
	QPointF pos = event->position();  // 获取鼠标位置
	QString msg = QString("Mouse released at position (%1, %2)").
		arg(pos.x()).arg(pos.y());
	this->setText(msg);
}

EventDistributeFunctionTest::EventDistributeFunctionTest(QWidget* parent):QWidget(parent)
{
	setFixedSize(400, 300);
}

bool EventDistributeFunctionTest::event(QEvent* event)
{

	//3 键盘按下事件
	if (event->type() == QEvent::KeyPress) {
		QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
		if (keyEvent->key() == Qt::Key_Space) {
			qDebug() << "空格键按下";
			return true;
		}

	}

	//1.1处理鼠标按下事件
	if (event->type() == QEvent::MouseButtonPress) {
		QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
		qDebug() << "鼠标被按下：" << mouseEvent->pos();
		return true;
	}

	//1.2处理键盘按下事件
	if (event->type() == QEvent::KeyPress) {
		QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
		qDebug() << "键盘被按下" << keyEvent->text();
		return true;
	}

	//1.3处理绘制事件
	if (event->type() == QEvent::Paint) {
		QPaintEvent* paintEvent = static_cast<QPaintEvent*>(event);
		QPainter painter(this);
		painter.setPen(Qt::red);
		painter.drawText(50, 50, "Hello,Event!");
		return true;//返回true，表示事件已经被处理
	}

	//2 拦截修改鼠标事件
	if (event->type() == QEvent::MouseButtonPress) {
		QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
		qDebug() << "鼠标按下" << mouseEvent->pos();
		return true;
	}


	//如果事件没有被处理，交给基类处理
	return QWidget::event(event);
}

EventFilterTest::EventFilterTest()
{
}

bool EventFilterTest::eventFilter(QObject *watched, QEvent *event)
{
	if (event->type() == QEvent::KeyPress)
	{
		QKeyEvent *keyEvent = static_cast <QKeyEvent *>(event);
		if (keyEvent->key() == Qt::Key_Enter) {
				qDebug() << "Enter key pressed!";
				return true;
			}
	}
	return QObject::eventFilter(watched,event);
}

TextEdit::TextEdit(QWidget* parent):QMainWindow(parent)
{
	textEdit = new QTextEdit(this);
	currentFilePath = "";
}

void TextEdit::runTest()
{
	//一、创建主窗口框架
	//1.创建菜单栏
	QMenuBar* menuBar = this->QMainWindow::menuBar();
	QMenu* fileMenu = menuBar->addMenu("文件");

	//创建菜单项
	QAction* openAction = new QAction(QIcon(":/images/file-open.png"), "打开", this);
	fileMenu->addAction(openAction);
	QAction* saveAction = new QAction(QIcon(":/images/file-save.png"), "保存", this);
	fileMenu->addAction(saveAction);
	QAction* newAction = new QAction(QIcon(":/images/file-new"), "新建", this);
	fileMenu->addAction(newAction);

	//创建工具栏
	QToolBar* toolBar = this->addToolBar("tool");
	toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::TopToolBarArea);
	toolBar->addAction(newAction );
	toolBar->addAction(openAction );
	toolBar->addAction(saveAction );


	//创建状态栏

	//2.创建中心部件和布局
	QWidget* centralWidget = new QWidget(this);
	QVBoxLayout* layout = new QVBoxLayout(centralWidget);

	setCentralWidget(centralWidget);

	layout->addWidget(textEdit);

	

	//设置窗口标题和图标
	setWindowTitle("文本剪辑器");
	setWindowIcon(QIcon(":/icons/textEdit"));
	resize(600, 400); // 设置窗口大小

	//3.菜单栏功能实现
	connect(openAction, &QAction::triggered, this, &TextEdit::openFile);
	connect(saveAction, &QAction::triggered, this, &TextEdit::saveFile);
	connect(newAction, &QAction::triggered, this, &TextEdit::newFile);



}

void TextEdit::openFile()
{
	if (!textEdit->toPlainText().isEmpty())
	{
		QMessageBox::StandardButtons reply;
		reply = QMessageBox::question(this, "新建文件", "当前文件尚未保存，是否保存？",
			QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
		if (reply == QMessageBox::Yes) {
			saveFile();//保存文件
		}
		else if (reply == QMessageBox::Cancel) {
			return;//取消新建操作
		}
	}
	QString path = QFileDialog::getOpenFileName(this, "打开文件", "", "TextFiles(*.txt);;All Files(*)");
	if (!path.isEmpty()) {
		QFile file(path);
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
			QMessageBox::warning(this,"警告", tr("找不到该文件").arg(path));
			return;
		}
		QTextStream in(&file);
		textEdit->setText(in.readAll());
		file.close();
		//更新窗口标题，显示文件名
		QFileInfo fileInfo(file);
		setWindowTitle(tr("文本编辑器 - %1").arg(fileInfo.fileName()));

		currentFilePath = path;
	}
	else
	{
		QMessageBox::warning(this, tr("path"),
			tr("You did not select any file."));

	}
}



void TextEdit::saveFile()
{
	QString path;
	if (currentFilePath.isEmpty())
	{
		path = QFileDialog::getSaveFileName(this, "保存文件", "", "Text Files(*.txt);;All files(*)");

		//取消操作
		if (path.isEmpty()) {
			return;
		}

		if (!path.endsWith(".txt", Qt::CaseInsensitive))
		{
			path += ".txt";
		}
	}
	else
	{
		path = currentFilePath;
	}

	QFile file(path);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		QMessageBox::warning(this, "警告", tr("无法保存该文件：%1").arg(path));
		return;
	}


	QTextStream out(&file);
	//写入文本框内容
	out << textEdit->toPlainText();
	file.close();

	currentFilePath = path;

	// 获取当前时间
	QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

	//保存完成后提示
	statusBar()->showMessage(tr("保存完成：%1[%2]").arg(path).arg(currentTime));  


}

void TextEdit::newFile()
{
	if (!textEdit->toPlainText().isEmpty())
	{
		QMessageBox::StandardButtons reply;
		reply = QMessageBox::question(this, "新建文件", "当前文件尚未保存，是否保存？",
			QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
		if (reply == QMessageBox::Yes) {
			saveFile();//保存文件
		}
		else if (reply == QMessageBox::Cancel) {
			return;//取消新建操作
		}
	}
	//清空文本编辑器内容
	textEdit->clear();
	setWindowTitle("新建文件--未保存");

}