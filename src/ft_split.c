/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 23:33:01 by amartel           #+#    #+#             */
/*   Updated: 2025/10/18 19:37:43 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_count_words(char const *s, char c)
{
    int	count;
    int	in_word;

    count = 0;
    in_word = 0;
    while (*s)
    {
        if (*s != c && !in_word)
        {
            in_word = 1;
            count++;
        }
        else if (*s == c)
            in_word = 0;
        s++;
    }
    return (count);
}
static void ft_free_error(char **res) {
    int	i;

    i = 0;
    while (res[i])
    {
        free(res[i]);
        i++;
    }
    free(res);
}
static char	*ft_word_dup(const char *s, char c)
{
    int		len;
    char	*word;

    len = 0;
    while (s[len] && s[len] != c)
        len++;
    word = ft_calloc(len + 1, sizeof(char));
    if (!word)
        return (NULL);
    ft_memcpy(word, s, len);
    return (word);
}

char	**ft_split(char const *s, char c)
{
    char	**res;
    int		i = 0;

    if (!s)
        return (NULL);
    res = ft_calloc(ft_count_words(s, c) + 1, sizeof(char *));
    if (!res)
        return (NULL);
    while (*s)
    {
        if (*s != c)
        {
            res[i] = ft_word_dup(s, c);
            if (!res[i])
            {
                ft_free_error(res);
                return (NULL);
            }
            i++;
            while (*s && *s != c)
                s++;
        }
        else
            s++;
    }
    return (res);
}


// TODO : norm ! and verif on ubuntu