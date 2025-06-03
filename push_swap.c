/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machouba <machouba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:21:05 by machouba          #+#    #+#             */
/*   Updated: 2024/04/08 14:03:15 by machouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = split(argv[1], ' ');
	init_stack_a(&a, argv + 1);
	if (argc == 2)
		ft_free_tab(argv);
	if (!stack_sorted(a))
	{
		if (lstsize(a) == 2)
			sa(&a, false);
		else if (lstsize(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	ft_free(&a);
	return (0);
}
