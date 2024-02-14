#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define MAX_INT  2147483647
# define MIN_INT -2147483648

typedef struct  s_flags
{
    int index;
    int lenght;
    char specifier;
    
    int hashtag;
    int space;
    int plus;
    int minus;
    int zero;
    int point;
}               t_flags;

int	    ft_printf(const char *format, ...);
int	    ulen(unsigned int n);
int	    print_u(unsigned int n);
int	    print_str(char *str);
int	    ptr_len(unsigned long long n);
void	get_ptr(unsigned long long n);
int	    print_ptr(unsigned long long n);
int	    print_percent(void);
int	    nbrlen(int n);
int	    print_nbr(int n);
int 	hex_len(unsigned	int n);
int	    get_hex(unsigned int n, const char c);
int	    print_hex(unsigned int n, const char c, t_flags *f);
int	    print_char(const char c);
int	    parser(va_list args, char c, t_flags *f);

// warnings
void    hashtag_warning(void);
void    plus_warning(void);
void    minus_warning(void);
void    space_warning(void);
void    point_warning(void);
void    zero_warning(void);
void    check_warnings(t_flags *f);

// utils
void    init_flags(t_flags *f);
void    reset_flags(t_flags *f);
int     is_specifier(char c);
int     is_flag(char c);
size_t  ft_strlen(char *str);

// main
int     main_loop(const char *format, t_flags *f, va_list args);
char    *get_flags_and_specifier(const char *format, t_flags *f);
void     parse_flags_get_info(char *flags, t_flags *f);

#endif