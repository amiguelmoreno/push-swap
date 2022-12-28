/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmoren <antmoren@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:02:32 by antmoren          #+#    #+#             */
/*   Updated: 2022/12/28 21:44:13 by antmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	(void)argv;
	if (argc < 2)
		return (0);
	if (!is_correct_input(argv))
		exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = fill_stack(argc, argv);
	stack_size = get_stack_size(stack_a);
	return (0);
}
