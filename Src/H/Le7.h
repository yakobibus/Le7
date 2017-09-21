// Le7.h

# ifndef LE_7_H
# define LE_7_H  (1)

# include <iostream>
# include <cassert>
# include "Joueur.h"


namespace le7_main
{
	class Main7Base
	{
	public :
		Main7Base() :_argc (0), _argv (nullptr) {}
		Main7Base(int argc, char** argv);
		virtual ~Main7Base();
		Main7Base(const Main7Base& m);
		Main7Base& operator = (const Main7Base& m);
	protected :
		virtual void Le7 ( void ) = 0;
		inline int getArgc(void);
		inline std::string getArgv(int rang);
		inline std::string* getArgv(void);
	private :
		int _argc;
		std::string* _argv;
	};

	class Main7 : public Main7Base
	{
	public :
		Main7() : Main7Base(0, nullptr) , _nbJoueurs (0), _lesJoueurs (nullptr) {}
		Main7(int argc, char** argv) ;
		~Main7();
		Main7(const Main7& m);
		Main7& operator = (const Main7& m);
		virtual void Le7(void);
	private :
		le7_joueur::Joueur* _lesJoueurs;
		int _nbJoueurs;
	};
}

# endif // LE_7_H
/*
** Principe
**   Lancer deux dés et totaliser les points (Afficher le score)
** Scoring :
**   La somme des lancés d'un joueur est == 7 => victoire
**   La somme des lancés d'un joueur est > 7  => défaite
**   La somme des lancés d'un joueur est < 7 => si c'est la meilleure main (meilleur cumul) => victoire
**                                           => si non => si relance pour cumul nouvelle évaluation
**                                                     => sinon défaite
**/

/*
** Algo :
**    
**/
