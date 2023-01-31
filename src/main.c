/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmoren <antmoren@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:02:32 by antmoren          #+#    #+#             */
/*   Updated: 2023/01/31 19:42:09 by antmoren         ###   ########.fr       */
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
// LEAKS
/* void ft_void()
{
	system("leaks -q push_swap");
}
 */

void	order_stack(t_stack	*stack_a, t_stack	*stack_b)
{
	int		stack_size;

	stack_size = get_stack_size(stack_a);
	add_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

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
		free_array(numbers_array);
	}
	else
	{
		if (!is_correct_input(argv, 1))
			exit_error(NULL, NULL);
		stack_b = NULL;
		stack_a = fill_stack(argc, argv, 1);
	}
	order_stack(stack_a, stack_b);
	return (0);
}

// LEAKS atexit(ft_void);
//LEAKS
	/* while (stack_a)
	{
		ft_printf("%d\n", stack_a->value);
		stack_a = stack_a->next;
	} */