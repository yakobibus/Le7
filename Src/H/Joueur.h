// Joueur.h

# ifndef JOUEUR_H
# define JOUEUR_H  (1)

# include <iostream>


namespace le7_joueur 
{
	class Joueur
	{
	public :
		Joueur();
		Joueur(std::string pseu_score_scoredo);
		virtual ~Joueur() = default;
		Joueur(const Joueur& j);
		Joueur& operator = (const Joueur& j);

		void setJoueur(const std::string& pseudo, const int& score, const int& nbParties);
		void affiche(void);
	private :
		std::string _pseudo ;
		int _score ;
		int _nbParties ;
	};
}

# endif // JOUEUR_H
