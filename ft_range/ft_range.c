/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebbali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:30:19 by mrebbali          #+#    #+#             */
/*   Updated: 2024/09/19 17:46:17 by mrebbali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     *ft_range(int start, int end)
{
	int i;
	int *result;

	if (start >= end)
		return (NULL);
	result = (int *)malloc(sizeof(int) * (end - start)+1);
	i = 0;
	while ((start + i) <= (end))
	{
		result[i] = start + i;
		i++;
	}
	return (result);

}

#include <stdio.h>
int main()
{
	int i;

	i=0;
	while(i <= 5)
		printf("%i\n",ft_range(5,10)[i++]);
}
