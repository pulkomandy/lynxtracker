#include <QAbstractTableModel>

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
		typedef struct
		{
			char note[3];
			uint8_t octave;
			uint8_t volume;
			char effect[2];
			uint8_t param;
		} NoteEntry;

		// TODO: handle end of pattern
		static const int length = 0x40;

		NoteEntry notes[length];
};
