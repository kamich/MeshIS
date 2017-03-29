#include "helloqt.h"
#include <qfiledialog.h>
#include <qmessagebox.h>
#include <qfile.h>
#include <qtextstream.h>
#include <qmessagebox.h>
#include <qsettings.h>

HelloQT::HelloQT(QWidget *parent)
	: QMainWindow(parent), maxRecFiles(5)
{
	ui.setupUi(this);
	//connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(open()));

	createActionsAndConnections();
	recFilesMenu();
}

HelloQT::~HelloQT()
{
	
}

// slots

void HelloQT::open()
{
	QString filePath = QFileDialog::getOpenFileName(
		this, tr("Open file"), "C://",
		tr("Text files(*.txt)"));

	if (!filePath.isEmpty())
		loadFile(filePath);
}

void HelloQT::openRec() {
	QAction *action = qobject_cast<QAction *>(sender());
	if (action)
		loadFile(action->data().toString());
}

// methods

void HelloQT::createActionsAndConnections()
{
	/*openAction = new QAction(tr("&Open..."), this);
	openAction->setShortcuts(QKeySequence::Open);
	connect(openAction, SIGNAL(triggered()),
		this, SLOT(open));*/

	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(open()));

	QAction* recentFileAction = 0;
	for (int i = 0; i < maxRecFiles; ++i) {
		recentFileAction = new QAction(this);
		recentFileAction->setVisible(false);
		connect(recentFileAction, SIGNAL(triggered()),
			this, SLOT(openRec));
		recFileActionList.append(recentFileAction);
	}
}

void HelloQT::recFilesMenu() {
	/*ui.menuMenu = ui.menuBar->addMenu(tr("&File"));
	ui.menuMenu->addAction(openAction);*/
	//ui.menuRecently_opened_files = ui.menuMenu->addMenu(tr("Open recent"));

	for (int i = 0; i < maxRecFiles; ++i)
		ui.menuRecently_opened_files->addAction(recFileActionList.at(i));

	updateRecentActionList();
}

void HelloQT::loadFile(const QString& filePath)
{
	QFile file(filePath);

	if (!file.open(QFile::ReadOnly)) {
		QMessageBox::warning(this, tr("Recent Files Example"),
			tr("This file could not be found:\n%1.")
			.arg(filePath));
		return;
	}

	QTextStream in(&file);
	ui.textBrowser->setText(in.readAll());

	adjustForCurrentFile(filePath);
}

void HelloQT::adjustForCurrentFile(const QString &filePath) {
	currentFilePath = filePath;
	setWindowFilePath(currentFilePath);

	QSettings settings;
	QStringList recentFilePaths =
		settings.value("recentFiles").toStringList();
	recentFilePaths.removeAll(filePath);
	recentFilePaths.prepend(filePath);
	while (recentFilePaths.size() > maxRecFiles)
		recentFilePaths.removeLast();
	settings.setValue("recentFiles", recentFilePaths);

	// see note
	updateRecentActionList();
}


void HelloQT::updateRecentActionList() {
	QSettings settings;
	QStringList recentFilePaths =
		settings.value("recentFiles").toStringList();

	auto toEnd = 0;
	if (recentFilePaths.size() <= maxRecFiles)
		toEnd = recentFilePaths.size();
	else
		toEnd = maxRecFiles;

	for (int i = 0; i < toEnd; ++i) {
		QString strippedName = QFileInfo(recentFilePaths.at(i)).fileName();
		recFileActionList.at(i)->setText(strippedName);
		recFileActionList.at(i)->setData(recentFilePaths.at(i));
		recFileActionList.at(i)->setVisible(true);
	}

	for (int i = toEnd; i < maxRecFiles; ++i)
		recFileActionList.at(i)->setVisible(false); // false 
}


