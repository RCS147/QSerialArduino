#ifndef INTERFACE
#define INTERFACE

#include <QWidget>
#include <QByteArray>
#include <QGridLayout>
#include <QPushButton>

#include "Arduino.h"
#include "Fader.h"

class Interface : public QWidget {

	Q_OBJECT

	public:
		Interface();
		~Interface();


	public slots:
		void updateValues();
			
	private:
		const static int colorMin = 0;
		const static int colorMax = 255;

		QByteArray RGB;

		Arduino* device;

		QGridLayout* layout;

		Fader* redFade;
		Fader* blueFade;
		Fader* greenFade;	

		QPushButton* sendMsgButton;
};
#endif
