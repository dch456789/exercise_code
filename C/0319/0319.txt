#include <stdio.h>
#include <stdlib.h>
#define CP1 char *
#define MAX 5
typedef char * CP;
typedef int AR[10];    //定义i新的数据类型AR,代表int[10]；
typedef int (*sorted_function)(int a,int b);
//typedef void (*says)(void);

void try0(void)
{
    CP1 a1,b1;    //define仅仅是文本替换
    CP1 c1;
    int a,b,c;
    CP cp1,cp2;   //typedef是声明了一个新的数据类型。
    printf("%zu\n",sizeof(cp1));
    printf("%zu\n",sizeof(cp2));
    AR ar1;
    printf("%zu\n",sizeof(ar1));
    printf("%zu\n",sizeof(a1));
    printf("%zu\n",sizeof(b1));
    printf("%zu\n",sizeof(c1));
}
//______________________________________________
int sorted_up(int a,int b)
{
    return a-b;
}
int sorted_down(int a,int b)
{
    return b-a;
}

//void display_arr(int *arr,int size,says call)           //使用typedef的声明
void display_arr(int *arr,int size,void (*call)(void))    //另一个方式的声明，不使用typedef    
{
    for(int i = 0;i < size;i++)
    {
        printf("%d ",arr[i]);
    }
    call();
}
void sorted_arr(int *arr,int size,sorted_function sorted_f)    //回调函数。
{
    for(int i = 0;i < size-1;i++)
    {
        for(int j = 0;j < size-1-i;j++)
        {
            if(sorted_f(arr[j],arr[j+1]) > 0)
            {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}
void sayhellow(void)
{
    puts("请输入文本。");
    return;
}
void try1(void)
{
    //int (*function)(int x,int y);    //函数声明，以标识符为基础，先右后左，代表函数,形参：两个int类型
    int arr[6] = {34,45,87,112,44,37};
    display_arr(arr,6,sayhellow);
    sorted_arr(arr,6,sorted_up);
}
//——————————————————————————————————————————————————————————————————————————————
int *insert_arr()    //数组录入
{
    int index = 0;
    int arr[MAX] = {0};

        
        int num;
        puts("请输入数字.");
        for(int i = 0;i < index -1;i++)
        {
            scanf("%d",&num);
            arr[index++] = num;
        }
        for(int i = 0;i < index;i++)
        {
            printf("%d ",arr[i]);
        }
    return arr;
}
void try2(void)    //悬空指针案例
{
    int *ptr = NULL;
    ptr = insert_arr();
    for(int i = 0;i < MAX;i++)
    {
        printf("%d ",ptr[i]);
    }
    
}
//________________________________________________
int *insert_arr2()
{
    int *arr = malloc(sizeof(int)*MAX);     //在内存中开辟一块空间，4*5=（20），arr指向它。
    int num;
    puts("请输入数字：");
    for(int i = 0;i < MAX;i++)
    {
        scanf("%d",&num);
        arr[i] = num;
    }
    for(int i = 0;i < MAX;i++)
    {
        printf("%d ",arr[i]);
    }
    return arr;
}
void try3(void)
{
    int *ptr = NULL;
    ptr = insert_arr2();
    puts("");
    for(int i = 0;i < MAX;i++)
    {
        printf("%d ",ptr[i]);
    }
    free(ptr);      //释放内存。
    ptr = NULL;    //防止指针悬空
    return;
}
int main(void)
{
    try3();
    return 0;
}