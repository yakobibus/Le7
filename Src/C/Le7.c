// Le7.c

# include <iostream>
# include "Le7.h"
# include "Joueur.h"

using std::string;

namespace le7_main
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
				std::cout << "(" << i << ") <" << _argv[i].c_str() << ">" << std::endl;
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
			for (int i = 0; i < _nbJoueurs; ++i)
			{
				_lesJoueurs[i].setJoueur(getArgv(1 + i), initScore, initNbParties);
				_lesJoueurs[i].affiche();
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
			for (int i = 1; i < getArgc(); ++i)
			{
				_lesJoueurs[i].setJoueur(getArgv(i), initScore, initNbParties);
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
				for (int i = 1; i < getArgc(); ++i)
				{
					_lesJoueurs[i].setJoueur(getArgv(i), initScore, initNbParties);
				}
			}
		}
		return *this;
	}

	inline void Main7::Le7(void)
	{
		le7_joueur::Joueur j1("Primo");
	}
}
	

int main(int argc, char** argv) {
	le7_main::Main7 m7 (argc, argv);
	m7.Le7();

	return 0;
}
