// Le7.c

# include <iostream>
# include "Le7.h"
# include "Joueur.h"

using std::string;

namespace le7_le7
{
	le7_le7::Le7::Le7(le7_joueur::Joueur*& listeJoueurs, int& nbJoueurs)
		: _lesJoueurs (listeJoueurs)
		, _nbJoueurs (nbJoueurs)
	{
		_partiesDesJoueurs = new le7_le7::Le7::Partie[_nbJoueurs];
	}

	le7_le7::Le7::~Le7()
	{
		delete[] _partiesDesJoueurs;
	}

	le7_le7::Le7::Le7(const Le7& l) : _nbJoueurs(this->_nbJoueurs), _lesJoueurs (this->_lesJoueurs)
	{
		if(this != &l)
		{ 
			delete[] _partiesDesJoueurs;

			_nbJoueurs = l._nbJoueurs;
			_partiesDesJoueurs = new le7_le7::Le7::Partie [_nbJoueurs];
			for (int i = 0; i < _nbJoueurs; ++i)
			{
				_partiesDesJoueurs[i] = l._partiesDesJoueurs[i];
			}
		}
	}

	le7_le7::Le7& le7_le7::Le7::operator = (const Le7& l)
	{
		if(this != &l)
		{ 
			delete[] _partiesDesJoueurs;

			_nbJoueurs = l._nbJoueurs;
			_partiesDesJoueurs = new le7_le7::Le7::Partie [_nbJoueurs];
			for (int i = 0; i < _nbJoueurs; ++i)
			{
				_partiesDesJoueurs[i] = l._partiesDesJoueurs[i];
			}
		}
		
		return *this;
	}


	void le7_le7::Le7::Regle_1 (void)
	{
		if (_nbJoueurs == 1)
		{
			std::cout << ".... Regle_1 ...\n";
			le7_joueur::Joueur jTemporaire(_lesJoueurs [0]);
			
			delete [] _lesJoueurs;
			_lesJoueurs = nullptr;

			_nbJoueurs = 2;
			_lesJoueurs = new le7_joueur::Joueur[_nbJoueurs];

			_lesJoueurs[0] = jTemporaire;
			const std::string pseudoSparring = "Sparring Partner";
			const int initScoreSparring = 0;
			const int initNbPartiesSparring = 0;
			const int initEniemeSparring = 2;
			const int initClassementSparring = 0;
			_lesJoueurs[1].setJoueur(pseudoSparring, initScoreSparring, initNbPartiesSparring, initEniemeSparring, initClassementSparring);
		}
	}

	Le7::Partie::Partie()
		: _nbLances(0)
		, _estHorsJeu(false)
	{
		for (int i = 0; i < 7; ++i)
		{
			_scoreDesLances[i] = -1;
		}
	}

	Le7::Partie::Partie(const Partie & p)
	{
		if (this != &p)
		{
			_nbLances = p._nbLances;
			_estHorsJeu = p._estHorsJeu;
			for (int i = 0; i < 7; ++i)
			{
				_scoreDesLances[i] = p._scoreDesLances[i];
			}
		}
	}

	Le7::Partie& Le7::Partie::operator = (const Le7::Partie& p)
	{
		if (this != &p)
		{
			_nbLances = p._nbLances;
			_estHorsJeu = p._estHorsJeu;
			for (int i = 0; i < 7; ++i)
			{
				_scoreDesLances[i] = p._scoreDesLances[i];
			}
		}

		return *this;
	}
}

namespace le7_main7Base
{
	Main7Base::Main7Base(int argc, char** argv)
		: _argc(argc)
		, _argv(nullptr)
	{
		if (_argc > 0)
		{
			_argv = new string[_argc];
			for (int i = 0; i < _argc; ++i)
			{
				_argv[i] = argv[i];
			}
		}
	}


	Main7Base::~Main7Base() {
		if (_argc > 0)
		{
			delete[] _argv;
			_argv = nullptr;
		}
	}


	Main7Base::Main7Base(const Main7Base& m) {
		if (this != &m)
		{
			if (_argc > 0)
			{
				delete[] _argv;
				_argv = nullptr;
			}

			_argc = m._argc;

			if (_argc > 0)
			{
				_argv = new string[_argc];
				for (int i = 0; i < _argc; ++i)
				{
					_argv[i] = m._argv[i];
					std::cout << "(" << i << ") <" << _argv[i].c_str() << ">" << std::endl;
				}
			}
		}
	}


	Main7Base& Main7Base::operator = (const Main7Base& m) {
		if (this != &m)
		{
			if (_argc > 0)
			{
				delete[] _argv;
				_argv = nullptr;
			}

			_argc = m._argc;

			if (_argc > 0)
			{
				_argv = new string[_argc];
				for (int i = 0; i < _argc; ++i)
				{
					_argv[i] = m._argv[i];
					std::cout << "(" << i << ") <" << _argv[i].c_str() << ">" << std::endl;
				}
			}
		}

		return *this;
	}


	inline int Main7Base::getArgc(void) { return _argc; }

	inline std::string * Main7Base::getArgv(void) { return _argv; }

	inline std::string Main7Base::getArgv(int rang) { assert(rang >= 0 && rang < _argc); return _argv[rang]; }
}

namespace le7_main
{
	Main7::Main7(int argc, char** argv)
		: Main7Base(argc, argv)
		, _nbJoueurs(0)
		, _lesJoueurs(nullptr)
	{
		_nbJoueurs = -1 + getArgc();

		if (_nbJoueurs > 0) {
			_lesJoueurs = new le7_joueur::Joueur[_nbJoueurs];

			const int initScore = 0;
			const int initNbParties = 0;
			const int initClassement = 0;
			for (int i = 0; i < _nbJoueurs; ++i)
			{
				_lesJoueurs[i].setJoueur(getArgv(1 + i), initScore, initNbParties, 1 + i, initClassement);
			}
		}
	}

	Main7::~Main7()
	{
		if (_nbJoueurs > 0) {
			delete[] _lesJoueurs;
			_lesJoueurs = nullptr;
		}
	}

	Main7::Main7(const Main7 & m)
	{
		if (_nbJoueurs > 0) {
			delete[] _lesJoueurs;
			_lesJoueurs = nullptr;
		}

		_nbJoueurs = m._nbJoueurs;

		if (_nbJoueurs > 0) {
			_lesJoueurs = new le7_joueur::Joueur[_nbJoueurs];

			const int initScore = 0;
			const int initNbParties = 0;
			const int initClassement = 0;
			for (int i = 1; i < getArgc(); ++i)
			{
				_lesJoueurs[i].setJoueur(getArgv(i), initScore, initNbParties, i, initClassement);
			}
		}
	}

	Main7& Main7::operator = (const Main7& m)
	{
		if (this != &m) {
			if (_nbJoueurs > 0) {
				delete[] _lesJoueurs;
				_lesJoueurs = nullptr;
			}

			_nbJoueurs = m._nbJoueurs;

			if (_nbJoueurs > 0) {
				_lesJoueurs = new le7_joueur::Joueur[_nbJoueurs];

				const int initScore = 0;
				const int initNbParties = 0;
				const int initClassement = 0;
				for (int i = 1; i < getArgc(); ++i)
				{
					_lesJoueurs[i].setJoueur(getArgv(i), initScore, initNbParties, i, initClassement);
				}
			}
		}
		return *this;
	}

	inline void Main7::affiche(void)
	{
		std::cout << std::endl;
		for (int i = 1; i <= _nbJoueurs; ++i)
		{
			_lesJoueurs[-1 + i].affiche(_nbJoueurs);
		}
	}

	inline void Main7::Le7(void)
	{
		le7_le7::Le7 le7 (_lesJoueurs, _nbJoueurs);
		le7.Regle_1();

		for (int ii = 0; ii < _nbJoueurs; ++ii)
		{
			std::cout << '.' << std::endl ; // ici ...
		}
		/*
		std::cout << "Joueur 1, " << std::endl;
		le7.Tirage();
		std::cout << "Joueur 2, " << std::endl;
		le7.Tirage();
		*/
	}
}
	

int main(int argc, char** argv) {
	le7_main::Main7 m7 (argc, argv);
	/* 20170927 1131
	m7.Le7();
	m7.affiche();
	*/

	return 0;
}
