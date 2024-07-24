/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:00:49 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/17 13:01:38 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*aux;
	unsigned char	*tmp;

	aux = (unsigned char *)s1;
	tmp = (unsigned char *)s2;
	i = 0;
	while ((aux[i] != '\0' && tmp[i] != '\0') && aux[i] == tmp[i])
		i++;
	return (aux[i] - tmp[i]);
}
