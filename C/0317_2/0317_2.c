#include <stdio.h>
int say_hello(void);
void swap(int *a,int *b);
int cmpar_int(int x,int y);
int factorial(int x);
int factorial2(int x);
int say_hello(void)
{
    printf("hellow world!\n");
    return 100;
}
void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int cmpar_int(int x,int y)
{
    if(x>y)
    return 1;
    else if(x==y)
    return 0;

    return -1;
}
int factorial(int x)    //阶乘
{
    int result = 1;
    for(int i = 1;i <= x;i++)
    result *= i;
    return result;
}
int factorial2(int x)    //递归阶乘
{
    if(x > 1)
    return x*factorial2(x-1);
    return 1;
}
int pot(int x)    //演示函数参数传递
{
    printf("pot[x] = %p\n",&x);
    printf("pot`s aria = %p\n",pot);
    return 0;
}
int fib_seq(int x)    //斐波那契数列
{
    if(x == 0)
    {
        return 0;
    }
    if(x == 1)
    {
        return 1;
    }
    return fib_seq(x-1) + fib_seq(x-2);
}
int sushu(int num)    //素数判断
{
    int is_prime = 1;
    for(int i = 2;i < num;i++)
    {
        if(num % i == 0)
        {
            is_prime = 0;
        }
    }
    return is_prime;
}
void sushu2(int x)    //函数调用函数
{
    for(int i = 2;i < x;i++)
    {
        if(sushu(i))
        printf("%d 是素数\n",i);
    }
    return;
}
void sushu3(int x,int y)    //素数的范围显示。
{
    for(int i = x;i < y;i++)
    {
        if(sushu(i))
        printf("%d 是素数\n",i);
    }
    return;
}
//___________________________________________________________
//main函数转移
void firstone(void) 
{
    int x = say_hello();
    int y = 10;
    printf("x = %d,y = %d\n",x,y);
    swap(&x,&y);
    printf("after swap: x = %d,y = %d\n",x,y);
//x和y进行大小比较
    puts("情输入x和y：");
    scanf("%d%d",&x,&y);
    int resule = cmpar_int(x,y);
    switch(resule)
    {
        case 1:
            printf("%d > %d\n",x,y);
            break;
        case -1:
            printf("%d < %d\n",x,y);
            break;
        default :
            printf("%d = %d\n",x,y);
            break;
    }
//阶乘
    int num;
    puts("请输入阶乘数：");
    scanf("%d",&num);
    int result = 1;
    for(int i = 1;i <= num;i++)
    result *= i;
    printf("!%d = %d\n",num,result);
//调用阶乘
    printf("%d\n",factorial(num));
//调用递归阶乘
    printf("%d\n",factorial2(num));
    factorial2(num);
//
    pot(x);
    printf("main[x] = %p\n",&x);
//
    return;
}
void secondtwo(void)
{
        int n;
    printf("请输入斐波那契数列的位：\n");
    scanf("%d",&n);
//常规斐波那契数列：
    int result;
    if(n == 0)
    result = 0;
    if(n == 1)
    result = 1;
    int pre_pre = 0;
    int pre = 1;
    for(int i = 2;i <= n;i++){
        result = pre_pre + pre;
        pre = result;
        pre_pre = pre;
    }
    printf("%d\n",result);
    printf("%d\n",fib_seq(n));
}
void thirdthree(void)
{
//素数判断
    int num;
    puts("请输入一个数：");
    scanf("%d",&num);
    int is_prime = 1;
    for(int i = 2;i < num;i++)
    {
        if(num % i == 0)
        {
            is_prime = 0;
            printf("%d 不是素数。\n",num);
            break;
        }
    }
    if(is_prime)
    {
        printf("%d 是素数\n",num);
    }
    sushu3(3,200);
    return;
}

int main(void)
{
    sushu3(3,200);
    return 0;
}