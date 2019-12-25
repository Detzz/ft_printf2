/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aali-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:31:27 by aali-mou          #+#    #+#             */
/*   Updated: 2019/10/30 14:00:22 by aali-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int g_pourcentage2;
int g_minus;
int g_1etoile;
int g_2etoile;
int g_point;
int g_nmbr1;
int g_nmbr2;
int g_count;
int g_zero;
va_list ap;
int g_moin;


int		ft_printf(const char *fmt, ...);
void	global(void);
int		traitementdesflags(const char *fmt, int i);
int		passdigits(const char *fmt, int i);
int		ft_isdigit(int c);
void	traitformats(const char *fmt, int i);
int		ft_atoi( const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	traitd(void);
void	traitu(void);
void    min_width(void);
void    precision(void);
int     lenth(long nb);
void    traitx(const char *fmt, int i);
void    traitp();









#endif
