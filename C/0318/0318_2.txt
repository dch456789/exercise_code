#include <stdio.h>
#include <string.h>
#define COWS 2
#define COLS 3
#define X 4     //try2
#define Y 5     //try2
#define CW 5    //try3
#define CL 20   //try3
void display_arr(int *arr,int cows,int cols);
int insert_arr(int (*arr)[3],int cows);
void display_arr1(int (*arr)[3],int cows,int index);
void top_arr(int (*arr)[Y],char op,int num) ;
int arr_insert(int (*arr)[Y],int longx,int longy);

void display_arr(int *arr,int cows,int cols)
{
    for(int i = 0;i < cows;i++)
    {
        for(int j = 0;j < cols;j++)
        {
            printf("%5d ",*(arr + i*cols + j));
        }
        puts("");
    }
}
int insert_arr(int (*arr)[3],int cows)
{
    int index = 0;
    while(1)
    {
        if((index + 1)>= 3*cows)
        {
            printf("数组已满。\n");
            break;
        }
        for(int i = 0;i < cows;i++)
        {
            for(int j = 0;j < 3;j++)
            {
                int num;
                scanf("%d",&num);
                if(num == -1)
                {
                    return index - 1;
                }
                arr[i][j] = num;
                index++;
            }
        }
    }
    return 3*cows;
}
void display_arr1(int (*arr)[3],int cows,int index)
{
    for(int i = 0;i < cows;i++)
        {
            for(int j = 0;j < 3;j++)
            {
                if(index > (i*cows + j))
                {
                    printf("%4d",arr[i][j]);
                }
                else
                printf("%4s","-");
            }
            puts("");
        }
        return;    
}
void try1(void)
{
    int arr[2][3] = {1,2,3,6,7,8};
    int arr1[2][3] = {0};
    int index = insert_arr(arr1,2);
    display_arr1(arr1,2,index);
    return;
}
//_____________________________________________________
void top_arr(int (*arr)[Y],char op,int num)    //最值判断函数，arr为数组地址；op为操作符，t为最大f为最小；num为有效数位长度
{
    if(op == 't')
    {
        int a = **arr;
        for(int i = 0;i < num;i++)
        {
            if(*(*arr + i) >= a)
            {
                a = *(*arr + i);
            }
        }
        printf("该字符串的最大值为：%d\n",a);
    }
    else if(op == 'f')
    {
        int a = **arr;
        for(int i = 0;i < num;i++)
        {
            if(*(*arr + i) <= a)
            {
                a = *(*arr + i);
            }
        }
        printf("该字符串的最小值为：%d\n",a);
    }
}
int arr_insert(int (*arr)[Y],int longx,int longy)    //int数组输入，arr为数组地址，longx为数组行数，longy为数组列数
{
    int numb = 0;
    puts("请输入数字：输入-1时退出");
    for(int i = 0;i < longx;i++)
    {
        for(int j = 0;j < longy;j++)
        {
            printf("请输入：");
            int arf;
            scanf("%d",&arf);
            if(arf == -1)
            {
                puts("输入结束");
                return numb;
            }
            arr[i][j] = arf;
            numb++;
        }
    }
    puts("输入结束");
    return numb;
}
void try2(void)
{
    int arr[X][Y] = {0};
    int num = arr_insert(arr,X,Y);
    top_arr(arr,'t',num);
    top_arr(arr,'f',num);
    return;
}
//________________________________________________________
int insert_name(char *name[CW])     //学生姓名录入
{
    int index = 0;
    while(1)
    {
        char input[20];
        printf("请输入学生姓名,输入esc退出:");
        scanf("%s",input);
        if(strcmp(input,"esc") == 0)
        {
            return index;
        }
        
        strcpy(name[index++],input);
        if(index >= CW)
        {
            puts("数组已满。");
            break;
        }
        
    }
    return CW;
/*     while(1)
    {
        char input[CL];
        if((index + 1) > CW * CL)
        {
            puts("数组已满。");
        }
    } */
}
void try3(void)
{
    char name[CW][CL];
    char *name_ptr[CW];
    for(int i = 0;i < CW;i++)
    {
        name_ptr[i] = name[i];
    }
    int index = insert_name(name_ptr);
    for(int i = 0;i < index;i++)
    printf("%d个学生姓名：%s\n",i+1,name[i]);
    return;
}
//————————————————————————————————————————————————————————

int main(void)
{
    try3();
    return 0;
}