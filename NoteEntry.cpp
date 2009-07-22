#include <QString>
#include <QTextStream>

#include "NoteEntry.h"

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
   	ts << effect ; 
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

bool NoteEntry::setFX(QChar fx)
{
	if(fx.isLetterOrNumber() || fx == '-')
	{
		effect=fx.toUpper().toAscii();
		return true;
	}
	return false;
}
