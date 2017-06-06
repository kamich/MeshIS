#include "markselection.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	markSelection w;
	w.show();
	return a.exec();
}
