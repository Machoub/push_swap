/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machouba <machouba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:34:11 by machouba          #+#    #+#             */
/*   Updated: 2024/04/05 15:40:08 by machouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_b(t_stack **a, t_stack **b, t_stack *cheap_node)
{
	while (*b != cheap_node->tag_node && *a != cheap_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

void	rev_rotate_a_b(t_stack **a, t_stack **b, t_stack *cheap_node)
{
	while (*b != cheap_node->tag_node && *a != cheap_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}

void	move_a_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node != NULL)
	{
		if (cheapest_node->median && cheapest_node->tag_node->median)
			rotate_a_b(a, b, cheapest_node);
		else if (!(cheapest_node->median) && !(cheapest_node->tag_node->median))
			rev_rotate_a_b(a, b, cheapest_node);
	}
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->tag_node, 'b');
	pb(a, b, false);
}

void	move_b_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->tag_node, 'a');
	pa(a, b, false);
}

void	min_on_top(t_stack **a)
{
	while ((*a)->data != ft_min(*a)->data)
	{
		if (ft_min(*a)->median)
			ra(a, false);
		else
			rra(a, false);
	}
}
