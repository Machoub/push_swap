/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machouba <machouba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:20:08 by machouba          #+#    #+#             */
/*   Updated: 2024/04/08 17:06:34 by machouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	push_swap_atoi(const char *str)
{
	long	r;
	long	s;

	r = 0;
	s = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			s = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		r = r * 10 + (*str - '0');
		str++;
	}
	return (r * s);
}

static void	add_node(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->data = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = lstlast(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack_a(t_stack **a, char **argv)
{
	long	n;
	int		i;

	i = -1;
	while (argv[++i])
	{
		if (error_syntax(argv[i]))
		{
			free_errors(a);
			break ;
		}
		n = push_swap_atoi(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			free_errors(a);
			break ;
		}
		if (error_dup(*a, n))
		{
			free_errors(a);
			break ;
		}
		add_node(a, n);
	}
	return ;
}

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->low_node)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack **stack, t_stack *top_node, char name_node)
{
	while (*stack != top_node)
	{
		if (name_node == 'a')
		{
			if (top_node->median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (name_node == 'b')
		{
			if (top_node->median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}
