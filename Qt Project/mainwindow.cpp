#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "functionlib.h"
#include <QProcess>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	on_pushRefresh_clicked();

}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::on_pushRefresh_clicked()
{
	ui->pushMunge->setDisabled(false);
	inputFileList.clear();
	ui->listWidget->clear();
	//ui->labelMessage->clear();
	ui->labelMessage->setHidden(true);

	if(!QFile::exists("CustomLVL/munge.bat"))
	{
		//ui->labelMessage->setText("Error: _BUILD/CustomLVL/munge.bat not found!");
		ui->labelMessage->setHidden(false);
		ui->pushMunge->setDisabled(true);
	}

	initList(inputFileList);

	std::cout << inputFileList << std::endl;

	for(QStringList::iterator it = inputFileList.begin(); it != inputFileList.end(); it++)
	{
		QListWidgetItem* item = new QListWidgetItem(*it, ui->listWidget);
		item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
		item->setCheckState(Qt::Unchecked);
	}
}

void MainWindow::on_pushMunge_clicked()
{
	QProcess process;

	for(int index = 0; index < ui->listWidget->count(); index++)
	{
		if(ui->listWidget->item(index)->checkState())
		{
			process.start("CustomLVL\\munge.bat", QStringList() << ui->lineEditPlattform->text() << ui->listWidget->item(index)->text());
			process.waitForFinished();
			copyFile(ui->listWidget->item(index)->text(), ui->lineEditPlattform->text());
		}
	}

	QDir cleanUp(QDir::currentPath());
	cleanUp.rmdir("MUNGED");
	QFile::copy(QDir::currentPath() + "/configmunge_fx.log", QDir::currentPath() + "/CustomLVL/configmunge_fx.log");
	QFile::copy(QDir::currentPath() + "/configmunge_mcfg.log", QDir::currentPath() + "/CustomLVL/configmunge_mcfg.log");
	QFile::copy(QDir::currentPath() + "/fontmunge.log", QDir::currentPath() + "/CustomLVL/fontmunge.log");
	QFile::copy(QDir::currentPath() + "/levelpack.log", QDir::currentPath() + "/CustomLVL/levelpack.log");
	QFile::copy(QDir::currentPath() + "/PC_modelmunge.log", QDir::currentPath() + "/CustomLVL/PC_modelmunge.log");
	QFile::copy(QDir::currentPath() + "/PC_texturemunge.log", QDir::currentPath() + "/CustomLVL/PC_texturemunge.log");
	QFile::copy(QDir::currentPath() + "/scriptmunge.log", QDir::currentPath() + "/CustomLVL/scriptmunge.log");

	QFile::remove(QDir::currentPath() + "/configmunge_fx.log");
	QFile::remove(QDir::currentPath() + "/configmunge_mcfg.log");
	QFile::remove(QDir::currentPath() + "/fontmunge.log");
	QFile::remove(QDir::currentPath() + "/levelpack.log");
	QFile::remove(QDir::currentPath() + "/PC_modelmunge.log");
	QFile::remove(QDir::currentPath() + "/PC_texturemunge.log");
	QFile::remove(QDir::currentPath() + "/scriptmunge.log");

}

void MainWindow::on_pushClean_clicked()
{
	QDir buildDir(QDir::currentPath() + "/CustomLVL/MUNGED");
	QDir mungedDir(QDir::currentPath() + "/../_LVL_" + ui->lineEditPlattform->text() + "/CustomLVL");

	buildDir.removeRecursively();
	mungedDir.removeRecursively();

	for(int index = 0; index < ui->listWidget->count(); index++)
	{
		if(ui->listWidget->item(index)->checkState())
			deleteFile(ui->listWidget->item(index)->text());
	}

	QFile::remove(QDir::currentPath() + "/CustomLVL/configmunge_fx.log");
	QFile::remove(QDir::currentPath() + "/CustomLVL/configmunge_mcfg.log");
	QFile::remove(QDir::currentPath() + "/CustomLVL/fontmunge.log");
	QFile::remove(QDir::currentPath() + "/CustomLVL/levelpack.log");
	QFile::remove(QDir::currentPath() + "/CustomLVL/PC_modelmunge.log");
	QFile::remove(QDir::currentPath() + "/CustomLVL/PC_texturemunge.log");
	QFile::remove(QDir::currentPath() + "/CustomLVL/scriptmunge.log");

}

void MainWindow::on_pushSelection_clicked()
{
	Qt::CheckState value = Qt::Checked;

	if(ui->pushSelection->text() == "unselect all")
	{
		value = Qt::Unchecked;
		ui->pushSelection->setText("select all");
	}
	else
		ui->pushSelection->setText("unselect all");

	for(int index = 0; index < ui->listWidget->count(); index++)
		ui->listWidget->item(index)->setCheckState(value);

}

