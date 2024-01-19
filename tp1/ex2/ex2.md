# Compte Rendu - Exercice 3 / TP1

## Question 7
1. Parlez de vos différents blocages avec le restant de la classe et discutez des solutions.
>- Définition des fonctions d'une certaine classe. `Person::method()`.

2. Expliquez la différence entre phase de build (compilation) et phase de link (édition des liens).  
En quoi consiste la précompilation et à quel moment est-elle effectuée ?
> Phase de build => génère les fichiers-objet, fait la table des symboles.
> Phase de link => créer les liens, met les fichiers-objets ensemble.

3. Que signifient les messages suivants ?  
a. error: 'qqchose' was not declared in this scope  
> Que 'qqchose' 

b. error: 'qqchose' is not a member of 'std'  
> Que 'qqchose' n'est pas reconnu comme membre (méthode) de 'std'.

Ces erreurs se produisent-elles pendant la phase de build ou de link ?  
> Pendant la phase de build.

Que fait exactement l'instruction préprocesseur `#include` et pourquoi permet-elle généralement de résoudre ce type de problème ?
> Elle permet d'include le namespace

4. Compilez le programme de l'exercice en ne linkant que le fichier-objet associé à `main.cpp` (c'est-à-dire en oubliant `utils.cpp`).  
Quelle est l'erreur qui s'affiche ?    
En quoi est-elle différente des erreurs de la question précédente ?  
Expliquez ce qu'elle signifie exactement.

5. Décommentez maintenant les instructions commentées des fichiers [main.cpp](ex3/main.cpp) et [utils.hpp](ex3/utils.hpp).  
Compilez maintenant le programme complet (avec les modules main et utils).  
Quelle est l'erreur qui s'affiche ? S'agit-il d'une erreur de build ou de link ?  
Pourquoi se produit-elle ?  
Que faudrait-il faire pour la résoudre ?

6. Ajoutez le mot-clef `inline` devant la définition de la fonction `print_bye` dans [utils.hpp](ex3/utils.hpp). Que constatez-vous quand vous réessayez de compiler le programme ?  
Selon-vous, quel est l'effet du mot-clef `inline` sur le linker ?
