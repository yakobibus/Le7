# Le7
    Un jeu de dés opposant au moins deux adversaires
    Chaque joueur lance un dé à son tour, les points se cumulent après chaque lancé

## Principe :
    Deux joueurs ou d'avantage s'affrontent dans un jeu de dés.  Le but est de totaliser 7 points avec le dé

## Scorring :
    s1. Les joueurs lancent chacun leur tour un premier dé
    s2. Quand tous les joueurs ont fait un lancer, les scores sont évalués et le classement déterminé
    s3. Si un joueur totalise 7 points 
        s31. il remporte la partie qui prend fin aussitôt
    s4. Sinon
        s41. Si un joueur totalise plus de 7 points
             s411. il est aussitôt hors-jeu, son score est ramené à zéro, il ne marque pas de point
        s42. Sinon
             s421. Un nouveau tour de lancés est enclenché pour lequel les joueurs encore en course. Ils ont le choix de relancer un dé ou non
                 s4211. Si un joueur renonce à relancer le dé, 
                        s42111. il cumule un lancer à zéro points, il garde donc son total inchangé pour ce tour
                 s4212. Sinon
                        s42121. il lance un nouveau dé dont les points s'ajoutent à son total. Ce cumul est évalué pour déterminer la victoire (7 points) ou l'élimination (> 7 points).
    s5. Afficher à l'issue de chaque tour, les scores et les victoires/défaites/hors-jeux éventuels et le classement

## Règles :
    r1. Si un seul joueur démarre la partie, le programme lui fournira un sparring partner
    r2. Si un joueur totalise plus de 7 points, il est hors-jeu d'office, son score est ramené à zéro
    r3. Le premier joueur totalisant 7 points gagne la partie qui prend fin aussitôt
    r4. Seul le gagnant marque des points (2 points)
    r5. Si aucun joueur n'a marqué 7 points, les scores des joueurs sont évalués de manière décroissante :
        Tous ceux ayant le score le plus élevé marqueront un point chacun.
    r6. Les joueurs n'ayant pas remporté la partie ne marquent pas de points
