# Tetris-like
Projet d'un jeu "Tetris-like" Pour l'université.

## Guide d'installation
### Prérequis
MLV Library (voir : https://www-igm.univ-mlv.fr/~boussica/mlv/api/French/html/index.html)
### Compilation
Afin de compiler le programme, vous devez utiliser la commande

```gcc -W -Wall -std=c89 -pedantic -O2 \`pkg-config --cflags MLV\` \`pkg-config --libs-only-other --libs-only-L MLV\` $1 \`pkg-config --libs-only-l MLV\` -o $2```

Cela créera un fichier Tetris-like executable.