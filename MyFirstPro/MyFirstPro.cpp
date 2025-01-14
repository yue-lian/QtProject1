#include "MyFirstPro.h"




MyFirstPro::MyFirstPro(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
}

MyFirstPro::~MyFirstPro()
{}

void MyFirstPro::test1()
{
    QPushButton* btn = new QPushButton;
    //设置父亲
    btn->setParent(this);
    //设置文字
    btn->setText("AONY");
    //移动位置
    btn->move(100, 100);

    //第二种创建
    QPushButton* btn2 = new QPushButton("孙悟空", this);
    btn2->move(100, 200);
    //重新指定窗口大小
    this->resize(600, 400);
    //设置窗口标题
    this->setWindowTitle("My First Project");
    //限制窗口大小
    this->setFixedSize(600, 400);

    
}

Test01::Test01()
{
    connect(this, &Test01::sendSignal, this, &Test01::receiveSlot);
}

void Test01::test2()
{
    emit sendSignal(); // 触发信号
    
}

void Test02::lambdaTest()
{

    /*
    QWidget：最基础的窗口控件，用于承载其他控件。
    QVBoxLayout：一个布局管理器，用于将控件垂直排列。
    QLabel：显示文本或图像的控件，在此用来显示数字。
    QPushButton：一个按钮控件，用于响应用户点击事件。*/
    window = new QWidget(this);

    QVBoxLayout* layout = new QVBoxLayout(window);
    QLabel* label = new QLabel("0", window);
    QPushButton* button = new QPushButton("增加", window);
    
    //重新指定窗口大小
    this->resize(600, 400);

    layout->addWidget(label);
    layout->addWidget(button);

    //使用lambda表达式，传递当前值
    QObject::connect(button, &QPushButton::clicked, [label]() {
        int currentValue = label->text().toInt();
        label->setText(QString::number(currentValue + 1));
        });


}


Test03::Test03(QWidget* parent) :QMainWindow(parent) {

    QPushButton* button = new QPushButton("测试三的按钮", this);

    this->setCentralWidget(button);

    this->setWindowTitle("People");
    
    this->setWindowIcon(QIcon(":/icons/C:/Users/senlz/Pictures/icon/happyFruit.png"));

    resize(600, 400); // 设置窗口大小

    //五、QMainWindow
    //（1）菜单部分
    QMenuBar* menuBar = this->menuBar();
    //创建菜单
    QMenu* fileMenu = menuBar->addMenu("File");
    QMenu* editMenu = menuBar->addMenu("Edit");
    //创建菜单项
    //fileMenu->addAction("Open");   // 添加 "Open" 菜单项
    //editMenu->addAction("Paste");   // 添加 "Edit" 菜单项
    //菜单项动作
    QAction* openAction = new QAction(QIcon(":/icons/C:/Users/senlz/Pictures/icon/open.svg"), "Open", this);
    fileMenu->addAction(openAction);
    QAction* editAction = new QAction(QIcon(":/icons/C:/Users/senlz/Pictures/icon/paste.svg"), "Paste", this);
    editMenu->addAction(editAction);

    //（2）工具栏部分
    //创建工具栏
    QToolBar* toolBar = this->addToolBar("Main ToolBar");
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::TopToolBarArea);
    //将动作添加到工具栏
    toolBar->addAction(openAction);
    toolBar->addAction(editAction);

    //添加分隔符
    toolBar->addSeparator();

    //添加自定义按钮到工具栏
    button = new QPushButton("custom", this);
    toolBar->addWidget(button);

    //连接槽函数
    connect(openAction, &QAction::triggered, this, []() {
        qDebug() << "open action triggered!";
        });

    //（3）状态栏
    //创建状态栏
    QStatusBar* statusBar = this->statusBar();
    //显示消息（这边会覆盖下面的进度条）
    //statusBar->showMessage("正在加载数据...",2000);

    //进度条
    QProgressBar* progressBar = new QProgressBar(this);
    progressBar->setRange(0, 100);
    statusBar->addWidget(progressBar);

    //显示标签
    // 创建一个用于显示“加载完成”的标签
    QLabel* statusLabel = new QLabel(this);
    statusBar->addWidget(statusLabel);

    //模拟进度条更新
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [progressBar]() {
        int value = progressBar->value() + 10;
        if (value <= 100) {
            progressBar->setValue(value);
        }
        else {
            progressBar->setValue(100);

        }
        });
    timer->start(500);  // 每500毫秒更新一次进度条

    // 5. 显示一条短暂的消息
    //statusBar->showMessage("加载完成", 2000);  // 2秒后自动清除

    //（4）停靠部件（铆接部件、浮动窗口）
    QDockWidget* dock = new QDockWidget("停靠部件左上右", this);
    addDockWidget(Qt::LeftDockWidgetArea, dock);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea |
        Qt::RightDockWidgetArea | Qt::TopDockWidgetArea);

    //（5）核心部件（中心部件 QTextEdit--编辑框控件）
    QTextEdit* edit = new QTextEdit(this);
    setCentralWidget(edit);

    //六、QDialog对话框

    //（1）模态对话框
    /*
    * 1.应用程序级别的模态
        当该种模态的对话框出现时，用户必须首先对对话框进行交互，
        直到关闭对话框，然后才能访问程序中其他的窗口。
        使用QDialog::exec()实现应用程序级别的模态对话框
    * 2.窗口级别的模态
        该模态仅仅阻塞与对话框关联的窗口，但是依然允许用户与程序中其它窗口交互。
        窗口级别的模态尤其适用于多窗口模式。
        使用QDialog::open()实现窗口级别的模态对话框
        
    *  一般情况下我们只使用应用程序级别的模态对话框。
    */
    QDialog dialog;
    dialog.setWindowTitle(tr("Hello, dialog!"));

    //添加按钮，用于打开模态和非模态对话框
    QPushButton* modalDialogButton = new QPushButton("打开模态对话框", this);
    QPushButton* nonModalDialogButton = new QPushButton("打开非模态对话框", this);
    modalDialogButton->move(200, 40);
    nonModalDialogButton->move(400, 40);

   
    connect(modalDialogButton, &QPushButton::clicked, this, &Test03::showModalDialog);

    //（2）非模态对话框

    connect(nonModalDialogButton, &QPushButton::clicked, this, &Test03::showNonModalDialog);



}

void Test03::showModalDialog()
{
    //创建一个模态对话框
    QDialog dialog(this);
    dialog.setWindowTitle("模态对话框");
    dialog.setFixedSize(300,200);

    //对话框内容布局
    QVBoxLayout* layout = new QVBoxLayout(&dialog);
    QLabel* label = new QLabel("这是一个模态对话框", &dialog);
    QPushButton* closeButton = new QPushButton("关闭", &dialog);

    layout->addWidget(label);
    layout->addWidget(closeButton);

    //连接关闭按钮
    connect(closeButton, &QPushButton::clicked,&dialog, &QDialog::accept);

    dialog.exec();
}

void Test03::showNonModalDialog()
{
    //创建一个非模态对话框
    QDialog* dialog = new QDialog(this);//用指针，方便销毁
    dialog->setWindowTitle("非模态对话框");
    dialog->setFixedSize(300, 200);

    //对话框内容布局
    QVBoxLayout* layout = new QVBoxLayout(dialog);
    QLabel* label = new QLabel("这是一个非模态对话框", dialog);
    QPushButton* closeButton = new QPushButton("关闭", dialog);

    layout->addWidget(label);
    layout->addWidget(closeButton);
    //QMessageBox::information(this, "信息", "这是一个信息框");

    //连接关闭按钮
    connect(closeButton, &QPushButton::clicked, dialog, &QDialog::close);
    //显示非模态对话框，不阻塞当前窗口
    dialog->show();
    //控制台打印
    qDebug() << "非模态对话框打开";
}

void Test03::test1()
{
    // 信息框
    QMessageBox::information(this, "信息框", "操作成功完成！");

    // 警告框
    QMessageBox::warning(this, "警告框", "这是一个警告信息！");

    // 错误框
    QMessageBox::critical(this, "错误框", "发生了严重错误，请重试！");

    // 确认框
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "确认框", "是否确定退出？",
        QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        qDebug() << "用户选择了是";
    }
    else {
        qDebug() << "用户选择了否";
    }

    // 自定义消息框
    QMessageBox msgBox;
    msgBox.setWindowTitle("自定义消息框");
    msgBox.setText("请选择操作：");
    QPushButton* yesButton = msgBox.addButton("是", QMessageBox::AcceptRole);
    QPushButton* noButton = msgBox.addButton("否", QMessageBox::RejectRole);
    msgBox.exec();

    if (msgBox.clickedButton() == yesButton) {
        qDebug() << "用户点击了是";
    }
    else if (msgBox.clickedButton() == noButton) {
        qDebug() << "用户点击了否";
    }

}

Test04::Test04(QWidget* parent) :QMainWindow(parent)
{
    textEdit = nullptr;
}

void Test04::textEditFunc()
{
    QPushButton* button = new QPushButton("测试三的按钮", this);

    this->setCentralWidget(button);

    this->setWindowTitle("People");

    this->setWindowIcon(QIcon(":/icons/C:/Users/senlz/Pictures/icon/happyFruit.png"));

    resize(600, 400); // 设置窗口大小


    QAction* openAction = new QAction(QIcon(":/images/file-open"), tr("&Open..."), this);
    openAction->setStatusTip(tr("Open an existing file"));
    QAction* saveAction = new QAction(QIcon(":/images/file-save"), tr("&Save..."), this);
    saveAction->setStatusTip(tr("Save a new file"));
    QMenu* file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);
    file->addAction(saveAction);

    QToolBar* toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);
    toolBar->addAction(saveAction);

    textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);

    connect(openAction, &QAction::triggered,
        this, &Test04::openFile);
    connect(saveAction, &QAction::triggered,
        this, &Test04::saveFile);
}


void Test04::openFile()
{
    QString path = QFileDialog::getOpenFileName(this,
        tr("openFile"), ".", tr("TextFiles(*.txt)"));
    if (!path.isEmpty()) {
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, tr("Read File"),
                tr("Cannot open file:\n%1").arg(path));
            return;
        }
        QTextStream in(&file);
        textEdit->setText(in.readAll());
        file.close();
    }
    else {
        QMessageBox::warning(this, tr("path"),
            tr("You did not select any file."));
    }
}

void Test04::saveFile()
{
    QString path = QFileDialog::getSaveFileName(this,
        tr("OpenFile"), ".", tr("TextFiles(*.txt)"));
    if (!path.isEmpty()) {
        QFile file(path);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::warning(this, tr("Write File"),
                tr("Cannot open file:\n%1").arg(path));
            return;
        }
        QTextStream out(&file);
        out << textEdit->toPlainText();
        file.close();

    }
    else
    {
        QMessageBox::warning(this, tr("Path"),
            tr("You did not select any file."));
    }
}

