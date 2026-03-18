#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
double get_num(const char *ptr,bool *should_exit);   //运算数字获取
char get_operator(void);    //运算符号获取
void display_result(double num1,char op,double num2,double result);    //输出运算式
void display_tip(void);    //运行提示
double calculation(double num1,char op,double num2);    //计算
void run(void);    //计算器启动页
int is_continue(void);    //是否继续运行
double get_num(const char *ptr,bool *should_exit)   //运算数字获取
{
    
    while(1)
    {
        printf("%s,输入esc退出。\n",ptr);
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
            *should_exit = false;
            return 0;
        }
        char *endptr;
        num1 = strtod(input,&endptr);    //stdlib.h函数，用于将字符型转换为浮点型，并将第二个指针指向浮点型的后一位地址。
        if(input == endptr || *endptr != '\0')
        {
            puts("请输入纯数字！");
            continue;
        }
        return num1;
    }
}
char get_operator(void)    //运算符号获取
{
    while(1)
    {
        puts("请输入操作符：[+] [-] [*] [/]");

        char operator;
        scanf("%c",&operator);
        while(getchar() != '\n');
        if(operator != '+' && operator != '-' && operator != '*' && operator != '/')
        {
            puts("不支持的操作符，请重试！");
            continue;
        }
        return operator;
    }
}
void display_result(double num1,char op,double num2,double result)    //输出运算式
{
    printf("%.2f = %.2f %c %.2f\n",result,num1,op,num2);
    return;
}
void display_tip(void)    //运行提示
{
    puts("这是一个简易的计算器。");
    return;
}
double calculation(double num1,char op,double num2)    //计算
{
    int result;
    switch(op)
    {
        case '+':
            result = num1 + num2;
            break;
        case '-' :
            result =  num1 - num2;
         break;
        case '*' :
            result =  num1 * num2;
            break;
        case '/' :
            result =  num1 / num2;
            break;
    }
    return result;
}    
void run(void)    //计算器启动页
{
    while(1)
    {
        display_tip();
        bool should_exit = true;
        double num1 = get_num("请输入第一个数字",&should_exit);
        if(!should_exit)
        {
            puts("谢谢使用。");
            return;
        }
        char op = get_operator();
        double num2 = get_num("请输入第二个数字",&should_exit);
        if(!should_exit)
        {
            puts("谢谢使用。");
            return;
        }
        if(num2 == 0 && op == '/')
        {
            puts("除数不能为0；");
            continue;
        }
        int result = calculation(num1,op,num2);
        display_result(num1,op,num2,result);
        int is_con = is_continue();
        if(is_con)
        {
            continue;
        }
        break;
    }
    return;
}
int is_continue(void)    //是否继续运行
{
    while(1)
    {
        puts("是否继续？继续输入y；结束输入n。");
        char input;
        scanf("%c",&input);
        if(input == 'y')
        {
            getchar();
            puts("继续：");
            return 1;
        }
        else if(input == 'n')
        {
            puts("谢谢使用。");
            return 0;
        }
        else
        {
            continue;
        }
    }
}
int main(void)
{
    run();
    return 0;
}