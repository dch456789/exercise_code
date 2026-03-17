#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "test\file1.h"

void try1(void)
{
    const int x = 10;
    int *ptr = &x;
    printf("%d\n",x);    //10
    *ptr = 20;  
    printf("%d\n",x);    //20
    int *const ptr2 = &x;
    *ptr = 20;
    printf("%d\n",x);    //20
    return;
}

void try2(void)    //重写计算器
{
    double fir;
    double sec;
    char mid;
    puts("这是一个加减乘除计算器。");
//输入第一个数字
    while(1)
    {
        puts("请输入第一个数字：键入esc退出");
        char input[50];
        double num1;
        fgets(input,sizeof(input),stdin);
        input[strcspn(input,"\n")] = '\0';
        if(!strlen(input))
        {
            puts("输入有误，请重新输入：");
            continue;
        }
        if(!strcmp(input,"esc"))
        {
            puts("谢谢使用。");
            return;
        }
        char *endptr;
        num1 = strtod(input,&endptr);    //stdlib.h函数，用于将字符型转换为浮点型，并将第二个指针指向浮点型的后一位地址。
        if(input == endptr || *endptr != '\0')
        {
            puts("请输入纯数字！");
            continue;
        }
        printf("%.2f\n",num1);
        fir = num1;
        break;
    }
//输入操作符
    while(1)
    {
        puts("请输入操作符：[+] [-] [*] [/]");

        char operator;
        scanf("%c",&operator);
        while(getchar() != '\n');
        /* if(scanf("%c",&operator))
        {
            puts("输入有误，请重新输入：");
            continue;
        } */
        if(operator != '+' && operator != '-' && operator != '*' && operator != '/')
        {
            puts("不支持的操作符，请重试！");
            continue;
        }
        printf("%c \n",operator);
        mid = operator;
        break;
    }
//输入第二个数字
    while(1)
    {
        puts("请输入第二个数字：键入esc退出");
        char input[50];
        double num1;
        fgets(input,sizeof(input),stdin);
        input[strcspn(input,"\n")] = '\0';
        if(!strlen(input))
        {
            puts("输入有误，请重新输入：");
            continue;
        }
        if(!strcmp(input,"esc"))
        {
            puts("谢谢使用。");
            return;
        }
        char *endptr;
        num1 = strtod(input,&endptr);
        if(input == endptr || *endptr != '\0')
        {
            puts("请输入纯数字！");
            continue;
        }
        if(mid == '/' && num1 == 0)
        {
            puts("除数不能为0，请重新输入：");
            continue;
        }
        printf("%.2f\n",num1);
        sec = num1;
        break;
    }
//运算
    puts("");
    switch(mid)
    {
        case '+':
            printf("%.2f %c %.2f = %.2f",fir,mid,sec,fir + sec);
            break;
        case '-':
            printf("%.2f %c %.2f = %.2f",fir,mid,sec,fir - sec);
            break;
        case '*':
            printf("%.2f %c %.2f = %.2f",fir,mid,sec,fir * sec);
            break;
        case '/':
            printf("%.2f %c %.2f = %.2f",fir,mid,sec,fir / sec);
            break;
        default:
            break;
    }
    return;
}

void try3 (void)
{
    int x;
    int arr[5];
    printf("%d\n",x);    //0  编译器默认优化
    for(int i = 0;i < 5;i++)
    {
        printf("%d ",arr[i]);    //编译器默认没有优化，不确定的值
    }
    printf("\n");
/*     int *a;
    printf("%p,%d",a,*a);
    int *a = NULL;
    printf(",%d",*a);
    return; */
    test();
    test();
    test();
    y++;
    printf("the y = %d",y);    //多文件
}

int main(void)
{
    try3();
    return 0;
}