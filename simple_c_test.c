#include "ft_printf.h"
#include <stdio.h>
int main()
{
	int orig, fake;
	orig = printf("Toto <%03c>\n", (char)(0));
	fake = ft_printf("Toto <%03c>\n", (char)(0));
	printf("%d = %d ?\n", orig, fake);
	return (0);
}
