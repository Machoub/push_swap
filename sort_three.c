/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machouba <machouba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:28:20 by machouba          #+#    #+#             */
/*   Updated: 2024/01/19 10:19:38 by machouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*big_stack;

	big_stack = ft_max(*stack);
	if (big_stack == *stack)
		ra(stack, false);
	else if ((*stack)->next == big_stack)
		rra(stack, false);
	if ((*stack)->data > (*stack)->next->data)
		sa(stack, false);
}
