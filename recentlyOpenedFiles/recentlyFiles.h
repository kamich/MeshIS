#ifndef RecentlyFiles_H
#define RecentlyFiles_H

#include <QtWidgets/QMainWindow>
#include "ui_helloqt.h"
#include <Qlist>

class RecentlyFiles : public QMainWindow
{
	Q_OBJECT

public:
	RecentlyFiles(QWidget *parent = 0);

private:
	Ui::HelloQTClass ui;
	const int maxRecFiles;
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



#endif // RecentlyFiles_H
