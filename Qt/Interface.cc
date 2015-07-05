#include "Interface.h"

Interface::Interface()
{
	device = new Arduino();

	layout = new QGridLayout();
	
	redFade = new Fader("Red", colorMin, colorMax);
	greenFade = new Fader("Green", colorMin, colorMax);
	blueFade = new Fader("Blue", colorMin, colorMax);

	QObject::connect(redFade, SIGNAL(valueChanged(int)), this, SLOT(updateValues()));
	QObject::connect(greenFade, SIGNAL(valueChanged(int)), this, SLOT(updateValues()));
	QObject::connect(blueFade, SIGNAL(valueChanged(int)), this, SLOT(updateValues()));
	
	layout->addWidget(redFade, 0, 0, 1, 1);
	layout->addWidget(greenFade, 0, 1, 1, 1);
	layout->addWidget(blueFade, 0, 2, 1, 1);
	
	this->setWindowTitle("Pick a Color");
	this->setLayout(layout);
}

Interface::~Interface()
{
	delete device;
}

void Interface::updateValues() 
{
	RGB.clear();
	RGB.append((char) redFade->getValue());
	RGB.append((char) greenFade->getValue());
	RGB.append((char) blueFade->getValue());
	device->sendMessage(RGB);
}

