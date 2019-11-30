#include "ft_printf.h"
#include <stdio.h>
#include <string.h>

#include "test.h"

#define D42_NXT_WA 1
#define D42_NXT_PA 2
#define D42_NXT_CNT 3

char *next_prfx(int flags)
{
	static char buffer[50];
	int idx;
	static int fdx = 0;
	static int wdx = 0;
	static int pdx = 0;
	char *wstr[D42_WCNT] = D42_WARGS;
	char *pstr[D42_PCNT] = D42_PARGS;
	char *fstr[D42_FCNT] = D42_FARGS;
	idx = 0;
	while(idx < 50)
		buffer[idx++] = 0;
	strcat(buffer, fstr[fdx]);
	if (!(flags & D42_NXT_WA))
		strcat(buffer, wstr[wdx]);
	else
		strcat(buffer, "*");
	if (!(flags & D42_NXT_PA))
		strcat(buffer, pstr[pdx]);
	else
		strcat(buffer, ".*");
	if (!(flags & D42_NXT_PA))
		if (++pdx < D42_PCNT)
			return buffer;
	pdx = 0;
	if (!(flags & D42_NXT_WA))
		if (++wdx < D42_WCNT)
			return buffer;
	wdx = 0;
	if (++fdx < D42_FCNT)
		return buffer;
	fdx = 0;
	return NULL;
}

void test()
{
	static char buffer[50];
	static char format[50];
	static char info[5];
	char *prfx;
	D42_ATYPE pfarg[D42_ACNT] = D42_ARGS;

	int adx = 0;
	int ndx;
	while (adx < D42_ACNT)
	{
		ndx = 0;
		while (ndx < D42_NXT_CNT)
		{
			while((prfx = next_prfx(ndx)))
			{
				bzero(buffer, 50);
				bzero(format, 50);
				bzero(info, 5);
				strcat(format, prfx);
				strcat(format, D42_CONV);
				strcat(buffer, "format <%");
				strcat(buffer, format);
				strcat(buffer, ">\n");
				strcat(info, "%");
				strcat(info, D42_CONV);
				if (ndx == 0)
				{
					printf("Formating : %%%s with arg = |", format);
					fflush(stdout);
					printf(info, pfarg[adx]);
					fflush(stdout);
					printf("|\n");
					fflush(stdout);
				}
				if (ndx > 0)
				{
					int warg[D42_WACNT] = D42_WAARGS;
					int parg[D42_PACNT] = D42_PAARGS;
					int wadx = 0;
					int padx = 0;
					while (1)
					{
						printf("Formating : %%%s with arg = |", format);
						fflush(stdout);
						printf(info, pfarg[adx]);
						fflush(stdout);
						printf("|");
						fflush(stdout);
						if (ndx & D42_NXT_WA)
						{
							printf(" width = %d", warg[wadx]);
							fflush(stdout);
						}
						if (ndx & D42_NXT_PA)
						{
							printf(" prec = %d", parg[padx]);
							fflush(stdout);
						}
						printf("\n");
						fflush(stdout);		

						switch (ndx)
						{
							case 1:
								printf(buffer, warg[wadx], pfarg[adx]);
								fflush(stdout);
								break;
							case 2:
								ft_printf(buffer, parg[padx], pfarg[adx]);
								fflush(stdout);
								break;
							default:
								ft_printf(buffer, warg[wadx++], parg[padx], pfarg[adx]);
								fflush(stdout);
								break;
						}
						if (ndx == 1 || ndx == 3)
						{
							if (++wadx < D42_WACNT)
								continue;
							if (ndx == 1)
								break;
							else
								wadx = 0;
						}
						if (ndx >= 2)
						{
							if (++padx < D42_PACNT)
								continue;
							break;
						}
					}
				}
				else
				{
					ft_printf(buffer, pfarg[adx]);
					fflush(stdout);
				}
			}
			ndx++;
		}
		adx++;
	}
}

int main()
{
	test();
	//int count = 0;
	//while(next_prfx(3) && ++count)
	//	printf("%d\n", count)
	//	;
}
