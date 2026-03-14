#include <stdio.h>
#include <math.h>
#include <string.h>
#define COSX 3    //try1
#define COSY 4    //try1
#define CX 3    //try2,3：人数
#define CY 50    //try2,3：名称长度

void try1(void);    //二维数组的动态输入
void try2(void);
void try3(void);

void try1(void)
{
    //——————————————————————————————————————————————————
    //数组初始化和显示。
    int arr[COSX][COSY] = {0};
    for(int i = 0;i < COSX;i++)
    {
        for(int j = 0;j < COSY;j++)
        {
            printf("%d ",arr[i][j]);
        }
        puts("");
    }
    //————————————————————————————————————————————————————————
    //数组进行赋值操作。
    puts("请输入二维数组的值，-1结束：");
    int total_num = 0;
    while(total_num <(COSX * COSY))
    {
        int num = 0;
        printf("现在输入第%d/%d个元素。",total_num + 1,COSX * COSY);
        
        while(!scanf("%d",&num))
        {
            printf("输入的不是数字，请重新输入：");
            while(getchar()!= '\n');
            continue;
        }
        if(num == -1)
        {
            break;
        }
        int cox = total_num/COSY;
        int coy = total_num%COSY;
        arr[cox][coy] = num;
        total_num++;
        for(int i = 0;i < COSX;i++)
        {
            for(int j = 0;j < COSY;j++)
            {
                if(total_num> (i* COSY) + j)
                {
                    printf("%5d",arr[i][j]);
                }
                else
                {
                    printf("%s","    -");
                }
            }
            puts("");
        }
    }
    while(getchar() != '\n');    //清空缓冲区
    //_______________________________________
    //赋值结束，追加操作部分。

    printf("如果想要继续输入，请按回车：");
    while(getchar() == '\n')
    {
        printf("进入追加模式。");
        printf("\n请输入二维数组的值，-1结束。");
        while(total_num <(COSX * COSY))
        {
            int num = 0;
            printf("现在输入第%d/%d个元素。",total_num + 1,COSX * COSY);
            
            while(!scanf("%d",&num))
            {
                printf("输入的不是数字，请重新输入：");
                while(getchar()!= '\n');
                continue;
            }
            if(num == -1)
            {
                break;
            }
            int cox = total_num/COSY;
            int coy = total_num%COSY;
            arr[cox][coy] = num;
            total_num++;
            for(int i = 0;i < COSX;i++)
            {
                for(int j = 0;j < COSY;j++)
                {
                    if(total_num> (i* COSY) + j)
                    {
                        printf("%5d",arr[i][j]);
                    }
                    else
                    {
                        printf("%s","    -");
                    }
                }
                puts("");
            }
        }
    while(getchar() != '\n');
    printf("输入结束，是否继续？若继续，请按回车：");
    }
    return;
}

void try2(void)
{
    //char name[][20] = {"name","table"};    //从又向左读取，因此最重要的是列。
    //char subject[][10] = {"语文","数学","英语"}
    char name[CX][CY] = {0};
    char subject[3][10] = {"语文","数学","英语"};
    float score[CX][3] = {0};
    int index = 0;
    while(1)
    {
        puts("请输入学生的姓名：按esc退出");

        char name_tmp[100];
        fgets(name_tmp,sizeof(name_tmp),stdin);

        /* if(fgets(name_tmp,10,stdin) == NULL)
        {
            printf("输入有误，重新输入！\n");
            continue;
        } */

        name_tmp[strcspn(name_tmp,"\n")] = 0;
        int lenth = strlen(name_tmp);
        if(!lenth)
        {
            printf("输入有误，重新输入！\n");
            continue;
        }
        if(!strcmp(name_tmp,"esc"))
        {
            break;
        }
        strcpy(name[index],name_tmp);
        index++;
    }
    for(int i = 0;i < index;i++)
    {
        printf("%s ",name[i]);
    }
    puts("");
    //————————————————————————————
    //学生成绩录入：
    for(int i = 0;i < index;i++)
    {
        for(int j = 0;j<3;j++)
        {
            printf("请输入%s的%s成绩：",name[i],subject[j]);
            scanf("%f",&score[i][j]);
        }
    }
    //______________________________
    //简易成绩输出：
    printf("%d\n",index);
    for(int i=0;i<COSX;i++)
    {
        for(int j=0;j<COSY;j++)
        {
            printf("%-10.2f  ",score[i][j]);
        }
        printf("\n");
    }
    //格式化输出：
    for(int i=0;i<index;i++)
    {
        printf("%s的",name[i]);
            for(int k=0;k<3;k++)
            {
                printf("%s 成绩为：%.2f",subject[k],score[i][k]);
            }
            puts("");
    }
    
}

void try3(void)
{
    char name[CX][CY] = {0};
    char subject[3][10] = {"语文","数学","英语"};
    float chengji[CX][3] = {0};
    int peop = 0;
    float avg_sub[2][3] = {0};
    float max_min[2][3] = {0};

    while(1)
    {
        puts("请输入学生的姓名：输入esc退出。");
        char name_f[100];

        //______________________
        //姓名输入模块
        fgets(name_f,sizeof(name_f),stdin);
        name_f[strcspn(name_f,"\n")] = 0;
        int lenth = strlen(name_f);
        if(!lenth)
        {
            printf("输入有误，请重新输入：\n");
            continue;
        }
        if(!strcmp(name_f,"esc"))
        {
            break;
        }
        strcpy(name[peop],name_f);
        peop++;
        if(peop == CX)
        {
            printf("人数已经满了，无法继续输入。\n");
            break;
        }
    }
    for(int i = 0;i < peop;i++)
    {
        printf("%s  ",name[i]);
    }
    puts("");
    //______________________________________
    //学生成绩录入
    for(int i = 0;i < peop;i++)
    {
        for(int j =0;j < 3;j++)
        {
            printf("请输入 %s 的 %s 成绩：",name[i],subject[j]);
            scanf("%f",&chengji[i][j]);
        }
    }
    //_________________________________________
    //格式化输出；
    printf("%d 人\n",peop);
    for(int i = 0;i < peop;i++)
    {
        printf("%s 的",name[i]);
        for(int j = 0;j < 3;j++)
        {
            printf("%s 成绩为：%10.2f    ",subject[j],chengji[i][j]);
        }
        puts("");
    }
    //_________________________
    //各科成绩的平均分与总分
    for(int i = 0;i < peop;i++)    //总分
    {
        for(int j = 0;j < 3;j++)
        {
            avg_sub[1][j] += chengji [i][j];
        }
    }
    for(int i = 0;i < 3;i++)
    {
        avg_sub[0][i] = (avg_sub[1][i]/peop);
    }
    for(int i = 0;i < 3;i++)
    {
        printf("%s 科目的平均分为：%5.2f ,总分为：%5.2f;\n",subject[i],avg_sub[0][i],avg_sub[1][i]);
    }
    //______________________________________
    //各科最值输出：
    for(int i = 0;i < 3;i++)//i为科目
    {
        for(int j = 0;j < peop - 1;j++)//j为人数
        {
            float a = chengji[j][i];
            float mi = chengji[j][i];
            if(a < chengji[j+1][i])
            max_min[1][i] = a;
            else
            max_min[1][i] = chengji[j+1][i];
            if(mi > chengji[j+1][i])
            max_min[0][i] = mi;
            else
            max_min[0][i] = chengji[j+1][i];
        }
    }
    for(int j = 0;j < 3;j++)
    {
        printf("%s 科目的最高分为：%5.2f ，最低分为：%5.2f ；\n",subject[j],max_min[0][j],max_min[1][j]);
    }
}

int main(void)
{
    try3();
    return 0;
}