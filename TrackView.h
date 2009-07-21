#include <QAbstractTableModel>

class NoteEntry
{
	private:
		uint16_t note;
		uint8_t volume;
		char effect;
		uint8_t param;
		static const char note_2_text[12][3];

	public:
		NoteEntry();
		QString renderNote() const;
		QString renderVol() const;
		QString renderFX() const;
		QString renderParam() const;
};


class TrackView: public QAbstractTableModel
{
	public:
		TrackView();

		int rowCount(const QModelIndex & parent = QModelIndex()) const ; 
		int columnCount(const QModelIndex & parent = QModelIndex()) const ;
		QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const ;
		QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const ;

		// TODO...
		//**edition
		//setData
		//flags
	private:

		// TODO: handle end of pattern
		static const int length = 0x40;

		NoteEntry notes[4][length];
};
