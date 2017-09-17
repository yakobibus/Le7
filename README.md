# Le7
Le7 est un jeu de dés (deux dés). Le premier à 7 points gagne 
### Principe :
    Deux joueurs ou d'avantage lancent chacun leur tour deux dés et totalisent les points. Chaque nouveau lancé de dés vient s'ajouter à la somme des points du joueur pour la partie en cours.
##### Scoring :
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
### Remarques :
    1. Si un seul joueur démarre la partie, le programme lui fournira un sparring partner
    2. Chaque lancé se fait avec deux dés
    3. Le joueur cumule les points de tous ses lancés successifs
    4. La meilleure main est le cumul des points qui atteint 7 ou s'en rapproche le plus
    5. Un joueur ne peut lancer les dés que si son nombre de lancés est <= à celui de ses adversaires
    6. Tous les joueurs ayant un cumul >= 7 points ne peuvent plus lancer les dés. Leur score est définitif pour la partie en cours
