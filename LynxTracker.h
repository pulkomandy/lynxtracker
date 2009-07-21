#include <QVector>

#include "ui_LynxTracker.h"
#include "TrackView.h"

class LynxTracker : public QMainWindow
{
	Q_OBJECT

	public:
		LynxTracker(QMainWindow *parent = 0);
		~LynxTracker();

	private:
		Ui::MainWindow ui;
		QVector<TrackView*> Tracks;
};
