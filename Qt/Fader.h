#ifndef FADER
#define FADER

#include <QWidget>
#include <QSlider>
#include <QLabel>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QString>

class Fader : public QWidget {

	Q_OBJECT

	public:
		Fader(QString str = "", int m = 0, int n = 10);
		~Fader();

		void setRange(int n, int m);
		void setName(QString n);

		int getValue();
	
	public slots:
		void setValue(int val);
		void update();

	signals:
		void valueChanged(int val);

	private:
		int max;
		int min;

		int value;

		QString name;

		QVBoxLayout* layout;

		QSlider* slide;
		QSpinBox* box;
		QLabel* label;

};
#endif
