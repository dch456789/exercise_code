#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#define over -888
#define MAX 5
#define COWS 2
#define COLS 3

void try1(void);    //传统排序（正序）
void try1_1(void);    //传统排序（倒序）
void try2(void);    //教学代码
void try3(void);    //二维数组

void try1(void)
{
    int arr[6] = {4,67,34,6,12,1};
    int copy_arr[6];

//copy数组
for(int i = 0;i<6;i++)
{
    copy_arr[i] = arr[i];
}
//输出数组
for(int i = 0;i < 6;i++)
{
    printf("%d ",copy_arr[i]);
}
//排序（传统排序）
for (int i = 0;i < 5;i++)
    {
    int min_index = 1;
    for(int j = 0;j < 6;j++)
        {
        if(arr[min_index] > arr[j])
            {
                min_index = j;
            }
        }
        if(min_index != i)
        {
            int tmp;
            tmp = copy_arr[i];
            copy_arr[i] = copy_arr[min_index];
            copy_arr[min_index] = tmp;
        }
    }
/* for(int i = 0;i < 5;i++)
{
    for(int j = 0;j < 6;j++)
    {
        if(copy_arr[i] > copy_arr[])
    }
} */

//冒泡排序
for(int i = 0;i < 5;i++)
{
    int is_swap = 0;
    for(int j = 0;j < 5-i;j++)
    {
        if(copy_arr[j] > copy_arr[j+1])
        {
            int temp;
            temp = copy_arr[j];
            copy_arr[j] = copy_arr[j+1];
            copy_arr[j+1] = temp;
            is_swap = 1;
        }
    }
    if(!is_swap)
    {
        break;
    }
}

//输出数组。
printf("\n\n");
for(int i = 0;i < 6;i++)
{
    printf("%d ",copy_arr[i]);
}
return;   
}

void try1_1(void)
{
    int arf[6] = {34,623,45,6756,3,5};
    for(int i = 0;i < 6;i++)
    printf("%d ",arf[i]);
    for(int i = 0;i < 6;i++)
    {
        int tag1_1 = 0;
        for(int j = 0;j < 5-i;j++)
        {
            if(arf[j]<arf[j+1])
            {
                int lscch;
                lscch = arf[j+1];
                arf[j+1] = arf[j];
                arf[j] = lscch;
                tag1_1 = 1;
            }
        }
        if(!tag1_1)
        {
            break;
        }
    }
    puts("");
    for(int i = 0;i < 6;i++)
    printf("%d ",arf[i]);
    return;
}

void try2(void)
{
    char name[50] ={'h','e','l','l','o'};
    printf("%zu\n",sizeof name);    //数组的大小输出
    printf("%s\n",name);
    name[0] = 'H';
    printf("%s\n",name);
    char name1[] = "hello";    //自动初始化，会在字符数组的最后面增加\0表示字符串的结束
    printf("%zu\n",sizeof name1);
    printf("%s\n",name1);
    printf("%d\n",strlen(name1));    //专用长度判断语句strlen（）
    name1[0] = 'H';
    printf("%s\n",name1);
    printf("%p\n",&name1);
    printf("%p\n","hello");    //字符串本身也是一种常量。

    char name2[6];
    for(int i = 0;i < 5;i++)
    {
        name2[i] = name[i];
    }
    name2[5] = '\0';
    printf("%s",name2);

    strcpy(name2,name1);    //字符串拷贝函数
    return;
}

void try3(void)
{
    {
    int arr[2][3] = {{1,2,3},5,6,7};
    //int arr[COWS][COLS] = {{1,2,3},{5,6,7}};
    for(int i = 0;i < COWS;i++)
    {
        for(int j = 0;j < COLS;j++)
        {
            printf("%d ",arr[i][j]);
        }
        puts("");
    }
    //return;
    }
    //_________________________________________
    {
    int arr[COWS][COLS] = {{1,2,3},{5,6,7}};
    for(int i = 0;i < COWS * COLS;i++)
    {
        {
            printf("%d ",arr[0][i]);
        }
        if((i+1) % 3 == 0)
        puts("");
    }
    }

    //______________________________________
    {
        int arr[COWS][COLS] = {{1,2,3},{5,6,7}};
        for(int i = -3;i < 3;i++)
        {
            printf("%d ",arr[1][i]);
            if((abs(i + 1)) % 3 == 0)
            printf("\n");
        }
        puts("");
    }

    return;
}

void try1_2(void)  //二维数组的排序（倒序）
{
    int maxs = 0;
    int mins = 0;
    int subs = 0;
    int arf[2][3] = {34,623,45,6756,3,5};
    for(int i = 0;i < 6;i++)
    printf("%d ",arf[0][i]);
    maxs = arf[0][0];
    mins = maxs;
    for(int i = 0;i < 6;i++)
    {
        int tag1_1 = 0;
        for(int j = 0;j < 5-i;j++)
        {
            if(maxs<arf[0][j+1])
            {
                maxs = arf[0][j+1];
            }
            if(mins > arf[0][j+1])
            {
                mins = arf[0][j+1];
            }
            if(arf[0][j]<arf[0][j+1])
            {
                int lscch;
                lscch = arf[0][j+1];
                arf[0][j+1] = arf[0][j];
                arf[0][j] = lscch;
                tag1_1 = 1;
            }
        }
        if(!tag1_1)
        {
            break;
        }
    }
    for(int i = 0;i < 6;i++)
    subs  += arf[0][i];
    puts("");
    for(int i = 0;i < 6;i++)
    printf("%d ",arf[0][i]);
    puts("");
    printf("max = %d    min = %d    sub = %d\n",maxs,mins,subs);
    return;
}

int main(void)
{
    try1_2();

    return 0;
}