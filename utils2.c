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
int max(t_list *s)
{
    int max;
    max = s ->content;
    while (s)
    {
        if (s->content > max)
            max = s->content;
        s = s->next;
    }
    return max;
}
// int check_min(t_list *s, int len)
// {
//     int min;
//     int i;
//     i = 0;
//     min = s ->content;
//     while (s && len > i)
//     {
//         if (s->content < min)
//             min = s->content;
//         s = s->next;
//         i++;
//     }
//     return min;
// }