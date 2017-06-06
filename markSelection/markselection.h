#ifndef MARKSELECTION_H
#define MARKSELECTION_H

#include <QtWidgets/QMainWindow>
#include "ui_markselection.h"

class markSelection : public QMainWindow
{
	Q_OBJECT

public:
	markSelection(QWidget *parent = 0);

private:
	Ui::markSelectionClass ui;
	void loadFile(const QString& filePath);

private slots:
	void openSelectionWindow();
	void markLine();
};

#endif // MARKSELECTION_H
