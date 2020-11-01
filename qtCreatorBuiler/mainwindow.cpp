#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QFileDialog>


using namespace std;


QString binFolder;
QString buildFolder;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::on_pushButton_clicked()
{
	cout<<"trying system command"<<endl;

	binFolder = QFileDialog::getExistingDirectory(
				this,
				tr("open bin folder"),
				"c://"
				);

}

void MainWindow::on_pushButton_2_clicked()
{
	buildFolder = QFileDialog::getExistingDirectory(
				this,
				tr("open build folder"),
				"C:\\Users\\Lenna\\Documents\\qt"
				);
}

void MainWindow::on_pushButton_3_clicked()
{
	system("C:\\Qt\\5.15.1\\mingw81_64\\bin\\windeployqt.exe C:\\Users\\Lenna\\Documents\\qt\\qtCreatorBuiler\\build-qtCreatorBuiler-Desktop_Qt_5_15_1_MinGW_64_bit-Debug\\Debug");
	system("copy C:\\Qt\\5.15.1\\mingw81_64\\bin\\libgcc_s_seh-1.dll");
	system("copy C:\\Qt\\5.15.1\\mingw81_64\\bin\\libstdc++-6.dll");
	system("copy C:\\Qt\\5.15.1\\mingw81_64\\bin\\libwinpthread-1.dll");


}
//asd
