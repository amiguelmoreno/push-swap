/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils-2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmoren <antmoren@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:06:20 by antmoren          #+#    #+#             */
/*   Updated: 2023/01/27 14:08:04 by antmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**formatArray(char *arr)
{
	char	**result;

	//int i = 0;
	result = ft_split(arr, ' ');
	return (result);
}

int	arrLength(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}