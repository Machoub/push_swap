/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machouba <machouba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:47:05 by machouba          #+#    #+#             */
/*   Updated: 2024/04/05 15:37:07 by machouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = lstsize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->median = true;
		else
			stack->median = false;
		stack = stack->next;
		i++;
	}
}

static void	target_a(t_stack *a, t_stack *b)
{
	t_stack		*target_stack;
	int			best_match_index;
	t_stack		*cur_b;

	while (a)
	{
		best_match_index = INT_MIN;
		cur_b = b;
		while (cur_b)
		{
			if (cur_b->data < a->data && cur_b->data > best_match_index)
			{
				best_match_index = cur_b->data;
				target_stack = cur_b;
			}
			cur_b = cur_b->next;
		}
		if (best_match_index == INT_MIN)
			a->tag_node = ft_max(b);
		else
			a->tag_node = target_stack;
		a = a->next;
	}
}

static void	cost_analysis_a(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = lstsize(a);
	len_b = lstsize(b);
	while (a && a->next)
	{
		a->push_cost = a->index;
		if (!(a->median))
			a->push_cost = len_a - (a->index);
		if (a->tag_node)
		{
			if (a->tag_node->median)
				a->push_cost += a->tag_node->index;
			else
				a->push_cost += len_b - (a->tag_node->index);
		}
		a = a->next;
	}
}

void	cheapest(t_stack *stack)
{
	int		cheapest_v;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_v = INT_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_v)
		{
			cheapest_v = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->low_node = true;
}

void	init_nodes_a(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	target_a(a, b);
	cost_analysis_a(a, b);
	cheapest(a);
}
