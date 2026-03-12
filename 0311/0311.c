#include <stdio.h>
#include <unistd.h>

void ninenine_table(void);
void sushu(void);
void jinduline(void);
void zhiyinfj(void);

void ninenine_table(void)
{
    for(int i = 1;i<=9;i++)
    {
        for(int j = 1;j<=i;j++)
        {
            printf("%d * %d = %2d  ",i,j,i*j);
        }
        puts("");
    }
}

void sushu(void)
{
    for(int i = 2;i<=100;i++)
    {
        int toke = 0;
        for(int j=2;j<i;j++)
        {
            if(i%j==0)
            {
                toke = 1;
                continue;
            }
        }
        if(toke == 0)
        printf("%3d是素数\n",i);
    }
}

void jinduline(void)
{
    printf("downloading：[----------]0%%");
    for(int i = 10;i<=100;i+=10)
    {
        printf("\rdownloading:[");
        for(int j = 0;j < i/10;j++)
        {
            printf("=");
        }
        for(int j =i/10;j<10;j++)
        {
            printf("-");
        }
        printf("]%d%%",i);
        sleep(1);
    }
}

void zhiyinfj(void)    //质因数分解
{
    int targ = 0;
    int tiken1 = 0;
    while(1)
    {
        puts("请输入一个大于1的整数:");
        putchar;
        scanf("%d",&targ);
        if(targ<=1)
        {
            puts("请您输入一个【大于1】的数字。");
            continue;
        }
        if(1)
        {
            int su_token = 0;
            for(int a = 2;a<targ;a++)
            {
                if(targ%a==0)
                {
                  su_token=1;
                }
            }
            if(su_token==0)
            {
                printf("喂喂你输入一个质数还求什么质因数？\n");
                usleep(500000);
                break;
            }
        }
        printf("%d =",targ);
        int ps = targ;
        int i2 = 2;
        while(1)
        {
            if(ps%i2==0)
            {
                ps/=i2;
                printf("%d*",i2);
                i2=2;
                continue;
            }
            else
            {
                if(i2>=(ps/2))
                {
                    printf("%d",ps);
                    return;
                }
                i2++;
                continue;
            }

        }
    }
    return;
}

void try1(void)    //质因式分解
{
    puts("请输入一个数字：");
    int num;
    scanf("%d",&num);
    printf("%d = ",num);
    for(int i = 1;num % 2 == 0;i++)
    {
        if(num%2==0)
        {
            if(num!=2)
            {
            printf(" 2 * ");
            num/=2;
            }
            else{
                printf("2");
            }
        }
    }
    for(int i = 3;num % i == 0;i+=2)
    {
        while(num % i == 0)
        {
            if(num==i)
            {
                printf(" %d ",i);
                return;
            }
            else
            {
            printf("%d *",i);
            num/=i;
            }
        }
    }
}

void try1_2(void)    //质因式分解2
{
    puts("请输入一个数字：");
    int num;
    scanf("%d",&num);
    printf("%d = ",num);
    int i1 = 1;
    while(num % 2 == 0)
    {
        if(num%2==0)
        {
            if(num!=2)
            {
            printf(" 2 * ");
            num/=2;
            }
            else{
                printf("2");
            }
        }
        i1++;
    }
    i1 = 3;
    while(num % i1 == 0)
    {
        while(num % i1 == 0)
        {
            if(num==i1)
            {
                printf(" %d ",i1);
                return;
            }
            else
            {
            printf("%d *",i1);
            num/=i1;
            }
        }
        i1+=2;
    }
}

void try2(void)    //鸡兔同笼
{
    puts("enter a number :");
    int num;
    int count=0;
    scanf("%d",&num);

    while(num <= 0 || num %2 != 0)
    {
        printf("error enter.");
        return;
    }

    printf("%8s %8s","兔子的个数：","鸡的个数：\n");

    for(int i = 0;num - 4*i >=0;i++)
    {
        if((num-4*i)%2 == 0)
        {
            printf("%-10d,%-4d\n",i,(num-4*i)/2);
            count++;
        }
    }
    putchar;
    printf("有效答案共有 %d 个。",count);

    return;
}

void try3(void)  //因式分解_for
{
    puts("请输入一个数字：");
    int num;
    int zyznum = 0;
    scanf("%d",&num);
    printf("%d的因子有：",num);
    for(int i = 2;i<=num/2;i++)
    {
        if(num%i==0)
        {
            printf("%d ",i);
            zyznum++;
        }
    }
    printf("\n数字[%d]的因数有：%d 个。",zyznum);
    return;
}

void try3_2(void)    //因式分解_while
{
    puts("请输入一个数字：");
    int num;
    int zyznum = 0;
    scanf("%d",&num);
    printf("%d的因子有：",num);
    int i = 2;
    while(i<=num/2)
    {
        if(num%i==0)
        {
            printf("%d ",i);
            zyznum++;
        }
        i++;
    }
    printf("\n数字[%d]的因数有：%d 个。",zyznum);
    return;
}

void try4(void)    //棱形打印
{
    puts("请输入要打印的菱形的高度：");
    int high;
    scanf("%d",&high);
    int i = 1;
    int lelong = high;
    for( ;lelong>0;lelong--)
    {
        
        for(int j = lelong-1;j>0;j--)
        {
            printf(" ");
        }
        for(int j = 1;j<=(2*i)-1;j++)
        {
            printf("*");
        }
        printf("\n");
        i++;
    }

    for(int j = high-1;j>0;j--)
    {
        for(int k = high-j;k>0;k--)
        {
            printf(" ");
        }
        for(int k = 2*j-1;k>0;k--)
        {
            printf("*");
        }
        printf("\n");
    }
    return;
}

void try4_2(void)    //三角打印
{
    puts("请输入要打印的三角形形的高度：");
    int high;
    scanf("%d",&high);
    int i = 1;
    int lelong = high;
    for( ;lelong>0;lelong--)
    {
        
        for(int j = lelong-1;j>0;j--)
        {
            printf(" ");
        }
        for(int j = 1;j<=(2*i)-1;j++)
        {
            printf("*");
        }
        printf("\n");
        i++;
    }

}

void try5(void)    //完数判断
{
    puts("请在问号中输入您想要知道的完数范围：\n[0--->?]");
    int cor;
    scanf("%d",&cor);
    int num=0;
    printf("[0->%d]中的完数有：",cor);
    for(int i = 1;i<=cor;i++)
    {
        int sub= 0;
        for(int j = 1;j<=i/2;j++)
        {
            if(i%j==0)
            sub+=j;
        }
        if(sub==i)
        {
            printf("%d ",i);
        }
    }
    return;
}

int main(void)
{
    //ninenine_table();
    //sushu();
    //jinduline();
    //zhiyinfj();
    //try3();
    //try2();

    //try4();
    //try4_2();
    try5();

    return 0;
}