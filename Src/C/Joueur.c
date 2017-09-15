# include <iostream>
# include "Joueur.h"

using std::string;

namespace le7_joueur 
{
	le7_joueur::Joueur::Joueur() 
		: _pseudo("")
		, _score(0)
		, _nbParties(0) 
	{
	}


	le7_joueur::Joueur::Joueur(string pseudo)
		: _pseudo(pseudo)
		, _score (0)
		, _nbParties (0) 
	{
	}

	le7_joueur::Joueur::Joueur(const Joueur & j)
	{
		if (this != &j)
		{
			_pseudo = j._pseudo;
			_score = j._score;
			_nbParties = j._nbParties;
		}
	}

	Joueur& le7_joueur::Joueur::operator = (const Joueur& j)
	{
		if (this != &j)
		{
			_pseudo = j._pseudo;
			_score = j._score;
			_nbParties = j._nbParties;
		}

		return *this;
	}


	void Joueur::setJoueur(const std::string& pseudo, const int& score, const int& nbParties)
	{
		_pseudo = pseudo;
		_score = score;
		_nbParties = nbParties;
	}

	void Joueur::affiche(void) {
		std::cout << "Pseudo : " << _pseudo.c_str() << std::endl;
		std::cout << " Score : " << _score << std::endl;
		std::cout << "    En : " << _nbParties << " partie" << (_nbParties > 1 ? "s" : "") << std::endl;
		std::cout << std::endl;
	}
}
