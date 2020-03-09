/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:29:36 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/09 18:36:05 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void		kick_from_b(t_stack *a, t_stack *b)
{
	while (b->used_size > 0)
	{
		count_moves(a, b);
		do_moves(a, b);
	}
}

void		sort_small(t_stack *a, t_stack *b)
{
	int 	i;

	i = a->used_size - 1;
	while (a->used_size > 3)
	{
		if (a->arr[i].index != a->min && a->arr[i].index != a->max)
		{
			push_b(a, b);
			i = a->used_size - 1;
		}
		else
			rotate_a(a);
	}
	sort_three(a);
	if (b->used > 0)
	{
		kick_from_b(a, b);
		kick_val_to_top(a, a->max);
	}
}
