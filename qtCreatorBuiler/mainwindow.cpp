#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>



using namespace std;


int testbuildFolder = 0;
int testbinFolder = 0;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


	QFile file("testBinFolderFile.txt");

	file.open(QIODevice::ReadOnly);

	QTextStream in(&file);
	QString text = in.readAll();
	ui->binLineEdit->setText(text);
	file.close();


	QFile file1("testBuildFolderFile.txt");

	file1.open(QIODevice::ReadOnly);

	QTextStream in1(&file1);
	QString text1 = in1.readAll();
	ui->buildLineEdit->setText(text1);

	file.close();



}

MainWindow::~MainWindow()
{
	delete ui;
}






void MainWindow::on_pushButton_clicked()
{
	QString binFolder;

	binFolder = QFileDialog::getExistingDirectory(
				this,
				tr("open bin folder"),
				"c://"
				);
	QFile file("testBinFolderFile.txt");

	file.open(QIODevice::WriteOnly);

	QTextStream out(&file);
	QString text = binFolder;
	out << text;
	file.flush();
	file.close();

	ui->binLineEdit->setText(binFolder);


}

void MainWindow::on_pushButton_2_clicked()
{
	QString buildFolder;

	buildFolder = QFileDialog::getExistingDirectory(
				this,
				tr("open build folder"),
				"C:\\Users\\Lenna\\Documents\\qt"
				);
	QFile file("testBuildFolderFile.txt");

	file.open(QIODevice::WriteOnly);

	QTextStream out(&file);
	QString text = buildFolder;
	out << text;
	file.flush();
	file.close();

	ui->buildLineEdit->setText(buildFolder);

}



void MainWindow::on_pushButton_3_clicked()
{
	QString empts;


	if(ui->binLineEdit->text() != empts && ui->buildLineEdit->text() != empts){

	//system("C:/Qt/5.15.1/mingw81_64/bin/windeployqt.exe C:/Users/Lenna/Documents/qt/qtCreatorBuiler/build-qtCreatorBuiler-Desktop_Qt_5_15_1_MinGW_64_bit-Debug/Debug");
	//system("copy C:/Qt/5.15.1/mingw81_64/bin/libgcc_s_seh-1.dll");
	//system("copy C:\\Qt\\5.15.1\\mingw81_64\\bin\\libstdc++-6.dll");
	//system("copy C:\\Qt\\5.15.1\\mingw81_64\\bin\\libwinpthread-1.dll");

	} else if(ui->binLineEdit->text() == empts){
		QMessageBox::warning(this,"error", "remember to select a bin dir");

	} else if(ui->buildLineEdit->text() == empts){
		QMessageBox::warning(this,"error", "remember to select a build dir");
	} else{
		QMessageBox::warning(this,"error", "something went wrong, try to set the bin and build dir again");

	}


}
//asd
