/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machouba <machouba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:29:22 by machouba          #+#    #+#             */
/*   Updated: 2024/04/05 15:37:32 by machouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	target_b(t_stack *a, t_stack *b)
{
	t_stack		*target_stack;
	int			best_match_index;
	t_stack		*cur_a;

	while (b)
	{
		best_match_index = INT_MAX;
		cur_a = a;
		while (cur_a)
		{
			if (cur_a->data > b->data && cur_a->data < best_match_index)
			{
				best_match_index = cur_a->data;
				target_stack = cur_a;
			}
			cur_a = cur_a->next;
		}
		if (best_match_index == INT_MAX)
			b->tag_node = ft_min(a);
		else
			b->tag_node = target_stack;
		b = b->next;
	}
}

void	init_nodes_b(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	target_b(a, b);
}
