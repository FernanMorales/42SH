#include "libft.h"
#include "ft_term.h"
#include <stdio.h>

void    print_l(t_lst *l)
{

    int    i;
    t_elem *tmp;

    tmp = l->first;
    i = 0;
    while (i < l->size_lst)
    {
        printf("%c", tmp->data);
        tmp = tmp->next;
        i++;
    }
}

int    main(void)
{
    t_lst *l;

    l = init_list();
    printf("print : %c add : %p\n", l->first->data, l);
    insert_top(l, 'A');
    insert_top(l, 'B');
    insert_top(l, 'C');
 insert_pos(l, l->first->next, 'D');
    print_l(l);
    printf("\nfirst : %c | last : %c", l->first->data, l->last->data);
    return (0);
}
