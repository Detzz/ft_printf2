#include "ft_printf.h"

void	ft_putnbr_fdu(unsigned int n, int fd)
{
	unsigned int	nouvar;

	nouvar = n;
	if (nouvar <= 9)
	{
		ft_putchar_fd(nouvar + 48, fd);
	}
	if (nouvar > 9)
	{
		ft_putnbr_fd(nouvar / 10, fd);
		ft_putchar_fd(nouvar % 10 + 48, fd);
	}
}


void putchar2(unsigned int d , int r)
{
   if ( g_zero != 0 && g_point == 0)
    {
        g_nmbr2 = g_nmbr1;
        g_nmbr1 = 0;
    }
   if (r < 0 && d == 0 && g_point != 0)
    {
        if (g_minus != 0)
        {
        ft_putchar_fd('0',1);
        min_width();
        }
        if (g_minus == 0){
            if (g_zero != 0)
            {
              g_nmbr2 =g_nmbr1;
              precision();
            }
            else
            {
                min_width();
            }
            
        ft_putchar_fd('0',1);
      
        }        
    }
   else   if (g_nmbr2 == 0 && d == 0 && r == 0)
    {
        if(g_point == 0 )
        {
            if(g_minus == 0)
            min_width();
            ft_putchar_fd('0',1);
            if (g_minus != 0)
            min_width();
        }
        else
        {
            g_nmbr1 = g_nmbr1 + 1;
        min_width();
        }
        
        
    }
   
    else{
    
        if (g_minus != 0)
        {
            precision();
            ft_putnbr_fdu(d,1);
            min_width();         
        }
        else if(g_zero != 0 && r < 0)
        {
            g_nmbr2 = g_nmbr1;
            precision();
            ft_putnbr_fdu(d,1);
        }
        else
        {        
            min_width();
            precision();
            ft_putnbr_fdu(d,1);
        
        }       
    
    }
}


void traitu(void)
{
    unsigned int d;
    int r;

    r = 0;
    if (g_1etoile != 0)
    {
        g_1etoile =  va_arg(ap, int);
        g_nmbr1 = g_1etoile;
        if (g_nmbr1 < 0)
        {
            g_minus = 1;
            g_nmbr1 = -g_nmbr1;
        }
    }
    if (g_2etoile != 0)
    {
        g_2etoile =  va_arg(ap, int);
        g_nmbr2 = g_2etoile;
          r = g_nmbr2;
    }
    d = va_arg(ap,  unsigned int);
    if(g_nmbr2 == 0 && g_nmbr1 == 0 && g_point == 0)
        ft_putnbr_fdu(d,1);
    else
    {
    g_nmbr2 -= lenth(d);
    if (g_nmbr2 < 0)
        g_nmbr2 = 0;
    else
     g_nmbr2 =  (g_nmbr2 == 0) ? 0 : g_nmbr2 ;
    g_nmbr1 -= (g_nmbr2 + lenth(d));
    putchar2(d, r);
    }


}
