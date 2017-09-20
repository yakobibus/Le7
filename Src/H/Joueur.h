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

		void setJoueur(const std::string& pseudo, const int& score, const int& nbParties, const int& enieme = 0, const int& classement = 0);
		void affiche(const int& nbJoueurs = 0) const;
		//
		class Identite 
		{
		public :
			Identite();
			Identite(std::string pseudo);
			~Identite() = default;
			Identite(const Identite& i);
			Identite& operator = (const Identite& i);

			void setIdentite(const std::string& pseudo, const int& score, const int& nbParties, const int& enieme = 0, const int& classement = 0);
			const Identite& getIdentite (void) const ;
			//
		protected :
		private :
			std::string _pseudo ;
			int _score ;
			unsigned int _enieme;
			unsigned int _classement;
			int _nbParties ;
			//
			friend void Joueur::affiche(const int& nbJoueurs) const;
		};
	private :
		Identite _identite;
	};
}

# endif // JOUEUR_H
