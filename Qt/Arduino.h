#ifndef ARDUINO
#define ARDUINO

#include <QtSerialPort>
#include <QObject>

class Arduino : public QObject{

	Q_OBJECT

	public:
		Arduino(QObject* parent = 0);
		~Arduino();

	public slots:	
		bool sendMessage(QByteArray msg);
	
	private:
		QSerialPort* serial;
		QSerialPortInfo* info;
};

#endif
