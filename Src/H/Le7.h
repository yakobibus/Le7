// Le7.h

# ifndef LE_7_H
# define LE_7_H  (1)

# include <iostream>
# include <cassert>
# include "Joueur.h"
# include "LeDe.h"


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
	private :
		class Partie;
	public :
		Le7(le7_joueur::Joueur*& listeJoueurs, int& nbJoueurs);
		~Le7();
		Le7(const Le7& l) ;
		Le7& operator = (const Le7& l) ;
		//
		void Regle_1(void); // Si un seul joueur démarre la partie, le programme lui fournira un sparring partner 
		void Tirage(void) { std::cout << "[" << _de1.Lancer() << "]" << std::endl; }

		// void dummyPartie(Le7::Partie& p) { std::cout << p._nbLances; }
	private :
		class Partie
		{
		public :
			Partie();

			~Partie() = default;

			Partie(const Partie& p);

			Partie& operator = (const Partie& p); 
		protected :
		private :
			unsigned int _nbLances;
			int _scoreDesLances[7];  // Les scores des lancés successifs, initialises à -1
			bool _estHorsJeu ;

			friend class Le7;
		};
	private :
		le7_joueur::Joueur*& _lesJoueurs;
		int& _nbJoueurs;

		Partie* _partiesDesJoueurs;

		le7_le_de::LeDe _de1;
		//le7_le_de::LeDe _de2;
	};
}

# endif // LE_7_H
/*
Le7

Le7 est un jeu de dés (deux dés). Le premier à 7 points gagne

Principe :
	Deux joueurs ou d'avantage lancent chacun leur tour deux dés et totalisent les points. Chaque nouveau lancé de dés vient s'ajouter à la somme des points du joueur pour la partie en cours.
Scoring :
	Si le cumul des lancés d'un joueur est égal à 7
		alors victoire
	Sinon
		Si le cumul des lancés d'un joueur est > 7
			alors défaite
		Sinon
			Si le cumul des lancés d'un joueur est  <  7
				alors
					Si c'est la meilleure main (le meilleur cumul est celui qui se rapproche le plus de 7)
						alors victoire
					Sinon
						Si le joueur relance pour améliorer son cumul
							alors nouvelle évaluation du scoring de tous les joueurs
						Sinon
							défaite
Remarques :
	}1. Si un seul joueur démarre la partie, le programme lui fournira un sparring partner - {Regle_1)
	2. Chaque lancé se fait avec deux dés
	3. Le joueur cumule les points de tous ses lancés successifs
	4. La meilleure main est le cumul des points qui atteint 7 ou s'en rapproche le plus
	5. Un joueur ne peut lancer les dés que si son nombre de lancés est <= à celui de ses adversaires
	6. Tous les joueurs ayant un cumul >= 7 points ne peuvent plus lancer les dés. Leur score est définitif pour la partie en cours
**/

/*
** Algo :
**    
**/
