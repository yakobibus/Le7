# Le7
</br>Un jeu de dés (deux dés). Le premier à 7 points gagne 
</br><b>Principe :</b>
</br>   Deux joueurs ou d'avantage lancent chacun leur tour deux dés et totalisent les points.
</br> <i>Scoring :</i>
<dl>   
<dt>  Si le cumul des lancés d'un joueur est == 7 <dd> => alors victoire
<dt>  Si le cumul des lancés d'un joueur est >  7 <dd> => alors défaite
<dt>  Si le cumul des lancés d'un joueur est  <  7 <dd> => alors
   <dl> si c'est la meilleure main (le meilleur cumul est celui qui se rapproche le plus de 7) 
       <dt> <dd> => alors victoire            
       <dt> sinon <dd>
      <dl>
        <dt> ==> si relance pour cumul <dd> ==> alors nouvelle évaluation
        <dt>   ==> sinon <dd> ==> alors défaite
      </dl>
   </dl>
</dl>
<b>Remarques :</b>
<ol>
<li> Si un seul joueur démarre la partie, le programme lui fournira un sparring partner
<li> Chaque lancé se fait avec deux dés
<li> Le joueur cumule les points de tous ses lancés successifs
<li> La meilleure main est le cumul des points qui atteint 7 ou s'en rapproche le plus
</ol>
