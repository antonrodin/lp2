#ifndef CParejaH
#define CParejaH

template <class TValor1, class TValor2>
class CPareja {
public:
	//Constructors
	CPareja();
	CPareja(const TValor1& v1, const TValor2& v2);

	//Accessors and Modifiers
	const TValor1& v1() const;
	const TValor2& v2() const;
	void ponV1(const TValor1& v1);
	void ponV2(const TValor2& v2);
	
private:
	TValor1 _v1;
	TValor2 _v2;
};

template <class TValor1, class TValor2>
CPareja<TValor1, TValor2>::CPareja() {
}

template <class TValor1, class TValor2>
CPareja<TValor1, TValor2>::CPareja(const TValor1& v1,const TValor2& v2) {
	_v1 = v1;
	_v2 = v2;
}

template <class TValor1, class TValor2>
const TValor1& CPareja<TValor1, TValor2>::v1() const {
	return _v1;
}

template <class TValor1, class TValor2>
const TValor2& CPareja<TValor1, TValor2>::v2() const {
	return _v2;
}


template <class TValor1, class TValor2>
void CPareja<TValor1, TValor2>::ponV1(const TValor1& v1) {
	_v1 = v1;
}

template <class TValor1, class TValor2>
void CPareja<TValor1, TValor2>::ponV2(const TValor2& v2) {
	_v2 = v2;
}

#endif

