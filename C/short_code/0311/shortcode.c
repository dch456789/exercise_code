#include <stdio.h>


int main(void)
{
    int i=31;
    {
        int j = 21;
        printf("%d\n",j);
    }
    int j = 44;
    printf("[[%d]]\n[[%d]]",i,j);
    return 0;
}