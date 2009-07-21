#include "TrackView.h"

TrackView::TrackView()
{
	for(int i = 0; i<length;i++)
	{
		strcpy(notes[i].note,"--");
		notes[i].octave = 0;
		notes[i].volume = 0;
		strcpy(notes[i].effect,"-");
		notes[i].param = 0;
	}
}

int TrackView::rowCount(const QModelIndex & parent) const 
{
	return length;
}

int TrackView::columnCount(const QModelIndex & parent) const
{
	return 5;
}

QVariant TrackView::data(const QModelIndex & index, int role) const
{
	if(role == Qt::DisplayRole)
	{
		switch(index.column())
		{
			case 0: return QVariant(notes[index.row()].note);
			case 1: return QVariant(notes[index.row()].octave);
			case 2: return QVariant(notes[index.row()].volume);
			case 3: return QVariant(notes[index.row()].effect);
			case 4: return QVariant(notes[index.row()].param);
		}
	}
	return QVariant();
}

QVariant TrackView::headerData ( int section, Qt::Orientation orientation, int role) const
{
	if(role == Qt::DisplayRole)
	{
		if(orientation == Qt::Vertical)
			// TODO display it in hex
			return section;
		else
			switch(section)
			{
				case 0: return QVariant("Note");
				case 1: return QVariant("Oct");
				case 2: return QVariant("Vol");
				case 3: return QVariant("FX");
				case 4: return QVariant("Param");
			}
	}
	return QAbstractTableModel::headerData(section,orientation,role);
}
