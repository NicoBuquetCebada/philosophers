/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuquet- <nbuquet-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:00:53 by nbuquet-          #+#    #+#             */
/*   Updated: 2025/09/28 16:07:00 by nbuquet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
• Cada filósofo debe ser un hilo.

• Hay un tenedor entre cada filósofo. por lo tanto, si hay varios filósofos, cada filósofo
debe tener un tenedor a su izquierda y otro a su derecha. si solo hay un filósofo,
solo habrá un tenedor en la mesa.

• Para prevenir que los filósofos dupliquen los tenedores, deberás proteger los estados
de los tenedores con un mutex por cada uno de ellos.
*/

int	main(/* int ac, char av[] */)
{
	printf("Hola mundo!");
}