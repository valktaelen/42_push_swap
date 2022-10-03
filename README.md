# 42_push_swap
Trier des données sur une pile, avec un set d’instructions limité,
en moins de coups possibles.

# Le problème

On a 2 piles, a et b. 

- a contient des entiers sans doublons.
- b est vide

Le but est de trier la première pile à l'aide de la deuxième, pour cela nous pouvons
utiliser que certaines opérations.

- `sa` : swap a - intervertit les 2 premiers éléments au sommet de la pile a. Ne fait
rien s’il n’y en a qu’un ou aucun.
- `sb` : swap b - intervertit les 2 premiers éléments au sommet de la pile b. Ne fait
rien s’il n’y en a qu’un ou aucun.
- `ss` : sa et sb en même temps.
- `pa` : push a - prend le premier élément au sommet de b et le met sur a. Ne fait
rien si b est vide.
- `pb` : push b - prend le premier élément au sommet de a et le met sur b. Ne fait
rien si a est vide.
- `ra` : rotate a - décale d’une position vers le haut tous les élements de la pile a.
Le premier élément devient le dernier.
- `rb` : rotate b - décale d’une position vers le haut tous les élements de la pile b.
Le premier élément devient le dernier.
- `rr` : ra et rb en même temps.
- `rra` : reverse rotate a - décale d’une position vers le bas tous les élements de
la pile a. Le dernier élément devient le premier.
- `rrb` : reverse rotate b - décale d’une position vers le bas tous les élements de
la pile b. Le dernier élément devient le premier.
- `rrr` : rra et rrb en même temps.

Méthode utilisé: Quicksort

# Utilisation

Remplacer dir_push_swap par le dossier de push_swap

## Création de la librairie

```shell
make # compile lib (create libft.a)
```
ou depuis un autre dossier
```shell
make -C dir_push_swap
```

# Éxecution

```bash
./push_swap 1 2 8 4 6 7 -258 1465328 #...

# usage: ./push_swap numbers
```

### Utilisation du checker

`./push_swap numbers | checker_os numbers`

# Tests

https://bestofcpp.com/repo/SimonCROS-complexity-cpp-utilities

https://github.com/lmalki-h/push_swap_tester

https://github.com/AntoineA67/choupi-tester
