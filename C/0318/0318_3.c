#include <stdio.h>
#include <string.h>
#define CW 5    //try2
#define CL 20   //try2
char *classname [3] = {"语文","数学","英语"};
int *find_num(int *arr,int index,int num)
{
    for(int i=0;i<index;i++)
    {
        if(num == arr[i])
        {
            return &arr[i];
        }
    }
    return NULL;
}
void try1(void)
{
    int arr[6] = {6,4,7,8,2,3};
    int *ptr = find_num(arr,6,7);
    if(ptr == NULL)
    {
        printf("没找到！");
        return;
    }
    *ptr = 100;
    for(int i=0;i<6;i++)
    {
        printf("%d ",arr[i]);
    }
}
//____________________________________________________
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
}
void insert_grade(float (*grade)[3],char name[][CL],int index)
{
    for(int i = 0;i < index;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            printf("请输入%s 同学的 %s 成绩：",name[i],classname[j]);
            float gd = 0;
            scanf("%f",&gd);
            grade[i][j] = gd;
        }
    }
    return;
}
void grade_out(char name[][CL],float grade[][3],int index)
{
    for(int i = 0;i < index;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            printf("%s 的[%s]成绩为[%4.2f]\n",name[i],classname[j],grade[i][j]);
        }
    }
}
void try2(void)
{
    char name[CW][CL];
    float grade[CW][3] = {0};
    char *name_ptr[CW];
    for(int i = 0;i < CW;i++)
    {
        name_ptr[i] = name[i];
    }
    int index = insert_name(name_ptr);
    for(int i = 0;i < index;i++)
    {
        printf("%s ",name[i]);
    }
    puts("");
    insert_grade(grade,name,index);
    grade_out(name,grade,index);

}
int main(void)
{
    try2();
    return 0;
}