#include "push_swap.h"

int min(t_list *s)
{
    int min;
    min = s ->content;
    while (s)
    {
        if (s->content < min)
            min = s->content;
        s = s->next;
    }
    return min;
} 