# include <iostream>
# include <string>
# include "Joueur.h"

using std::string;

namespace le7_joueur 
{
	le7_joueur::Joueur::Identite::Identite() 
		: _pseudo("")
		, _score(0)
		, _nbParties(0) 
		, _enieme (0)
		, _classement (0)
	{
	}

	le7_joueur::Joueur::Identite::Identite(string pseudo)
		: _pseudo(pseudo)
		, _score(0)
		, _nbParties(0)
		, _enieme(0)
		, _classement(0)
	{
	}

	le7_joueur::Joueur::Identite::Identite(const Identite& i)
	{
		if (this != &i)
		{
			_pseudo = i._pseudo;
			_score = i._score;
			_nbParties = i._nbParties;
			_enieme = i._enieme;
			_classement = i._classement;
		}
	}

	le7_joueur::Joueur::Identite& le7_joueur::Joueur::Identite::operator = (const Identite& i)
	{
		if (this != &i)
		{
			_pseudo = i._pseudo;
			_score = i._score;
			_nbParties = i._nbParties;
			_enieme = i._enieme;
			_classement = i._classement;
		}

		return *this;
	}

	void le7_joueur::Joueur::Identite::setIdentite(const std::string& pseudo, const int& score, const int& nbParties, const int& enieme, const int& classement)
	{
		_pseudo = pseudo;
		_score = score;
		_nbParties = nbParties;
		_enieme = enieme;
		_classement = classement;
	}
	
	const le7_joueur::Joueur::Identite& le7_joueur::Joueur::Identite::getIdentite(void) const
	{
		return *this;
	}


	le7_joueur::Joueur::Joueur() 
		: _identite ()
	{
	}


	le7_joueur::Joueur::Joueur(string pseudo)
		: _identite (pseudo)
	{
	}

	le7_joueur::Joueur::Joueur(const Joueur & j)
	{
		if (this != &j)
		{
			_identite = j._identite;
		}
	}

	Joueur& le7_joueur::Joueur::operator = (const Joueur& j)
	{
		if (this != &j)
		{
			_identite = j._identite;
		}

		return *this;
	}


	void Joueur::setJoueur(const std::string& pseudo, const int& score, const int& nbParties, const int& enieme, const int& classement)
	{
		_identite.setIdentite(pseudo, score, nbParties, enieme, classement);
	}

	void Joueur::affiche(const int& nbJoueurs) const {
		std::cout << "Joueur : " << _identite._enieme << (nbJoueurs > 0 ? "/" + std::to_string(nbJoueurs) : ".") + " " << std::endl;
		std::cout << "Pseudo : " << _identite._pseudo << std::endl;
		std::cout << " Score : " << _identite._score << std::endl;
		std::cout << "    En : " << _identite._nbParties << " partie" << (_identite._nbParties > 1 ? "s" : "") << std::endl;
		std::cout << "ClassE : " << (_identite._classement == 0 ? "-" : (_identite._classement == 1 ? "Premier" : std::to_string(_identite._classement) + "e")) << std::endl;
		std::cout << std::endl;
	}
}
