/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:19:27 by malord            #+#    #+#             */
/*   Updated: 2022/06/09 16:07:53 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*s;
	size_t	n;

	n = (count * size);
	s = malloc(count * size);
	i = 0;
	if (!s)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
	return (s);
}

char	*ft_free(void *ptr)
{
	if (ptr)
	{
		free (ptr);
		ptr = NULL;
	}
	return (NULL);
}

char	*ft_strncpy(char *dest, char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src)
		return (dest);
	while (src[i] != 0 && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

size_t	ft_strlen_until(char *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != c)
		i++;
	if (!c)
		return (i);
	if (s[i] != c)
		return (0);
	else
		return (i + 1);
}

char	*ft_strjoin_free(char *s1, char const *s2)
{
	size_t	tlen;
	char	*nstr;
	int		i;

	i = 0;
	tlen = ft_strlen_until(s1, 0) + ft_strlen_until((char *)s2, 0) + 1;
	nstr = ft_calloc((tlen), sizeof(char));
	if (!nstr)
		return (NULL);
	if (s1)
	{
		while (s1[i])
			*nstr++ = s1[i++];
		free (s1);
	}
	if (s2)
		while (*s2)
			*nstr++ = *s2++;
	*nstr++ = '\0';
	return (nstr - tlen);
}
