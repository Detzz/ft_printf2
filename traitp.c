#include "ft_printf.h"

int     lenthp(long nb)
{
    int i;
    i = 1;
    if (nb < 0)
    {
        nb = -nb;
        while ((nb = (nb / 16)) != 0)
        {
            i++;
        }
        i = i + 1;
    }
    else
    {
        while ((nb = (nb / 16)) != 0)
        {
            i++;
        }
    }
    return (i + 2);
}

void        hexapointer(size_t n)
{
    if (n / 16)
        hexapointer(n / 16);
    if ((n % 16) >= 10)
        ft_putchar_fd((n % 16) + 'a' - 10, 1);
    else
        ft_putchar_fd((n % 16) + '0', 1);
    
}
void        pointer(void *n)
{
    ft_putstr_fd("0x",1);
    hexapointer((size_t)n);
}

void putchar4(void *d , int r)
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
        ft_putstr_fd("0x",1);
        }
        
        
    }
   
    else{
    
        if (g_minus != 0)
        {
            precision();
            pointer(d);
            min_width();         
        }
        else if(g_zero != 0 && r < 0)
        {
            g_nmbr2 = g_nmbr1;
            precision();
            pointer(d);
        }
        else
        {        
            min_width();
            precision();
            pointer(d);
        
        }       
    
    }
}


void traitp()
{
    void *d;
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
    d = va_arg(ap,  void*);
    if(g_nmbr2 == 0 && g_nmbr1 == 0 && g_point == 0)
        pointer(d);
    else
    {
    g_nmbr2 -= lenthp((long)d);
    if (g_nmbr2 < 0)
        g_nmbr2 = 0;
    else
     g_nmbr2 =  (g_nmbr2 == 0) ? 0 : g_nmbr2 ;
    g_nmbr1 -= (g_nmbr2 + lenthp((long)d));
    putchar4(d, r);
    }


}
