/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmoren <antmoren@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:22:23 by antmoren          #+#    #+#             */
/*   Updated: 2023/02/01 18:31:26 by antmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**numbers_array;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		numbers_array = format_array(argv[1]);
		if (!is_correct_input(numbers_array, 0))
			exit_error(NULL, NULL);
		stack_b = NULL;
		stack_a = fill_stack(arr_length(numbers_array), numbers_array, 0);
	}
	else
	{
		if (!is_correct_input(argv, 1))
			exit_error(NULL, NULL);
		stack_b = NULL;
		stack_a = fill_stack(argc, argv, 1);
	}
	ft_check(stack_a, stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
