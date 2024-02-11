/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:55:45 by jroulet           #+#    #+#             */
/*   Updated: 2024/02/11 13:56:35 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "push_swap.h"

int main() {
    const char *test_cases[] = {
        "123",          // Nombre positif
        "-456",         // Nombre négatif
        "   789",       // Espaces blancs au début
        "987   ",       // Espaces blancs à la fin
        "+321",         // Signe explicite positif
        "   -654",      // Espaces blancs au début, nombre négatif
        "42abc",        // Caractères après le nombre (ne doit pas être converti)
        "   ",          // Chaîne vide (0 doit être retourné ou une gestion spécifique)
        "   abc",       // Caractères non numériques au début (ne doit pas être converti)
        "9223372036854775807",   // LONG_MAX (limite supérieure)
        "-9223372036854775808",  // LONG_MIN (limite inférieure)
        "9223372036854775808",   // Nombre supérieur à LONG_MAX (comportement indéfini)
        "-9223372036854775809",  // Nombre inférieur à LONG_MIN (comportement indéfini)
    };

    for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); ++i) {
        long result = ft_atoli(test_cases[i]);
        printf("Test case: \"%s\" => Resultat: %ld\n", test_cases[i], result);
    }

    return 0;
}
