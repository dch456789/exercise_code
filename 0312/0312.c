#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define MAX 5
//函数声明区域
void try1(void);    //成绩录入系统
void try2(void);    //加减乘除计算器ver.2
void try3(void);    //数组的初始化以及增删改查
//函数体区域
void try1(void)
{
    char name[50];
    float chinese_grade;
    float math_grade;
    float english_grade;
    float sumgrade;
    float avggrade;

    puts("学生成绩录入系统");
    puts("请输入学生姓名：");
    scanf("%s",name);
    int is_value = 1;
    
    do{
        
            puts("请按照语文、数学、英语的输入顺序输入学生成绩：");
            int count = scanf("%f %f %f",&chinese_grade,&math_grade,&english_grade);
            if(count!=3)
            {
                printf("输入有误，请重新输入：\n");
                while(getchar()!='\n')
                {
                    continue;
                }
            }
            if(chinese_grade<0||chinese_grade>100||math_grade<0||math_grade>100||english_grade<0||english_grade>100)
            {
                printf("成绩范围有误，请重新输入：\n");
                while(getchar()!='\n');
                {
                    continue;
                }
            }
            sumgrade = chinese_grade + math_grade + english_grade;
            avggrade = sumgrade/3;
            printf("%-10s%-10s%-10s%-10s%-10s%-10s\n","姓名","语文","数学","英语","总成绩","平均分");
            printf("%-10s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f",name,chinese_grade,math_grade,english_grade,sumgrade,avggrade);
            is_value = 0;
        
    }while(is_value==1);
    return;
}

void try2(void)
{
    puts("支持加减乘除的计算器");
    int is_value = 1;
    while(is_value)
    {
        puts("请输入第一个数字：");
        float num1;
        while(!scanf("%f",&num1))
        {
            puts("输入有误，请重新输入：\n");
            while(getchar()!='\n');
        }
        while(getchar() != '\n');       
        puts("输入运算符：+ - * /");
        char oprator;
        while(scanf("%c",&oprator))
        {
            if(oprator != '+' && oprator != '-' && oprator != '*' && oprator != '/')
            {
                puts("不支持的运算符,请重新输入：");
                while(getchar()!= '\n');
                continue;
            }
            break;
        }
        while(getchar()!='\n');
        puts("请输入第二个数字：");
        float num2;
        NM:
        while(!scanf("%f",&num2))
        {
            puts("输入有误，请重新输入：\n");
            while(getchar()!='\n');
        }
        if(oprator == '/' && num2 == 0)
        {
            puts("除数不能为零，请重新输入：");
            while(getchar()!='\n');
            goto NM;
        }
        switch(oprator)
        {
            case '+':
                printf("%f + %f = %f",num1,num2,num1+num2);
                break;
            case '-':
                printf("%f - %f = %f",num1,num2,num1-num2);
                break;
            case '*':
                printf("%f * %f = %f",num1,num2,num1*num2);
                break;
            case '/':
                printf("%f / %f = %f",num1,num2,num1/num2);
                break;
        }
        printf("\n");
        puts("是否继续？（‘y’或‘Y’");
        while(getchar()!='\n');
        char contchoice;
        scanf("%c",&contchoice);
        if(contchoice != 'y' && contchoice != 'Y')
        {
            is_value = 0;
        }

    }
}

void try3(void)
{
   /*  int arr[5] = {1,2,3,4,5};
    int arr1[5];    //元素的数值不确定
    printf("%zu\n",sizeof arr);
    char name[50]; */
    //__________________________
    //数组输入部分
    int arr[MAX];
    int index = 0;
    int num;
    while(1)
    {
        if(index >= MAX)
        {
            puts("超过数组最大个数");
            break;
        }
        printf("请输入元素%d/%d\n",index+1,MAX);
        scanf("%d",&num);
        arr[index++] = num;
    }
    for(int i = 0;i < index;i++)
    {
        printf("%d ",arr[i]);
    }
    //___________________
    //Delete;
    puts("请输入删除的位置：");
    int posion;
    scanf("%d",&posion);
    while(posion < 0 || posion > MAX)
    {
        puts("无效的位置");
        break;
    }
    for(int i = posion;i < MAX;i++)
    {
        arr[i-1] = arr[i];
    }
    for(int i = 0;i < MAX - 1;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n数组的第%d位现在的值是：\n%d \n",posion,arr[posion-1]);
    //_____________________________
    //改变数据
    puts("请输入要修改的位置：");
    int position;
    scanf("%d",&position);
    puts("请输入改动后的值：");
    scanf("%d",&num);
    while(position < 0|| position > MAX)
    {
        puts("无效位置");
    }
    arr[position - 1]= num;
    for(int i = 0;i < MAX;i++)
    {
        printf("%d ",arr[i]);
    }
    //_______________________________
    //查找数据
    puts("请输入想要查找的数字：");
    int num2;
    scanf("%d",&num2);
    int is_find = 0;
    for(int i = 0;i < MAX;i++)
    {
        if(arr[i] == num2)
        {
            printf("已成功查找。%d 是数组中的第 %d  个元素。",num2,i);
            is_find = 1;
        }
    }
    if(is_find == 0)
    {
        printf("没找到该数字。");
    }
    return;
}

void try4(void)
{
    //______________________________
    //数组初始化
    int arr1[50] = {1,2,3,4,5,6,7,8};
    int ir = 8;
FIRST:
//__________________________________
//开始菜单
    for(int i=0;i<ir;i++)
        printf("%d ",arr1[i]);
    sleep(1);
    printf("\n现在数组中一共有%d个元素",ir);
    puts("您想要进行什么操作？1：删除   2、插入   其他：退出。");
    int tags;
    scanf("%d",&tags);
    switch(tags)
    {
        case 1:
            goto DEL;
        case 2:
            goto ADD;
        default:
            return;
    }
    //______________________________
    //数组删除
DEL:
    if(ir == 0)
    {
        printf("已经没有元素可以删除了。\n");
        goto FIRST;
    }
    printf("请输入您想要删除的位置：\n");
    int d_area;
    scanf("%d",&d_area);
    if(d_area <=0 || d_area > ir)
    {
        printf("您输入的位置不在现有数组范围内。");
        goto DEL;
    }
    while(getchar() != '\n');
    for(int i = d_area-1;i<ir;i++)
    {
        arr1[i] = arr1[i+1];
    }
    arr1[ir-1] = 0;
    ir--;
    goto FIRST;
ADD:
    if(ir == 50)
    {
        puts("已经没有位置可以放下新元素力！");
        goto FIRST;
    }
    printf("请输入您想要插入的位置：\n");
    while(getchar() != '\n');
    int ad_area = 1;
    scanf("%d",&ad_area);

    if((ad_area <= 0) || (ad_area > ir+1))
    {
        printf("您输入的位置不在数组范围内。");
        goto ADD;
    }
    printf("请输入您想插入的值：\n");
    int addnum;
    scanf("%d",&addnum);
    while(getchar()!='\n');
    int zancun;
    for(int i = ad_area-1;i<=ir;i++)
    {
        zancun = arr1[i];
        arr1[i] = addnum;
        addnum = zancun;
    }
    ir++;
    goto FIRST;
    return;
}

//main函数区域
int main(void)
{
    try4();
    return 0;
}