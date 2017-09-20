// Saisies.c

# include <iostream>
# include <sstream>
# include <cassert>
# include <string>
# include "Saisies.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

namespace le7_saisies
{
	Saisies::Saisies() : _eSaisie (Esaisie::nilValue)
	{
	}

	Saisies::Saisies (const Saisies& s)
	{
		if (this != &s)
		{
			_sPayload = s._sPayload;
			_iPayload = s._iPayload;
			_eSaisie = s._eSaisie;
		}
	}

	Saisies& Saisies::operator = (const Saisies& s)
	{
		if (this != &s)
		{
			_sPayload = s._sPayload;
			_iPayload = s._iPayload;
			_eSaisie = s._eSaisie;
		}

		return *this;
	}

	Esaisie Saisies::get(string invite)
	{
		cout << invite ;
		string sDummy;
		getline(cin, sDummy);
		std::stringstream ssDummy(sDummy);

		if (isNumber() == true)
		{
			ssDummy >> _iPayload;

			if (ssDummy.good ())
			{
				_eSaisie = Esaisie::errValue;
			}
			else
			{
				_eSaisie = Esaisie::iValue;
			}
		}
		else
		{
			ssDummy >> _sPayload;

			if (ssDummy.good ())
			{
				_eSaisie = Esaisie::errValue;
			}
			else
			{
				_eSaisie = Esaisie::sValue;
			}
		}
		
		return _eSaisie;
		/*
		ssDummy >> _sPayload;
		_eSaisie = Esaisie::sValue;

		try
		{
			std::stoi(_sPayload);
			_eSaisie = Esaisie::iValue;
		}
		catch (const std::exception& e)
		{
			cout << "Hebe non, pas un entier <" << e.what() << ">" << endl;
		}

		if (_eSaisie == Esaisie::nilValue)
		{
			//_eSaisie = Esaisie::errValue;
		}
		*/

		/*
		if (ssDummy >> _iPayload)
		{
			_eSaisie = Esaisie::iValue;
		}
		else
		{
			if (ssDummy >> _sPayload)
			{
				_eSaisie = Esaisie::sValue;
			}
			else
			{
				_eSaisie = Esaisie::errValue;
			}
		}
		*/
	}

	inline bool Saisies::isNumber(void) 
	{
		std::stringstream ssDummy;
		float fDummy = 0 ;

		ssDummy << _sPayload;
		ssDummy >> fDummy;

		return (ssDummy.good() == true ? false : (fDummy == 0 && _sPayload [0] != '0' ? false : true));
	}

	string Saisies::getSpayload(void)
	{
		assert(_eSaisie == Esaisie::sValue);

		return _sPayload;
	}

	int Saisies::getIpayload(void)
	{
		//assert(static_cast<int> (_eSaisie) == static_cast <int> (Esaisie::iValue));
		cout << "   <ici1> _eSaisie = [" << (int) _eSaisie << "]  </ici1>  ";

		return _iPayload;
	}
}
