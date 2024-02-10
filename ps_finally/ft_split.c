/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 11:57:11 by aben-cha          #+#    #+#             */
/*   Updated: 2024/02/10 20:15:59 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <string.h>

// int check_min_max(int n)
// {
//     if(n > INT_MAX || n < INT_MIN)
//         return(0);
//     return (1);
// }
// int	ft_atoi(const char *str)
// {
// 	int				i;
// 	int				sign;
// 	long             result;

// 	i = 0;
// 	sign = 1;
// 	result = 0;
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i] == '-')
// 			sign *= -1;
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		result = (result * 10) + str[i] - '0';
// 		i++;
// 	}
//     if(!check_min_max(result))
//         return (puts("Error\n"), -1);

// 	return (sign * (int)result);
// }

// int main()
// {
//     printf("%d\n",atoi("-2147483649"));
//     printf("test\n");

//     printf("test : %d\n",ft_atoi("-2147483649"));
//     return (0);
// }
int	ft_atoi(const char *str)
{
	int     i;
	int     sign;
	int     result;

	i = 0;
	sign = 1;
	result = 0;
	// while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	// 	i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	return (sign * result);
}
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*tab;

	i = 0;
	tab = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!tab)
		return (NULL);
	while (s[i])
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

int	nbr_strings(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			len++;
		while (*s && *s != c)
			s++;
	}
	return (len);
}

static void	free_memory(char **ptr, int j)
{
	while (j)
	{
		j--;
		free(ptr[j]);
	}
	free(ptr);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	s_length;

	i = 0;
	if (s == NULL)
		return (NULL);
	s_length = ft_strlen(s);
	if (start >= s_length)
		return (ft_strdup(""));
	if (len > (s_length - start))
		len = s_length - start;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	while (i < len)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}

static char	**ft_allocate_words(char const *s, char c, int size, int j)
{
	int		i;
	char	**ptr;

	ptr = (char **)malloc(sizeof(char *) * (size + 1));
	if (!ptr)
		return (0);
	while (j < size)
	{
		while (*s != '\0' && *s == c)
			s++;
		i = 0;
		while (s[i] != '\0' && s[i] != c)
			i++;
		ptr[j] = ft_substr(s, 0, i);
		if (!ptr[j])
		{
			free_memory(ptr, j);
			return (0);
		}
		s += i;
		j++;
	}
	ptr[j] = (0);
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	int		size;
	char	**ptr;

	if (!s)
		return (0);
	size = nbr_strings(s, c);
	j = 0;
	ptr = ft_allocate_words(s, c, size, j);
    return (ptr);
}


// int main(int ac, char **av)
// {
//     char **res ;
//     int i = 0;
//     int j = 0;
//     int n;
//     while(++i < ac)
//     {
//         res = ft_split(av[i], ' ');
//         while(res[j])
//         {
//             n = atoi(res[j]);
//             printf("%d\n", n);
//             j++;
//         }
//         i++;
//     }
//     while(i--)
//         free(res[i]);
//     free(res);

//     return (0);
// }