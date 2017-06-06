#include "markselection.h"
#include <qfile.h>
#include <qmessagebox.h>
#include <qtextstream.h>
#include <qfiledialog.h>
#include <qcolor.h>
#include <qpalette.h>
#include <qtextedit.h>
#include <qtablewidget.h>
#include <QTableWidgetItem>

markSelection::markSelection(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(openSelectionWindow()));
}

void markSelection::openSelectionWindow()
{
	QString filePath = QFileDialog::getOpenFileName(
		this, tr("Open file"), "C://",
		tr("Text files(*.txt)"));

	if (!filePath.isEmpty())
		loadFile(filePath);
}

void markSelection::loadFile(const QString& filePath)
{
	QFile file(filePath);

	if (!file.open(QFile::ReadOnly)) {
		QMessageBox::warning(this, tr("Recent Files Example"),
			tr("This file could not be found:\n%1.")
			.arg(filePath));
		return;
	}


	QTextStream in(&file);
	ui.tableWidget->setColumnCount(1);

	int rowNr = 0;
	while (!in.atEnd()) {
		auto line = in.readLine();
		auto item = new QTableWidgetItem(line);
		ui.tableWidget->insertRow(rowNr);
		ui.tableWidget->setItem(rowNr++, 0, item);
	}

	/*ui.textBrowser->moveCursor(QTextCursor::StartOfLine);
	ui.textBrowser->moveCursor(QTextCursor::EndOfLine, QTextCursor::KeepAnchor);*/
}

void markSelection::markLine()
{
	QTextEdit* edit = new QTextEdit;
	edit->moveCursor(QTextCursor::StartOfLine);
	edit->moveCursor(QTextCursor::EndOfLine, QTextCursor::KeepAnchor);
}