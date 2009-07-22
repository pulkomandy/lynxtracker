
class NoteEntry
{
	private:
		uint16_t note;
		uint8_t instrument;
		uint8_t volume;
		char effect;
		uint8_t param;
		static const char note_2_text[12][3];

	public:
		NoteEntry();
		QString renderNote() const;
		QString renderInst() const;
		QString renderVol() const;
		QString renderFX() const;
		QString renderParam() const;

		bool setFX(QChar fx);
		void setParam(uint8_t newparam);
		void setInst(uint8_t newinst);
};


