Jean-Marie Saindon
Achraf El Khamsi

Le code de chaque Achievement se trouve dans les répertoires Baseline, Ach-1,etc
Dans le dossier rapport se trouve le rapport au format pdf et le .tex associé.

//Instructions pour la compilation du projet :

- l'instruction make permet de compiler l'intégralité des achievements 
  de la Baseline à l'achievement 3

- si on ne souhaite compiler qu'un seul achievement, il suffit d'ajouter 
  le nom de celui-ci à la suite de la commande make.
  exemples : make Baseline ou make Achievement1


//Instructions pour l'execution :

- la compilation a pour effet de créer un executable par achievement.
  exemples : ./projectB  est la commande executant la Baseline
  	     ./projectA1 est la commande executant l'Achievement 1

- suite à l'execution d'un project, on a le choix entre faire afficher 
  la partie tour par tour (en entrant 1), ou faire afficher la partie 
  entière (en entrant un autre nombre).
  Attention : l'affichage de la grille de jeu pour les achievements 2 et 3
  	      n'est disponible qu'en mode tour par tour.

//Instructions pour la compilation et l'execution des tests :

- l'instruction make test permet de compiler et d'executer l'intégralité 
  des tests des achievements de la Baseline à l'achievement 3

- si on souhaite compiler et executer les tests d'un seul achievement, 
  il suffit d'ajouter le nom de celui-ci à la suite de la commande make test-.
  exemples : make test-Baseline ou make test-Achievement1

		     		 	   
