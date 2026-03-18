#include <stdio.h>
#include <stdbool.h>
#define MAX 5
//-----------------------------------------------------
void try1_1(int arr[],int size)
//void try1_1(int *arr,int size)
{  
    for(int i=0;i < size;i++)
    {
        printf("%d ",arr[i]);   //数组思想取元素
        //printf("%d ",*(arr+i))    //指针思想取元素
    }
}
int find_max(int *arr,int size)
{
    int max = *arr;
    for(int i=0;i < size;i++)
    {
        if(max < *(arr + i))
        {
            max = *(arr + i);
        }
    }
    return max;
}
void sorted_arr(int *arr,int size)    //冒泡排序
{
    for(int i = 0;i < size-1;i++)
    {
        for(int j = 0;j <=size-1-i;j++)
        {
            if(arr[j] > arr[j+1])
            {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}
void try1(void)
{
    int arr[5] = {56,23,4,71,44};
    
    int arr2[10] = {56,25,8,6,42,99,31,77,52,30};
    try1_1(arr2,10);
    puts("");
    printf("%d is max.\n",find_max(arr,10));
}
//_____________________________________________________
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
int sushu3(int x,int y,int *arr)    //素数的范围显示。
{
    int nu = 0;
    for(int i = x;i < y;i++)
    {
        if(sushu(i))
        //printf("%d 是素数\n",i);
        {
        *(arr+nu) = i;
        nu++;
        }
    }
    return nu;
}

void try2(void)
{
    int arr[100];
    int size = sushu3(3,100,arr);
    for(int i = 0;i < size;i++)
    {
        printf("%d ",arr[i]);
    }
}
//-----------------------------------------------------
int insert_arr(int *arr,int max)    //数组录入
{
        int index = 0;
    while(1)
    {
        if(index >= max)
        {
            puts("数组已满。");
            return max;
        }
        puts("请输入数字.");
        int num;
        scanf("%d",&num);
        if(num == -1)
        {
            return index;
        }

        arr[index++] = num;
    }
}
void try3(void)
{
    int arr[MAX] = {0};
/*     for(int i = 0;i < MAX;i++)
    {
        int num;
        scanf("%d",&num);
        arr[i] = num;
    } */
    int siz = insert_arr(arr,MAX);
    for(int i = 0;i < siz;i++)
    {
        printf("%d ",arr[i]);
    }
}
//_____________________________________________________
float calculator(float a,float b,char sign,int *wrong)
{
    *wrong = 1;
    switch(sign)
    {
        case '+' :
            return a + b;
            break;
        case '-' :
            return a - b;
            break;
        case '*' :
            return a * b;
            break;
        case '/' :

            return a / b;
            break;
        default :
            puts("计算有误");
            *wrong = 0;
            return 0;
    }
}
void try4(void)
{
    float a;
    float b;
    char sign = {0};
{
    int wrong = 0;
    while(wrong = 0)
    {
        scanf("%f %c %f",&a,&sign,&b);
        if(b == 0 && sign == '/')
        {
        puts("分母不能为0，请重新输入。");
        break;
        }
        printf("%d %c %d = %d;",a,b,sign,calculator(a,b,sign,&wrong));
        break;
    }     
}  
}
//---------------------------------------------------------
void try4_2(void)
{
    bool flag = true;
}

void try5(void)
{
    int *ptr = NULL;    //ptr就是空，没有指向任何空间。好习惯。
    printf("%p ",ptr);
    return;
}
int main(void)
{
    try5();
    return 0;
}