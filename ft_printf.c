/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aali-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 20:12:43 by aali-mou          #+#    #+#             */
/*   Updated: 2019/12/07 22:51:03 by aali-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		passdigits(const char *fmt, int i)
{
	while (ft_isdigit(fmt[i]) == 1)
	i++;
	return(i);
}


void	traitformats(const char *fmt, int i)
{
	if (fmt[i] == 'd' || fmt[i] == 'i')  traitd();
	/*(fmt[i] == 's') ? traits();
	*/if (fmt[i] == 'u')  traitu();
	/*(fmt[i] == 'c') ? traitc();
	*/if (fmt[i] == 'x' || fmt[i] == 'X')  traitx(fmt, i);
	if (fmt[i] == 'p')  traitp();
	/*(fmt[i] == '%') ? traitpourcentage();*/

}



int	traitementdesflags(const char *fmt, int i)
{
	i++;

		g_minus = (fmt[i] == '-') ? i++ : 0;
		g_zero = (fmt[i] == '0') ? i++ : 0;
		g_nmbr1 = (ft_isdigit(fmt[i]) == 1) ? ft_atoi(&fmt[i]) : 0;
		i = (ft_isdigit(fmt[i]) == 1) ? passdigits(fmt, i): i++;
		g_1etoile = (fmt[i] == '*') ? i++ : 0;
		g_point = (fmt[i] == '.') ? i++ : 0;
		g_nmbr2 = (ft_isdigit(fmt[i]) == 1) ? ft_atoi(&fmt[i]) : 0;
		i = (ft_isdigit(fmt[i]) == 1) ? passdigits(fmt, i): i++;
		g_2etoile= (fmt[i] == '*') ? i++ : 0;

		traitformats(fmt, i);
		i++;
		return (i);

}


void	global(void)
{
	g_zero = 0;
	g_pourcentage2 = 0;
	g_minus = 0;
	g_1etoile = 0;
	g_2etoile = 0;
	g_point = 0;
	g_nmbr1 = 0;
	g_nmbr2 = 0;
	g_count = 0;
	g_moin = 0;
}

int     ft_printf(const char *fmt, ...)
{
	int x;
	int i;

	global();
	x = 0;
	i = 0;
	va_start(ap, fmt);
	while (fmt[i] != '\0')
	{
		x = i;
		while (fmt[x] != '%' && fmt[x] != '\0')
			x++;
		while (i < x)
		{
			ft_putchar_fd(fmt[i],1);
			i++;
		}
		if (fmt[i] == '%')
			x  = traitementdesflags(fmt, i);
		if (x == 0)
			return (g_count);
		i = x;
		if (fmt[i] == '\0')
			return(g_count);
		//i++;
	}
	va_end(ap);
	return(g_count);
}
/*int main()
{int i;
	i = ft_printf("%.p", (void *)0x0);
	printf ("    %d",i);
	i = printf("\n%.p", (void *)0x0);
	printf ("    %d",i);
}*/