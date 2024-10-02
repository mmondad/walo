#include "cub3d.h"

int	ft_sep_mot(char *str, char sep, int ptr)
{
	int	i;

	i = ptr;
	while (str[i])
	{
		if (str[i] != sep)
		{
			i++;
		}
		else
			break ;
	}
	return (i - ptr);
}

char	*ft_locmot(char *str, int *ptr, char sep, t_info *info)
{
	int		j;
	int		k;
	char	*locmot;

	k = 0;
	j = ft_sep_mot(str, sep, *ptr);
	locmot = ft_malloc(sizeof(char) *(j + 1), info);
	if (!locmot)
		return (NULL);
	while (str[*ptr] && str[*ptr] != sep)
	{
		locmot[k] = str[*ptr];
		(*ptr)++;
		k++;
	}
	locmot[k] = '\0';
	return (locmot);
}

int	ft_countr_mot(char *s, char c)
{
	char	*m;
	int		count;
	int		i;

	i = 0;
	count = 0;
	m = (char *)s;
	while (m[i])
	{
		if (m[i] != c)
		{
			while (m[i] != c && m[i])
				i++;
			count++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_split(char *s, char c, t_info *info)
{
	int		i;
	char	**split;
	int		j;

	i = 0;
	j = 0;
	split = ft_malloc(sizeof(char *) * (ft_countr_mot(s, c) + 1), info);
	if (!split)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			split[j] = ft_locmot(s, &i, c, info);
			j++;
			if (s[i] == '\0')
				break ;
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}