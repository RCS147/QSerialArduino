#include "Arduino.h"

#include <QByteArray>

Arduino::Arduino(QObject* parent) : 
	QObject(parent)
{
	serial = new QSerialPort();
	serial->setPortName("ttyACM0");
	serial->open(QIODevice::ReadWrite);
	serial->setBaudRate(QSerialPort::Baud9600);
	serial->setDataBits(QSerialPort::Data8);
	serial->setParity(QSerialPort::NoParity);
	serial->setStopBits(QSerialPort::OneStop);
	serial->setFlowControl(QSerialPort::NoFlowControl);
		qDebug() << "Is Open		: " << serial->isOpen();
		qDebug() << "Is Writable	; " << serial->isWritable();

	info = new QSerialPortInfo("ttyACM0");
		qDebug() << "Name		: " << info->portName();
		qDebug() << "Manufacturer	: " << info->manufacturer();
		qDebug() << "Busy		: " << info->isBusy();
}

Arduino::~Arduino()
{
}

bool Arduino::sendMessage(QByteArray msg)
{
	if(!serial->isOpen())
	{
		qDebug() << "ERROR: Port is not open";
		return false;
	}

	if(!serial->isWritable())
	{
		qDebug() << "ERROR: Port is not writable";
		return false;
	}

	if(msg.isEmpty())
	{
		qDebug() << "ERROR: Nothing to write";
		return false;
	}

	if(serial->write(msg) != msg.size())
	{
		qDebug() << "ERROR: Failed to write message";
		return false;
	}

	qDebug() << "Message sent";
	return true;
}
