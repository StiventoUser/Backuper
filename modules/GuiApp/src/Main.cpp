#include "TabWidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	TabWidget tabdialog("fileName");

	tabdialog.show();

	return app.exec();
}
