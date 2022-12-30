/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmoren <antmoren@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:36:00 by antmoren          #+#    #+#             */
/*   Updated: 2022/12/29 21:09:18 by antmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../42-library/includes/ft_printf.h"
# include "../42-library/includes/get_next_line_bonus.h"
# include "../42-library/includes/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

/* Init */

t_stack				*fill_stack(int ac, char **av);
void				add_index(t_stack *stack_a, int stack_size);

/* Positions */

void				add_positions(t_stack **stack);
int					get_lowest_index_position(t_stack **stack);
int					get_target(t_stack **a, int b_idx, int target_idx,
						int target_pos);
void				add_target_position(t_stack **a, t_stack **b);

/* Sort */

int					is_sorted(t_stack *stack);
void				sort_small(t_stack **stack);
void				sort(t_stack **stack_a, t_stack **stack_b);

/* Movements */

void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);

/* Stack Utils */

t_stack				*get_stack_before_bottom(t_stack *stack);
t_stack				*get_stack_bottom(t_stack *stack);
t_stack				*stack_new(int value);
void				stack_add_bottom(t_stack **stack, t_stack *new);
int					get_stack_size(t_stack *stack);

/* Utils */

void				free_stack(t_stack **stack);
void				exit_error(t_stack **stack_a, t_stack **stack_b);
int					nb_abs(int nb);

/* Check Input Errors */

int					is_sign(char c);
int					is_correct_input(char **av);
int					nbstr_cmp(const char *s1, const char *s2);

#endif