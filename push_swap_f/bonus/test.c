/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:38:14 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/16 17:49:54 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <stdio.h>
int spaces(char *s)
{
    int i = 0;
    int len_s = ft_strlen(s);
    while(s[i])
    {
        if(!(s[i] == ' '))
            return (0);
        i++;
    }
    if(i == len_s)
        return (1);
    return (0);   
}

int main(int ac, char **av)
{
        
    char *res[3] = {"  jjj ", " 09 5 6", "    "};
    // if(!res)
    int i = 0;
    while(i < 3)
    {
        if(spaces(res[i]))
            printf("error\n");
        else
            printf("%s\n",res[i]);    
        i++;
    }
    //     printf("res : %s\n", res[0]);
    //     printf("res : %s\n", res[1]);
        

    printf("success : %d\n", i);
    return (0);
}