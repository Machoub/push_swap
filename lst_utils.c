/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machouba <machouba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:11:22 by machouba          #+#    #+#             */
/*   Updated: 2024/01/19 14:02:08 by machouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	lstsize(t_stack *lst)
{
	size_t	i;

	if (!lst)
		return (0);
	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

bool	stack_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack	*ft_min(t_stack *a)
{
	int			min;
	t_stack		*min_stack;

	if (!a)
		return (NULL);
	min = INT_MAX;
	while (a)
	{
		if (a->data < min)
		{
			min = a->data;
			min_stack = a;
		}
		a = a->next;
	}
	return (min_stack);
}

t_stack	*ft_max(t_stack *a)
{
	int			max;
	t_stack		*max_stack;

	if (!a)
		return (NULL);
	max = INT_MIN;
	while (a)
	{
		if (a->data > max)
		{
			max = a->data;
			max_stack = a;
		}
		a = a->next;
	}
	return (max_stack);
}
