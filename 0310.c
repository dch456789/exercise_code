#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>
#define NAME 40
void one(void);
void two(void);
void sb(void);
void threecode(void);
void gradelv(void);
void gsqh(void);
void guess(void);

void one(void)
{
    printf("hellow\n");
    printf("%d\n",2&&2);
    int a = printf("now has been out\n");
    printf("%d\n",a);
    printf("%zu\n",sizeof "语文");
    printf("%d\n",0b101&2);
    char ta = 0b11010001;
    int tb = 0b11010001;
    printf("%i\n%d\n%d\n",0b11010001,tb,ta);
    int b = 1;
/*    while(1)
    {
        
        printf("%d",b = b ^ 1);
        sleep(2);
    }
*/
    printf("%d\n",&b);
    int *c = &b;
    printf("%d\n",*c);
}

void two(void)
{
    char name[NAME];
    float Chinese_grade;
    float Math_grade;
    float English_grade;
    float Sub_grade;
    float Avg_grade;

    puts("please enter your 'name',Chinese_grade','Math_grade','English_grade' with ' '.");
    scanf("%s",name);
    putchar;
    scanf("%f %f %f",&Chinese_grade,&Math_grade,&English_grade);

    printf("%s %f %f %f\n",name,Chinese_grade,Math_grade,English_grade);

    Sub_grade += Chinese_grade + Math_grade + English_grade;
    Avg_grade = Sub_grade / 3.0;

    printf("Mr.%s ,The chinese is :%-.2f;\n",name,Chinese_grade);
    for(int i = 0;i <= 1;i++)
    {
        for(int j = 0;j<strlen(name)+5;j++)
        
                printf(" ");
        if(i==0)
        {
            
            printf("The math is :%-.2f;\n",Math_grade);
        }
        else if(i==1)
        {

            printf("The english is :%-.2f;\n",English_grade);
        }
    }
    printf("The sub grade is:%.2f;\n",Sub_grade);
    printf("the avg grade is:%.2f;\n",Avg_grade);
}

void sb()
{
    puts("1：if实现  2：switch实现————");
    int sw;
    scanf("%d",&sw);
    puts("这是一段整数四则运算代码。请输入两个整数，并以空格作为分隔：");
    int a;
    int b;
    scanf("%d %d",&a,&b);
    putchar;
    printf("a=%-4d,b=%-4d;\n",a,b);
    puts("请选择您想要进行的运算：\n1：相加；2：相减；3：相乘；4：相除；");
    int c;
    scanf("%d",&c);
    if(sw == 1)
    {
        if(c==1)
        {
            printf("%d + %d = %d",a,b,a+b);
            return;
        }
        else if(c==2)
        {
            printf("%d - %d = %d;",a,b,a-b);
            return;
        }
        else if(c==3)
        {
            printf("%d * %d = %d;",a,b,a*b);
            return;
        }
        else if(c==4)
        {
            if(b==0)
            {
                puts("错误，分母不能为0；");
                return;
            }
            if((a%b) != 0)
            {
                printf("%d / %d = %.2f",a,b,(float)a/(float)b);
                return;
            }
            printf("%d / %d = %d;",a,b,(a/b));
            return;
        }
        else
        {
            puts("错误，您输入的操作并未包含。");
            return;
        }
    }
    else if(sw == 2)
    {
        switch(c)
        {
            case 1:
                printf("%d + %d = %d",a,b,a+b);
                return;
            case 2:
                printf("%d - %d = %d;",a,b,a-b);
                return;
            case 3:
                printf("%d * %d = %d;",a,b,a*b);
                return;
            case 4:
                if(b==0)
                {
                    puts("错误，分母不能为0；");
                    return;
                }
                if((a%b) != 0)
                {
                    printf("%d / %d = %.2f",a,b,(float)a/(float)b);
                    return;
                }
                printf("%d / %d = %d;",a,b,(a/b));
                return;

        }
    }
}

void threecode(void)
{
    int sw;
    puts("请输入：1、用do-while实现    2、用while实现。");
    scanf("%d",&sw);
    if(sw==2)
    {
        while(1)
        {
            puts("菜单列表：\n 1:查看系统信息;\n 2:修改系统信息;\n 3:退出系统;\n请选择:");
            int i=10;
            scanf("%d",&i);
            switch(i)
            {
                case 1:
                    printf("查看系统信息\n\n");
                    sleep(1);
                    continue;
                case 2:
                    printf("修改系统信息\n\n");
                    sleep(1);
                    continue;
                case 3:
                    printf("退出系统\n");
                    i=4;
                    break;
                default :
                    printf("选择错误！\n");
                    i = 10;
                    sleep(1);
                    continue;
            }
            while(i==4)
                return;
        }
    }
    else if(sw == 1)
    {
        do{
            puts("菜单列表：1、查看系统信息 2、修改系统信息 3、退出系统 \n  请选择：");
            int cho;
            scanf("%d",&cho);
            do{
                if(cho==1)
                {
                    puts("查看系统信息");
                    break;
                }
                else if(cho==2)
                {
                    puts("修改系统信息");
                    break;
                }
                else if(cho==3)
                {
                    puts("退出系统");
                    sleep(1);
                    return;
                }
                else 
                {
                    puts("您的输入不在功能范围内！");
                    break;
                }
            }while(1);
            sleep(1);
        }while(1);
    }
}

void gradelv(void)
{
    puts("请输入成绩和要采用的方式，1为if，2为switch：用空格分隔");
    int grade;
    int sw;
    scanf("%d %d",&grade,&sw);
    if(sw==1)
    {
        if(grade>100||grade<0)
        {
            puts("错误的输入\n");
            return;
        }
        if(grade >=90)
        {
            printf("优秀！\n");
            return;
        }
            
        if(grade >=80)
        {
            printf("良好！\n");
            return;
        }
        if(grade >=60)
        {
            printf("及格！\n");
            return;
        }
        if(grade >=0)
        {
            printf("不及格！\n");
            return;
        }
    }
    else if(sw==2)
    {
        switch((int)(grade<=100 && grade >=0))
        {
            case 0:
                puts("错误的输入！");
                return;
            case 1:
            switch(grade / 10)
            {
                case 10:
                case 9:
                    puts("优秀！");
                    break;
                case 8:
                    puts("良好！");
                    break;
                case 7:
                case 6:
                    puts("及格！");
                    break;
                default:
                    puts("不及格！");
                    break;
            }
            default:
                return;
                
            
        }
    }

}

void gsqh(void)
{
    int i = 1;
    int j = 0;
    do
    {
        j = j + i;
        i++;
    }while(i<=100);
    printf("%d",j);
}

void guess(void)
{
    int target = 61;
    int guessnum;

    while(1)
    {    
        puts("请输入数字：");
        scanf("%d",&guessnum);
        switch(guessnum>target){
        case 1 :
            puts("大了");
            break;
        default :
            switch(guessnum<target){
            case 1:
                puts("小了");
                break;
            default:
                printf("%d 就是这个数\n",guessnum);
                return;
            }
        }

    }
}

int main(void)
{
    //one();
    //two();
    //sb();
    threecode();
    //gradelv();
    //gsqh();
    //guess();
    return 0;
}