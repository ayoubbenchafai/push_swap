/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:26:36 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/03 18:44:14 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_list
{
    int             index;
    struct s_list    *next;
}   t_list;

void ft(t_list **s)
{
    // stack fram ft
    // s = 0XFFFFFF / *s = 0x5FDF6454 / **s = 42
    // *s = 0xEFEFEF  /
    s->index = 1; // * = ->
}

int main ()
{
    int *s; //  stack fram main : 
            //  *s = 42 / {s = 0x5FDF6454;} / &s = 0xFFFFFF
    
    //printf("%d", (int)*s);
    ft(&s);
    return (0);
}