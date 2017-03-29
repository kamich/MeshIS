#ifndef HELLOQT_H
#define HELLOQT_H

#include <QtWidgets/QMainWindow>
#include "ui_helloqt.h"
#include <Qlist>

class HelloQT : public QMainWindow
{
	Q_OBJECT

public:
	HelloQT(QWidget *parent = 0);
	~HelloQT();

private:
	Ui::HelloQTClass ui;
	const int maxRecFiles;
	/*QAction* openAction;*/
	QList <QAction*> recFileActionList;
	QString currentFilePath;

	void loadFile(const QString& filePath);
	void adjustForCurrentFile(const QString &filePath);
	void recFilesMenu();
	void createActionsAndConnections();
	void updateRecentActionList();

	private slots:
		void open();
		void openRec();
};



#endif // HELLOQT_H
