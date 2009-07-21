#include "LynxTracker.h"

LynxTracker::LynxTracker(QMainWindow* parent)
{
	ui.setupUi(this);
	Tracks << new TrackView // Empty track
	<< new TrackView
	<< new TrackView
	<< new TrackView
	<< new TrackView ;
	ui.TrackEdit1->setModel(Tracks[1]);
	ui.TrackEdit1->resizeColumnsToContents();
	ui.TrackEdit2->setModel(Tracks[2]);
	ui.TrackEdit2->resizeColumnsToContents();
	ui.TrackEdit3->setModel(Tracks[3]);
	ui.TrackEdit3->resizeColumnsToContents();
	ui.TrackEdit4->setModel(Tracks[4]);
	ui.TrackEdit4->resizeColumnsToContents();
	show();
}

LynxTracker::~LynxTracker()
{
	TrackView* t;
	foreach(t,Tracks)
	{
		delete t;
	}
}

