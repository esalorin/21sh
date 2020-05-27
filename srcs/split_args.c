/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 14:27:24 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/05/27 18:09:12 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char	**escapes(char **array)
{
	int		i;
	char	*tmp;

	i = 0;
	while (array && array[i])
	{
		tmp = ft_rmescapes(array[i]);
		ft_strdel(&array[i]);
		array[i++] = tmp;
	}
	return (array);
}

static char	**last(char **array, char *s, int i, int j)
{
	char	**des;
	char	**temp;
	char	*tmp;

	tmp = ft_strsub(s, j, (i - j));
	temp = escapes(ft_strsplit(tmp, ' '));
	if (j > 1 && ft_isprint(s[j - 2]))
	{
		array[ft_arraylen(array) - 1] = ft_joindel(array[ft_arraylen(array)
		- 1], ft_strdup(temp[0]));
		if (temp[1])
			des = ft_array_merge(array, ft_arrayrem(temp, 0));
		else
			des = array;
		ft_arraydel(temp);
	}
	else
		des = ft_array_merge(array, temp);
	ft_strdel(&tmp);
	return (des);
}

static char	**quotes(char **array, char *s, int *i, int *j)
{
	char	**ar1;
	char	**ar2;
	char	*temp;
	char	c;

	c = s[*i];
	temp = ft_strsub(s, *j, (*i - *j));
	ar1 = ft_strsplit(temp, ' ');
	ar2 = ft_array_merge(array, escapes(ar1));
	ft_strdel(&temp);
	*j = ++(*i);
	while (s[*i] != c || (s[*i] == c && c == 34 && !count_slash(s, *i)))
		(*i)++;
	temp = ft_rmescapes_inquotes(ft_strsub(s, *j, (*i - *j)), c);
	if (*j > 1 && ft_isprint(s[*j - 2]))
	{
		*j = *i + 1;
		ar2[ft_arraylen(ar2) - 1] = ft_joindel(ar2[ft_arraylen(ar2) - 1], temp);
		return (ar2);
	}
	*j = *i + 1;
	ar1 = ft_array_push(ar2, temp, -1);
	ft_strdel(&temp);
	ft_arraydel(ar2);
	return (ar1);
}

static char	**split_args(char *s)
{
	char	**temp;
	char	**array;
	int		j;
	int		i;

	i = 0;
	j = 0;
	array = ft_arraynew(0);
	while (1)
	{
		if ((s[i] == 34 || s[i] == 39) && count_slash(s, i))
		{
			temp = quotes(array, s, &i, &j);
			array = temp;
		}
		else if (s[i] == '\0')
		{
			temp = last(array, s, i, j);
			array = temp;
			break ;
		}
		i++;
	}
	ft_strdel(&s);
	return (array);
}

char		**check_if_quotes(char *s)
{
	char	*s1;
	char	*s2;
	char	*tmp;
	int		q;

	if ((q = quote_match(s)) == 0 && count_slash(s, ft_strlen(s)))
		return (escapes(ft_strsplit(s, ' ')));
	s1 = ft_strdup(s);
	while (q % 2 != 0 || q == 34 || q == 39 || !count_slash(s1, ft_strlen(s1)))
	{
		if (q == 34 || q == 39)
			ft_printf((q == 34) ? "dquote" : "quote");
		ft_printf("> ");
		get_next_line(0, &tmp);
		(q == 2 || q == 0) && !tmp[0] ? ft_strdel(&tmp) : 0;
		if ((q == 2 || q == 0) && !tmp[0])
			break ;
		s2 = (q == 2 || q == 0) ? ft_strdup(tmp) :
		ft_strjoin("\n", tmp);
		ft_strdel(&tmp);
		s1 = ft_joindel(s1, s2);
		q = quote_match(s1);
	}
	return (split_args(s1));
}
