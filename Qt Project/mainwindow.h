#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
		Q_OBJECT

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();

	private slots:


	void on_pushRefresh_clicked();

	void on_pushClean_clicked();

	void on_pushMunge_clicked();

	void on_pushSelection_clicked();

private:
		Ui::MainWindow *ui;
		QStringList inputFileList;
};

#endif // MAINWINDOW_H
