/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machouba <machouba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:12:32 by machouba          #+#    #+#             */
/*   Updated: 2024/04/08 13:32:54 by machouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_syntax(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

int	error_dup(t_stack *stack, int n)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->data == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	ft_free(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		(*lst)->data = 0;
		free(*lst);
		*lst = tmp;
	}
}

void	free_errors(t_stack	**stack)
{
	ft_free(stack);
	ft_printf("Error\n");
	return ;
}
