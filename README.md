Pour compiler :
```
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=XXX
```
Remplacer XXX par la valeur souhaitée (de 1 a 1000000000, sinon le buffer par défaut est de 10).

Run avec :
```
./a.out example.txt
```

Tu peux modifier example.txt a ta guise.

To do :

-> Cleaner le code (changer noms de variables newl_index et next_index pour meilleur nom.

-> Merge les fonctions create line et add buffer to line -> comportement très proche.

-> Faire les bonus du sujet (l'idée est de faire une array type: static t_gnl	gnl[fd] ).
