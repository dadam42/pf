#include "ft_printf.h"
#include <stdio.h>
int main()
{
	int orig, fake;
	orig = printf("Toto <%08.2d>\n", 421);
	fake = ft_printf("Toto <%08.6d>\n", 421);
	printf("%d = %d ?\n", orig, fake);
	return (0);
}
