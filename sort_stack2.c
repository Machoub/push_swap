/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machouba <machouba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:28:27 by machouba          #+#    #+#             */
/*   Updated: 2024/01/23 15:29:26 by machouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stacks(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = lstsize(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b, false);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b, false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
