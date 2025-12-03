
#include "game.h"

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	int		i;

	i = 0;
	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
		i++;
	}
	if (nb >= 10)
		i += ft_putnbr_fd(nb / 10, fd);
	i += ft_putchar_fd(nb % 10 + '0', fd);
	return (i);
}
