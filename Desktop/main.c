#include "./ft_printf/printf.h"

int	main(void)
{
	int	len;
	float	a = 2.875;

	len = 0xdeadc0de;
	printf("\nretval_fake: %d\n", ft_printf("%] %0+ 20d %% %#hhX %.12f", len, len, a));
	printf("\nretval_orig: %d\n", printf("%] %0+ 20d %% %#hhX %.12f", len, len, a));
	printf("%zu && %zu\n", sizeof(unsigned long long), sizeof(intmax_t));
	return (0);
}
