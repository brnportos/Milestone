#include "push_swap.h"

static void	stack_rotation(t_stack **a)
{
	t_stack	*last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	last = *a;
	while (last->next != NULL)
		last = last->next;
	last->next = *a;
	*a = (*a)->next;
	last->next->next = NULL;
}

void	ra(t_stack **a, t_stats *ops)
{
	stack_rotation(a);
	write(1, "ra\n", 3);
	if (ops)
	{
		ops->ra++;
		ops->total_ops++;
	}
}