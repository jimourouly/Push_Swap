#!/bin/bash

# Fonction pour vérifier si un test est en erreur
is_error() {
    result=$(./push_swap $1 | ./checker_OS $1)
    if [[ $result == "KO" ]]; then
        echo "Error: $1"
    fi
}

# Générer une liste de toutes les permutations possibles de 1 à 6
permutations=("1 2 3 4")

for i in {1..999}; do
    permutations+=($(echo ${permutations[0]} | tr ' ' '\n' | shuf | tr '\n' ' '))
done

# Afficher uniquement les tests en erreur
for permutation in "${permutations[@]}"; do
    is_error "$permutation"
done
