#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define PEOPNUM 4
#define NAMEL 40

void try1(void);

void try1(void)
{
    int arr[5] = {1,2,3,4,5};
    printf("%p\n",arr);
    int *ptr = arr;

    printf("%p\n",&arr[0]);
    printf("%p\n",ptr);
    printf("%p\n",ptr+1);
    printf("%d\n",*(ptr+1));

    //下标遍历
    for(int i = 0;i < 5;i++)
    {
        printf("%d ",arr[i]);
    }
    puts("");
    //指针遍历
    for(int i = 0;i < 5;i++)
    {
        printf("%d ",*(ptr + i));
    }
    puts("");
    for(int i = 0;i < 5;i++,ptr++)
    {
        printf("%d ",*ptr);
    }
    puts("");
    ptr = arr;    //回置
    for(int i = 0;i < 5;i++)
    {
        printf("%d ",*ptr++);    //先追加，再解引用。
    }
    puts("");
    ptr = arr;    //回置
    for(int i = 0;i < 5;i++)
    {
        printf("%d ",ptr[i]);
    }
    puts("");
    for(int i = 0;i < 5;i++)    //一维数组名会退化，退化为一个指针地址
    {
    //    printf("%d ",*arr++);    //不可以，因为数组名是常量，不能改变。
        printf("%d ",*(arr + i));
    }
    puts("");
    printf("%d \n",*(arr + 1));    //指针地址+1跳过多少位完全由指针声明类型决定。
    return;
}

void try2(void)
{
    char char_a[] = {"hello!"};
    printf("%s \n",char_a);
    char char_b[] = {'a','b','c','d'};
    //__________________________________________
    char *ptr = char_a;
    for(int i = 0;i < strlen(char_a);i++)
    {
        printf("%c ",*(ptr+i));
    }
    puts("");
    //____________________________________________
    ptr = char_a;
    int i = 0;
    while(char_a[i] != '\0')
    {
        printf("%c ",char_a[i++]);
    }
    puts("");
    char *ptr_char = "world";    //字符串字面量初始化 \0
    printf("%s\n",ptr_char);
    puts("");
    for(i = 0;i < strlen(ptr_char);i++)
    {
        printf("%c ",ptr_char[i]);
    }
    puts("");
}

void try3(void)
{
    char char_a[] = "hello";    //将字符串每个字符赋值到char_a的数组当中
    char *char_b = "hello";    //char_b指向的是一个字符串
    char_a[0] = 'H';
    printf("%s\n",char_a);
    //char_b[0] = 'H';    //不能修改常量
    printf("%s\n",char_b);
    printf("%c\n",*char_b);    //退化了，char_b指向的是字符串的首字符。
    printf("%p\n",char_b);
    printf("%p\n","hello");    //字符串也是个地址，指向第一个字符的地址。
    printf("%c\n","hello"[0]);    //可以当数组使用。
    printf("%d\n","hello"[5]);    //\0
}

void try4(void)
{
    int arr[2][3] = {1,2,3,4,5,6};    //数组名也会退化，int *[3]
    for(int i = 0;i < 2;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            printf("%d ",arr[i][j]);
        }
        puts("");
    }
    int (*ptr)[3] = arr;
    printf("%p \n",arr);
    printf("%p \n",ptr);
    printf("%p \n",arr + 1);    //二维数组名退化后变成一维数组，但是地址+1会变12位（3*4），会指向首行。
    printf("%p \n",ptr + 1);
    //看第二行：
    for(int i = 0;i < 3;i++)
    {
        printf("%d ",arr[1][i]);
    }
    //指针方式看第二行
    //printf("\n%d",*(arr+1));
    puts("");
    for(int i = 0;i < 2;i++)
    {
        printf("%d   :    ",**(ptr ));
        for(int j = 0;j < 3;j++)
        {
            printf("%p :%-5d",(*(ptr + i)+j),*(*(ptr + i)+j));  //输出数组arr每个元素的地址  和   arr的元素
        }
        puts("");
    }

    int (*ptr2)[3] = arr;
    puts("");
    for(int i = 0;i < 6;i++)
    {
        printf("%p  :  %-5d  \n",ptr2 + i,**(ptr2)+i);
    }
}

void try5(void)
{
    int arr[2][4] = {1,2,3,4,5,6,7,8};
    int (*ptr)[4] = arr;
    printf("%p\n",ptr);
    printf("%p\n",ptr+1);
    for(int i=0;i<4;i++)
    {
        printf("%d ",(*(ptr+1))[i]);    // []优先级高于*
    }
    puts("");
    for(int i = 0;i < 4;i++)
    {
        printf("%d ",*(*(ptr+1)+i));
    }
    puts("");
    int *ptr_a = (int*)arr;
    printf("%p\n",ptr_a);
    printf("%p\n",ptr_a+1);
    for(int i=0;i<8;i++)
    {
        printf("%d ",*ptr_a++);
    }
    puts("");
    for(int i=0;i<8;i++)
    {
        printf("%d ",*(&arr[0][0]+i));
    }
    //总结，在二维数组中，哪些代表行指针：
    //1、arr 第0行的行指针。
    //2、&arr[0],&arr[i] 第i行的行指针
    //3、&(*(arr+i));arr+i第i行的行指针
    printf("%p \n",arr+1);
    printf("\n");
    for(int i=0;i<4;i++)
    {
        printf("%d ",(*arr)[i]);
    }
    //总结：在二维数组中，哪些是代表行的第一个元素的指针：
    //1、&arr[0][0],&arr[i][0]
    printf("\n");
    printf("%p ",&arr[0][0]);   //arr[i][j]
    //2、arr[0],arr[i];         //*(arr[i])
    printf("%p ",arr[0]+1);
    //3、*arr,*(arr+i);         //*(*(arr+i)+j)
    printf("%p ",*(arr+1));
    printf("%p ",*arr+1);
    printf("%d ",**(arr+1));
    printf("%d ",**arr);
    printf("%p ",*(arr[1]+1));
}

void try6(void)    //指针and数组
{
    int arr_a[] = {1,2};
    int arr_b[] = {3,4};
    int arr_c[] = {5,6};
    int *ptr[3] = {arr_a,arr_b,arr_c};    //数组指针
    char sub[3][10] = {"语文","数学","英语"};
    printf("%s \n",sub[0]);
    char *ptr_c[3] = {"语文","数学","英语"};    //指针数组
    printf("%s\n",*(ptr_c+1));
    printf("%s\n",ptr_c[0]);
    for(int i=0;i<3;i++)
    {
        printf("%s ",*(ptr_c+i));
    }
    puts("");
    //
    printf("%p %p",**ptr,*arr_a);
    puts("");
    for(int i = 0;i < 3;i++)
    {
        for(int j=0;j<2;j++)
        {
            printf("%d ",ptr[i][j]);
        }
    }
    puts("");
    //__________________________________
    int x = 100;
    int *ptr_x = &x;
    int **ptr_p = &ptr_x;    //二级指针
    printf("%p  %p\n",*ptr_p,&x);
    printf("%d\n",**ptr_p);
    **ptr_p = 300;
    printf("%d \n",x);
    *ptr_x = 500;
    printf("%d \n",x);
}

void try7(void)    //进度条
{
    //正在下载中[=         ]10%
    printf("正在下载中[          ]0%%");
    for(int i=10;i<=100;i+=10)
    {
        printf("\r正在下载中[");
        for(int j=0;j<i/10;j++)
        {
            printf("=");
        }
        for(int j=10;j>i/10;j--)
        {
            printf(" ");
        }
        printf("]%d%%",i);
        sleep(1);
    }
    //________________________________
    puts("");

    //字符串形式
    //printf("正在下载中[          ]0%%");
    char bar[11];
    for(int i = 10;i <= 100;i+=10)
    {
        int length = i/10;
        for(int j = 0;j < 10;j++)
        bar[j] = ' ';
        
        for(int j = 0;j < length;j++)
        {
            bar[j] = '=';
        }
        bar[11] = '\0';
        printf("\r正在下载中[%s]%d%%",bar,i);
        sleep(1);
    }
    puts("");
    //————————————————————————————————————————————————
    //指针方式
    for(int i = 10;i <= 100;i+=10)
    {
        printf("\r正在下载中[%-10s]%d%%","=========="+10-i/10,i);
        sleep(1);
    }
}

void try6_2(void)    //多种二维数组遍历
{
    int sam[2][8] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    int (*pst)[8] = sam;
    printf("&sam[0][0] = %p  pst = %p\n",sam+1,pst+1);
    //数组
    for(int i = 0;i < 2;i++)
    {
        for(int j = 0;j < 8;j++)
        printf("%3d ",sam[i][j]);
        puts("");
    }

    //指针
    //1:
    puts("1:");
    for(int i = 0;i < 16;i++)
    printf("%-3d",**pst+i);
    puts("");
    //2:
    puts("2:");
    for(int i = 0;i < 2;i++)
    {
        for(int j = 0;j < 8;j++)
        printf("%-3d",pst[i][j]);
        puts("");
    }
    //3:
    puts("3:");
    for(int i = 0;i < 2;i++)
    {
        for(int j = 0;j < 8;j++)
        printf("%-3d",*(*(pst+i)+j));
        puts("");
    }
    //4:
    puts("4:");
    for(int i = 0;i < 2;i++)
    {
        for(int j = 0;j < 8;j++)
        printf("%-3d",*(pst[i]+j));
        puts("");
    }
    //5:
    puts("5:");
    for(int i = 0;i < 2;i++)
    {
        for(int j = 0;j < 8;j++)
        printf("%-3d",*(*(sam+i)+j));
        puts("");
    }

}

void try0(void)    //重写学生成绩录入系统
{
    char *classname [3] = {"语文","数学","英语"};    //课程名
    char name [PEOPNUM][NAMEL] = {0};    //学生姓名表
    char *stuname [PEOPNUM];    //学生姓名表的指针数组
    float grade [PEOPNUM][3] = {0};    //学生成绩表
    int peop = 0;    //学生人数
    //输入
    while(1)    //学生姓名录入
    {
        if(peop > PEOPNUM)
        {
            puts("没有空间可以录入了。");
            break;
        }

        puts("请输入您想要录入的学生姓名：输入esc退出。");
        char lemp[100];
        fgets(lemp,sizeof(lemp),stdin);
        lemp[strcspn(lemp,"\n")] = 0;
        int len = strlen(lemp);

        if(!len)
        {
            puts("输入有误，请重新输入：");
            continue;
        }

        if(!strcmp(lemp,"esc"))
        {
            break;
        }
        

        strcpy(name[peop],lemp);
        peop++;
    }
    //_________________________________________________________________
    //打印学生总表
    printf("%d 人。\n",peop);    //总人数
    for(int i = 0;i < PEOPNUM;i++)    //学生名字输出1：
    {
        printf("%-20s",*(name+i));
    }
    puts("");
    for(int i = 0;i <PEOPNUM;i++)    //指针数组赋值：
    stuname[i] = name[i];

    for(int i = 0;i < PEOPNUM;i++)    //学生名字输出2:
    printf("%-20s",*(stuname+i));
    puts("");
    //________________________________________________________________
    //学生成绩录入：
    for(int i =0;i < peop;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            printf("请输入 %s 同学的 %s 这门课程的成绩：\n",*(stuname+i),*(classname+j));
            float gd = 0;
            scanf("%f",&gd);
            grade[i][j] = gd;
        }
    }
    //___________________________________________________________________
    //学生成绩打印：
    for(int i = 0;i < peop*3;i++)
    printf("%s 同学的[ %s ]成绩为：%-5.2f。\n",*(stuname+i/3),*(classname + i%3),*(*grade+i));
    return;
    
}
int main(void)
{
    try0();
    return 0;
}
