GOSSET Séverin

Rapport de projet - FlightSim

# Introdutcion

Ce projet consiste à implementer un simulateur de vol très simple, en utilisant `Garamon` pour les rotations et `OpenGL` pour l'affichage. L'utilisation de `Garamon` va se faire via les quaternions, qui permettent d'éviter plusieurs problèmes que l'on obtient avec les rotations classiques.

# Le simulateur

Le simulateur de vol consistera en une caméra, qui representera l'avion, et qui va se déplacer en fonction du clavier de l'utilisateur. L'envirronnement, très simple, sera une texture de ciel tout autour de la camera. Pour se deplacer, on utilisera les commandes suivantes :

- `Z`/`S` pour orienter la caméra vers le haut / bas,
- `Q`/`S` pour orienter la caméra vers la gauche / droite, et
- `A`/`E` pour faire "rouler" la caméra sur la gauche / droite.

Ces commandes permettent d'orienter l'avion dans toutes les directions, c'est ce qui va nous interresser au cours du projet. 

## Rotations

Le principe du projet va être d'appliquer une rotation sur le bon axe de la caméra quand la touche est pressée. Ces rotations sont définies par l'image suivante :

![Les 3 axes de rotations](images/axes.png){height=200px}

Ces 3 axes permettent d'obtenir ce qu'on appelle les 6 degrés de liberté, on peut tourner dans 6 directions differentes. 

## Caméras

Afin de pouvoir experimenter avec avec le simulateur, j'ai implémenté 3 caméras differentes, qui implémentent toutes trois une interface `Camera`. Cette interface contient, entre autres, les méthodes dont on a besoin pour controller l'avion (`moveFront`, `rotate` sur chaque axe) et surtout, pour obtenir la `viewMatrix`.
La `viewMatrix` est la matrice qui represente l'endroit duquel est vu le monde, et va permettre de "déplacer" le monde de façon à voir le monde depuis le point de vue de la caméra. Les trois types de caméras implémentées sont la `MatrixCamera`, la `EulerCamera` et la `QuaternionCamera`.

### Matrix Camera

La `MatrixCamera` est une caméra qui utilise des matrices de rotations, comme vues en cours, pour transformer la `viewMatrix`. Le principe repose sur le fait qu'une rotation sur un des trois angle influe uniquement sur une des lignes de la `viewMatrix`. On va de garder 3 angles, un pour chaque axe, qui vont être mis à jour à chaque appel à la fonction correspondante. Lors de l'appel à `getViewMatrix`, on va creer 3 matrices identités, une pour chaque axe, et on va appliquer une rotation à chaque matrice par un vecteur différent, d'intensité égale à l'angle sauvegardé pour cet axe. La rotation `Roll` est appliquée avec le vecteur $(0, 0, 1)$, la rotation `Pitch` sur $(1, 0, 0)$ et la rotation `Yaw` sur $(0, 1, 0)$. Ensuite, on définit la matrice de rotation $R$ tel que :

\begin{equation}
R = M_{yaw} * M_{pitch} * M_{roll}
\end{equation}

Ensuite, la `viewMatrix` se définit à partir de $R$ et $T$ la matrice de translation selon l'opposé du vecteur de position de la caméra : 

\begin{equation}
V = R * T
\end{equation}

### Euler Camera

La `EulerCamera` repose sur un principe different, les angles d'Euler, qui sont souvent utilisés pour les caméras à la première personne : on garde 3 vecteur orthogonaux $v_{up}$, $v_{right}$ et $v_{front}$, qui representent respectivement comme leur nom l'indique le haut de la caméra, sa droite et son avant. Ces trois vecteurs vont être modifiés lors des rotations, et l'on va ensuite calculer la `viewMatrix` à partir de ces trois vecteurs.

Les opérations effectuées sur les vecteurs pour un angle $\theta$ sont, par exemple pour un `Roll`:

\begin{equation}
\begin{aligned}
v_{up} &= v_{up} * \cos{\theta} + v_{right} * \sin{\theta}\\
v_{right} &= v_{up} * v_{front}
\end{aligned}
\end{equation}

Le principe est que le `Roll` n'est pas censé modifier le vecteur $v_{front}$, puisqu'on tourne autour. Le vecteur $v_{up}$ va subir une rotation autour de cet axe, et le vecteur $v_{right}$ sera le produit en croix des deux autres, puisqu'ils sont orthogonaux entre eux. Pour les deux autres rotations, le raisonnement est annalogue, on change juste les vecteurs.

Lors de l'appel à `getViewMatrix`, on va utiliser ces trois vecteurs ainsi que la position pour calculer la matrice, grâce à la méthode `lookAt` fournie par `OpenGL`.