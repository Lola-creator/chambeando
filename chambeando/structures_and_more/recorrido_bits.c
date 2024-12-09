
#include <stdio.h>

void magic(int x)
{
    unsigned int mask = 1<<31;
    for(int c=0;c<=32;c++)
    {
        putchar((x & mask ? '1':'0'));
        x<<=1;
        
        if(!(c%8)) putchar(' ');
    }
    putchar('\n');
}


int main()
{
    magic(48);
    return 0;
}

