#include "minirt.h"


void	print_list(t_list *s)
{
	while (s)
	{
		printf("%s", (char *)s->obj);
		s = s->next;
	}
}