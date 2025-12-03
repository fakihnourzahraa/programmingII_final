
#include "so_long.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	count;
	size_t	actual_len;

	count = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		new = malloc(1);
		new[0] = '\0';
		return (new);
	}
	actual_len = ft_strlen(s + start);
	if (actual_len < len)
		len = actual_len;
	new = (char *)malloc(len + 1);
	if (!new)
		return (NULL);
	while (s[start] && count < len)
	{
		new[count++] = s[start++];
	}
	new[count] = '\0';
	return (new);
}
