/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmoren <antmoren@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:02:32 by antmoren          #+#    #+#             */
/*   Updated: 2023/01/27 14:10:07 by antmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		sa(stack_a);
	else if (stack_size == 3)
		sort_small(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
	char	**numbersArray;

	(void)argv;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		numbersArray = formatArray(argv[1]);
		if (!is_correct_input(numbersArray, 0))
			exit_error(NULL, NULL);
		stack_b = NULL;
		stack_a = fill_stack(arrLength(numbersArray), numbersArray, 0);
	}
	else
	{
		if (!is_correct_input(argv, 1))
			exit_error(NULL, NULL);
		stack_b = NULL;
		stack_a = fill_stack(argc, argv, 1);
	}
	stack_size = get_stack_size(stack_a);
	add_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
