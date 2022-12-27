/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmoren <antmoren@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:36:00 by antmoren          #+#    #+#             */
/*   Updated: 2022/12/27 13:48:58 by antmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../42-library/includes/ft_printf.h"
# include "../42-library/includes/get_next_line_bonus.h"
# include "../42-library/includes/libft.h"

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

int					is_correct_input(char **av);
int					arg_is_number(char *av);
int					arg_is_zero(char *av);
int					have_duplicates(char **av);
void				free_stack(t_stack **stack);
void				exit_error(t_stack **stack_a, t_stack **stack_b);
int					nb_abs(int nb);
int					is_sign(char c);
int					nbstr_cmp(const char *s1, const char *s2);

#endif