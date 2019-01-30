#include <unistd.h>


int ft_putchar(char c)
{
		write(1, &c, 1);
		return (0);
}

void ft_putnbr(int nb)
{
	int desyatki = 1;
	while (nb /desyatki != 0)
	{
	desyatki = desyatki * 10;
	}
	desyatki = desyatki / 10;
	while (desyatki != 1)
	{
		char l;
		int numbr;
		numbr = nb / desyatki;
		numbr = numbr % 10;
		l = '0' +  numbr;
		ft_putchar(l);
		desyatki = desyatki / 10;
	}
	int numbr;
	numbr = nb % 10;
	char l;
	l = '0' +  numbr;
	ft_putchar(l);
	ft_putchar('\n');	
}

int main()
{
		ft_putnbr(1567);
		return (0);
}
