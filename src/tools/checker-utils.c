/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker-utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmoren <antmoren@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:10:59 by antmoren          #+#    #+#             */
/*   Updated: 2023/01/27 14:11:20 by antmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_strcmp(char *stack_a, char *stack_b)
{
	int	i;

	i = 0;
	if (ft_strlen(stack_a) != ft_strlen(stack_b))
		return (0);
	while (stack_a[i])
	{
		if (stack_a[i] != stack_b[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_operations_2(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(line, "ra\n"))
		ra(stack_a);
	else if (ft_strcmp(line, "rb\n"))
		rb(stack_b);
	else if (ft_strcmp(line, "rr\n"))
		rr(stack_a, stack_b);
	else if (ft_strcmp(line, "rra\n"))
		rra(stack_a);
	else if (ft_strcmp(line, "rrb\n"))
		rrb(stack_b);
	else if (ft_strcmp(line, "rrr\n"))
		rrr(stack_a, stack_b);
	else
		exit_error(stack_a, stack_b);
}

void	ft_operations(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(line, "sa\n"))
		sa(stack_a);
	else if (ft_strcmp(line, "sb\n"))
		sb(stack_b);
	else if (ft_strcmp(line, "ss\n"))
	{
		sa(stack_a);
		sb(stack_b);
	}
	else if (ft_strcmp(line, "pa\n"))
		pa(stack_a, stack_b);
	else if (ft_strcmp(line, "pb\n"))
		pb(stack_b, stack_a);
	else
		ft_operations_2(line, stack_a, stack_b);
}

void	ft_check(t_stack *stack_a, t_stack *stack_b)
{
	char *line;

	line = get_next_line(0);
	while (line)
	{
		ft_operations(line, &stack_a, &stack_b);
		free(line);
		line = get_next_line(0);
	}
	if (stack_a && !stack_b && is_sorted(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}