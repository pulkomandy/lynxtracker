#include "LynxTracker.h"

LynxTracker::LynxTracker(QMainWindow* parent)
{
	ui.setupUi(this);
	ui.TrackEdit->setModel(&tv);
	ui.TrackEdit->resizeColumnsToContents();
	show();
}

LynxTracker::~LynxTracker()
{
}

