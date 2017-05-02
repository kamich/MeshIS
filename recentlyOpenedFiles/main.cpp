#include "recentlyFiles.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setApplicationName("RecentFiles");
	a.setOrganizationName("TXT reader with option to re-open");
	RecentlyFiles w;
	w.show();
	return a.exec();
}
