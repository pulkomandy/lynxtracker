#include <QAbstractTableModel>

#include "NoteEntry.h"

class TrackView: public QAbstractTableModel
{
	public:
		TrackView();

		int rowCount(const QModelIndex & parent = QModelIndex()) const ; 
		int columnCount(const QModelIndex & parent = QModelIndex()) const ;
		Qt::ItemFlags flags(const QModelIndex& index) const;
		QVariant data(const QModelIndex & index, int role = Qt::DisplayRole)
			const ;
		bool setData (const QModelIndex & index, const QVariant & value,
			int role = Qt::EditRole ) ;
		QVariant headerData ( int section, Qt::Orientation orientation,
			int role = Qt::DisplayRole ) const ;

		// TODO...
		//**edition
		//setData
		//flags
	private:

		// TODO: handle end of pattern
		static const int length = 0x40;

		NoteEntry notes[4][length];
};
