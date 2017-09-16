// Saisies.h

# ifndef SAISIES_H
# define SAISIES_H  (1)

# include <iostream>

namespace le7_saisies
{
	enum class Esaisie : int { nilValue = 0, iValue = 1, sValue = 2, errValue = 3} ;

	class Saisies 
	{
	public :
		Saisies();
		~Saisies() = default;
		Saisies(const Saisies& s);
		Saisies& operator = (const Saisies& s);

		Esaisie get(std::string invite = "$ > ");
		std::string getSpayload(void);
		int getIpayload(void);
		bool isNumber(void);
	protected :
	private :
		std::string _sPayload;
		int _iPayload;
		Esaisie _eSaisie;
	};

}
# endif // SAISIES_H
