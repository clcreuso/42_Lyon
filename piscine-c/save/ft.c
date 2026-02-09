
#include <stdio.h>

int	ft_check_diag(int tab[8][8], int y, int x, int sy, int sx)
{
    while (y >= 0 && x >= 0)
        if (tab[y--][x--] == 1)
            return (0);
    y = sy;
    x = sx;
    while (y >= 0 && x <= 7)
        if (tab[y--][x++] == 1)
            return (0);
    y = sy;
    x = sx;
    while (y <= 7 && x <= 7)
        if (tab[y++][x++] == 1)
            return (0);
    y = sy;
    x = sx;
    while (y <= 7 && x >= 0)
        if (tab[y++][x--] == 1)
            return (0);
    return (1);
}

int	ft_print_first_queen(int tab[8][8], int y, int x)
{
    int save_y;
    int save_x;
    
    save_y = y;
    save_x = x;
    y = 0;
    while (y < 8)
        if(tab[y++][x])
            return 0;
    y = save_y;
    x = 0;
    while (x < 8)
        if(tab[y][x++])
            return 0;
    x = save_x;
    if (ft_check_diag(tab, y, x, save_y, save_x))
        return (1);
    return (0);
}

int main()
{
	int a = ft_eight_queens_puzzle();
	printf("%d", a);
}
