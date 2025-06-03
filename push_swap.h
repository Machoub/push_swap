/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machouba <machouba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:14:25 by machouba          #+#    #+#             */
/*   Updated: 2024/04/08 13:27:16 by machouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "libft/inc/libft.h"
# include "libft/inc/ft_printf.h"

typedef struct s_stack
{
	int				data;
	int				index;
	int				push_cost;
	bool			median;
	bool			low_node;
	struct s_stack	*tag_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// gestion erreurs
int		error_syntax(char *str);
void	ft_free(t_stack **lst);
void	free_errors(t_stack	**stack);
int		error_dup(t_stack *stack, int n);

// lst utils
t_stack	*lstlast(t_stack *lst);
int		lstsize(t_stack *lst);
bool	stack_sorted(t_stack *stack);
t_stack	*ft_min(t_stack *a);
t_stack	*ft_max(t_stack *a);

// opperations
void	sa(t_stack **a, bool print);
void	sb(t_stack **b, bool print);
void	ss(t_stack **a, t_stack **b, bool print);
void	sort_three(t_stack **stack);
void	pa(t_stack **a, t_stack **b, bool print);
void	pb(t_stack **a, t_stack **b, bool print);
void	ra(t_stack **a, bool print);
void	rb(t_stack **b, bool print);
void	rr(t_stack **a, t_stack **b, bool print);
void	rra(t_stack **a, bool print);
void	rrb(t_stack **b, bool print);
void	rrr(t_stack **a, t_stack **b, bool print);

// initialisation stacks
void	current_index(t_stack *stack);
void	cheapest(t_stack *stack);
void	init_nodes_a(t_stack *a, t_stack *b);
void	init_nodes_b(t_stack *a, t_stack *b);
void	init_stack_a(t_stack **a, char **argv);
t_stack	*get_cheapest(t_stack *stack);
void	prep_for_push(t_stack **stack, t_stack *top_node, char name_node);
void	sort_stacks(t_stack **a, t_stack **b);
void	min_on_top(t_stack **a);
void	move_b_a(t_stack **a, t_stack **b);
void	move_a_b(t_stack **a, t_stack **b);
char	**split(char *s, char c);
void	rev_rotate_a_b(t_stack **a, t_stack **b, t_stack *cheap_node);
void	rotate_a_b(t_stack **a, t_stack **b, t_stack *cheap_node);

#endif