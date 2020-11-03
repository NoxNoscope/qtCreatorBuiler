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

	string x = ui->binLineEdit->text().toStdString();
	string y = ui->buildLineEdit->text().toStdString();

	string buildCommand = x + "/windeployqt.exe " + y;
	string buildBinaryCommand = x + "/binarycreator.exe " + y;


	QString copyMissing1 = ui->binLineEdit->text() + "/libgcc_s_seh-1.dll";
	QString copyMissing2 = ui->binLineEdit->text() + "/libstdc++-6.dll";
	QString copyMissing3 = ui->binLineEdit->text() + "/libwinpthread-1.dll";


	if(ui->binLineEdit->text() != empts && ui->buildLineEdit->text() != empts){
		cout << "build command" << endl;
		system(buildCommand.c_str());

		cout << "copy1 command" << endl;
		QFile::copy(copyMissing1, ui->buildLineEdit->text());

		cout << "copy2 command" << endl;
		QFile::copy(copyMissing2, ui->buildLineEdit->text());

		cout << "copy3 command" << endl;
		QFile::copy(copyMissing3, ui->buildLineEdit->text());

	} else if(ui->binLineEdit->text() == empts){
		QMessageBox::warning(this,"error", "remember to select a bin dir");

	} else if(ui->buildLineEdit->text() == empts){
		QMessageBox::warning(this,"error", "remember to select a build dir");
	} else{
		QMessageBox::warning(this,"error", "something went wrong, try to set the bin and build dir again");
	}




}
//asd
