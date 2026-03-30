#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void lefttrust(char * str,int num);
void lefttrust(char * str,int num)
{
    for(int i = 0,left = 0;i < num;i++)
        {
            if('(' == str[i])left++;
            else if(')' == str[i])left--;
            if(left<0)
            {
                puts("括号不匹配。");
                return;
            }
        }
        puts("括号匹配。");
}
void try1(void)
{
    int num = 0;
    int weigh = 10;
    char *str =(char*)calloc(weigh,sizeof(char));

    while((str[num] = getchar()) != '\n')
    {
        num++;
        if((num)%10 == 0)
        {
            str = (char*)realloc(str,sizeof(char)*(weigh+=10));
            puts("扩容成功");
        }
    }
    printf("%d\n",strlen(str));
    lefttrust(str,num);
    return;
}

int main(void)
{
    try1();
    return 0;
}