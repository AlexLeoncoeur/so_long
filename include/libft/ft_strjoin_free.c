
#include "libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	size_t		size;
	char		*str;
	char		*aux;
	int			i;
	int			j;

	str = (char *)s1;
	i = 0;
	j = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	if (size == 0)
		return (ft_strdup(""));
	aux = malloc(sizeof(char) * (size + 1));
	if (aux == NULL)
		return (0);
	while (s1 && s1[i] != '\0')
	{
		aux[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
	{
		aux[i + j] = s2[j];
		j++;
	}
	aux[i + j] = '\0';
	if (str)
		free(str);
	return (aux);
}