#include <QMainWindow>
#include "LynxTracker.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	LynxTracker lt;

	return app.exec();
}
