#ifndef MedallasH
#define MedallasH

class CMedallas {
public:
	CMedallas () : _oro(0), _plata(0), _bronce(0) {};
	CMedallas (int oro, int plata, int bronce) : _oro(oro), _plata(plata), _bronce(bronce) {};
	bool	operator< (const CMedallas &rhs) const;
	bool	operator== (const CMedallas &rhs) const;
	bool	operator> (const CMedallas &rhs) const;
	int		getOros() const { return this->_oro; }
	int		getPlatas () const { return this->_plata; }
	int		getBronces () const { return this->_bronce; }
	void		setOros(int oro) { _oro = oro; }
	void		setPlatas (int plata) { _plata = plata; }
	void		setBronces ( int bronce) { _bronce = bronce; }
private:
	int _oro;
	int _plata;
	int _bronce;
};

#endif