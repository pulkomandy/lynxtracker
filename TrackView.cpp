#include <QMessageBox>
#include <QString>
#include <QTextStream>

#include "TrackView.h"

NoteEntry::NoteEntry()
{
	note = volume = param = 0;
	effect = '-';
}

QString NoteEntry::renderNote() const
{
	QString text;
	QTextStream ts(&text);

	if (note == 0) ts << "---" ;
	else
	{
		ts << note_2_text[(note-1)%12] // Note name (with #)
	   	   << (note-1)/12 ; // octave
	}
	return text;
}

const char NoteEntry::note_2_text[12][3] =
{
	"C-",
	"C#",
	"D-",
	"D#",
	"E-",
	"F-",
	"F#",
	"G-",
	"G#",
	"A-",
	"A#",
	"B-"
};

QString NoteEntry::renderVol() const
{
	QString text;
	QTextStream ts(&text);
	ts.setIntegerBase(16);
	ts << volume; 
	return text;
}

QString NoteEntry::renderFX() const
{
	QString text;
	QTextStream ts(&text);
   	ts	<< effect ; 
	return text;
}

QString NoteEntry::renderParam() const
{
	QString text;
	QTextStream ts(&text);
	ts.setIntegerBase(16);
	right(ts).setFieldWidth(2);
 	ts.setPadChar('0');
	ts	<< param ;
	return text;

	return text;
}

void NoteEntry::setFX(char fx)
{
	effect=fx;
}

//------------------------------------------------------------------------------

TrackView::TrackView()
{
}

int TrackView::rowCount(const QModelIndex & parent) const 
{
	return length;
}

int TrackView::columnCount(const QModelIndex & parent) const
{
	return 16;
}

Qt::ItemFlags TrackView::flags(const QModelIndex &index) const
{
	if (!index.isValid())
		return Qt::ItemIsEnabled;

	return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

QVariant TrackView::data(const QModelIndex & index, int role) const
{
	if(role == Qt::DisplayRole)
	{
		switch(index.column()%4)
		{
			case 0: return QVariant(notes[index.column()/4][index.row()]
				.renderNote());
			case 1: return QVariant(notes[index.column()/4][index.row()]
				.renderVol());
			case 2: return QVariant(notes[index.column()/4][index.row()]
				.renderFX());
			case 3: return QVariant(notes[index.column()/4][index.row()]
				.renderParam());
		}
	}

	// Other roles : nothing for now
	return QVariant();
}

bool TrackView::setData (const QModelIndex & index, const QVariant & value,
	int role)
{
	if(role== Qt::EditRole)
	{	
		QMessageBox msgBox;
		msgBox.setText("The document has been modified.");
		msgBox.exec();
		switch(index.column()%4)
		{
			case 2: notes[index.column()/4][index.row()].setFX(value.toChar().toAscii());
				dataChanged(index,index);
				return true;
			default: return false;
		}
	}
	else
		return false;
}

QVariant TrackView::headerData ( int section, Qt::Orientation orientation, 
	int role) const
{
	if(role == Qt::DisplayRole)
	{
		if(orientation == Qt::Vertical)
		{
			QString text;
			QTextStream ts(&text);
			ts.setIntegerBase(16);
			right(ts).setFieldWidth(2);
 			ts.setPadChar('0');
			ts << section;
			return text;
		}
		else
			switch(section%4)
			{
				case 0: return QVariant("Nte");
				case 1: return QVariant("V");
				case 2: return QVariant("F");
				case 3: return QVariant("Param");
			}
	}

	// Other roles: use default value
	return QAbstractTableModel::headerData(section,orientation,role);
}
