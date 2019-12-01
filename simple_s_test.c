#include "ft_printf.h"
#include <stdio.h>
int main()
{
	int orig, fake;
	orig = printf("Toto <%-7s>\n", 0);
	fake = ft_printf("Toto <%-7s>\n", 0);
	printf("%d = %d ?\n", orig, fake);
	return (0);
}
