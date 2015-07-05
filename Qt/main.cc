#include <QtGui>
#include <QtSerialPort>
#include <QtWidgets>
#include <iostream>

#include "Arduino.h"
#include "Interface.h"

QT_USE_NAMESPACE

static int colorMax = 255;
static int colorMin = 0;
int colorRed, colorGreen, colorBlue;

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	Interface* window = new Interface();
	window->show();

	return app.exec();
}
