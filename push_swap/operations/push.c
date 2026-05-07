#include "push_swap.h"

void	pa(t_stack **a, t_stack **b, t_stats *ops)
{
	t_stack	*tmp;

	if (!b || !(*b))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	write(1, "pa\n", 3);
	if (ops)
	{
		ops->pa++;
		ops->total_ops++;
	}
}
