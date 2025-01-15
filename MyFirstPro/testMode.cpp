//TestMode.cpp
#include "TestMode.h"
TestMode::TestMode(QWidget* parent) :QMainWindow(parent) {
}

void TestMode::test(QWidget* parent) {
	//qDebug() << "HelloWorld";
	QMessageBox::warning(this, tr("stop!"), tr("You are winner!!"));
}
