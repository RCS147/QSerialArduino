#include "Fader.h"
#include <QDebug>

Fader::Fader(QString str, int m, int n)
{
	layout = new QVBoxLayout();

	name = str;
	min = m;
	max = n;

	label = new QLabel(name);
	layout->addWidget(label, 0, Qt::AlignHCenter);
		
	slide = new QSlider();
	slide->setMaximum(max);
	slide->setMinimum(min);
	layout->addWidget(slide, 0, Qt::AlignHCenter);

	QObject::connect(slide, SIGNAL(valueChanged(int)), this, SLOT(setValue(int)));
	
	box = new QSpinBox();
	box->setRange(min, max);
	layout->addWidget(box, 0, Qt::AlignHCenter);

	QObject::connect(box, SIGNAL(valueChanged(int)), this, SLOT(setValue(int)));

	value = min;

	this->setLayout(layout);		
}

Fader::~Fader()
{
}

void Fader::setRange(int m, int n)
{
	min = m;
	max = n;
}

void Fader::setName(QString n)
{
	name = n;
}

int Fader::getValue()
{
	return value;
}

void Fader::setValue(int val)
{
	if(val > max) { val = max; }
	if(val < min) { val = min; }
		
	value = val;
	update();
}

void Fader::update()
{
	box->setValue(value);
	slide->setValue(value);
	emit valueChanged(value);
}
