// Le7.h

# ifndef LE_7_H
# define LE_7_H  (1)

# include <iostream>
# include <cassert>
# include "Joueur.h"


namespace le7_main7Base
{
	class Main7Base
	{
	public:
		Main7Base() :_argc(0), _argv(nullptr) {}
		Main7Base(int argc, char** argv);
		virtual ~Main7Base();
		Main7Base(const Main7Base& m);
		Main7Base& operator = (const Main7Base& m);
	protected:
		virtual void Le7(void) = 0;
		inline int getArgc(void);
		inline std::string getArgv(int rang);
		inline std::string* getArgv(void);
	private:
		int _argc;
		std::string* _argv;
	};

	class Le7;
}

namespace le7_main
{
	class Main7 : public le7_main7Base::Main7Base
	{
	public:
		Main7() : Main7Base(0, nullptr), _nbJoueurs(0), _lesJoueurs(nullptr) {}
		Main7(int argc, char** argv);
		~Main7();
		Main7(const Main7& m);
		Main7& operator = (const Main7& m);
		virtual void Le7(void);

		void affiche(void);
	private:
		friend class Le7;
		le7_joueur::Joueur* _lesJoueurs;
		int _nbJoueurs;
	};
}

namespace le7_le7
{

	class Le7
	{
	public :
		Le7(le7_joueur::Joueur*& listeJoueurs, int& nbJoueurs);
		~Le7() = default;
		Le7(const Le7& l) = default ;
		Le7& operator = (const Le7& l) = default ;
		//
		void Regle_1(void); // Si un seul joueur d�marre la partie, le programme lui fournira un sparring partner 
	protected :
	private :
		le7_joueur::Joueur*& _lesJoueurs;
		int& _nbJoueurs;
	};
}

# endif // LE_7_H
/*
Le7

Le7 est un jeu de d�s (deux d�s). Le premier � 7 points gagne

Principe :
	Deux joueurs ou d'avantage lancent chacun leur tour deux d�s et totalisent les points. Chaque nouveau lanc� de d�s vient s'ajouter � la somme des points du joueur pour la partie en cours.
Scoring :
	Si le cumul des lanc�s d'un joueur est �gal � 7
		alors victoire
	Sinon
		Si le cumul des lanc�s d'un joueur est > 7
			alors d�faite
		Sinon
			Si le cumul des lanc�s d'un joueur est  <  7
				alors
					Si c'est la meilleure main (le meilleur cumul est celui qui se rapproche le plus de 7)
						alors victoire
					Sinon
						Si le joueur relance pour am�liorer son cumul
							alors nouvelle �valuation du scoring de tous les joueurs
						Sinon
							d�faite
Remarques :
	}1. Si un seul joueur d�marre la partie, le programme lui fournira un sparring partner - {Regle_1)
	2. Chaque lanc� se fait avec deux d�s
	3. Le joueur cumule les points de tous ses lanc�s successifs
	4. La meilleure main est le cumul des points qui atteint 7 ou s'en rapproche le plus
	5. Un joueur ne peut lancer les d�s que si son nombre de lanc�s est <= � celui de ses adversaires
	6. Tous les joueurs ayant un cumul >= 7 points ne peuvent plus lancer les d�s. Leur score est d�finitif pour la partie en cours
**/

/*
** Algo :
**    
**/
