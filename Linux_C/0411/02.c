#include   <stdio.h>
#include   <stdlib.h>
#include   <string.h>
// fread(const void*)

//从add开始的elementCount个elementSize大小的数据写入到文件
// fwrite(const void*add,size_t elementSize,size_t elementCount,FILE *)


//二进制写入数据
void test001()
{
 
    FILE  *fp=NULL;
    if( (fp=fopen("data","wb"))==NULL)
    {
        return;
    }
    puts("创建数据库成功");
    int data[12];
    for(int i=0;i<12;i++)
    {
        data[i]=rand()%100;
    }
 
    for(int i=0;i<12;i++)
    {
        fprintf(stderr,"[%d]=>%d\n",i,data[i]);
    }

    for(int i=0;i<12;i++)
    {
        fwrite(data+i,sizeof(int),1,fp);
    }
    
    fclose(fp);
}

//二进制读取数据
void test002()
{
    FILE  *fp=NULL;
    if( (fp=fopen("data","rb"))==NULL)
    {
        return;
    }
    puts("打开数据库成功");
    int *a=(int*)malloc(sizeof(int));
    for(int i=0;i<12;i++)
    {
        fread(a,sizeof(int),1,fp); 
        fprintf(stdout,"[%d]:%d\n",i,*a);
    }
    free(a);

    fclose(fp);
}

#define  STU_SIZE 120
#define NAME_SIZE 128
#define  SCORE_SIZE 6
struct  student
{
	char name[NAME_SIZE];
	int score[SCORE_SIZE];
    double avg;
};
typedef struct  student student;


void  test003()
{
    student data[STU_SIZE];
    memset(data,'\0',sizeof(student)*STU_SIZE);

    //初始化所有学生信息
    for(int i=0;i<STU_SIZE;i++)
    {
        //初始化姓名
        memset(data[i].name,rand()%25+65,4);
        memset(data[i].name+strlen(data[i].name),rand()%25+97,4);
        memset(data[i].name+strlen(data[i].name),rand()%25+97,4);

        //初始化各科成绩
        for(int j=0;j<SCORE_SIZE;j++)
        {
            data[i].score[j]=rand()%80+70;
        }

        //初始化平均分
        data[i].avg=0.0;
    }

    //创建数据库文件
    FILE  *fp=fopen("stu.db","wb");
    if(fp==NULL)
    {
        puts("创建学生数据库失败");
        return;
    }
     puts("创建学生数据库成功");

    //将数据写入文件保存
    fwrite(data,sizeof(student),STU_SIZE,fp);

    //关闭文件 
    fclose(fp);
}

void  test004()
{
    student data;

    //打开数据库文件
    FILE  *fp=fopen("stu.db","rb");
    if(fp==NULL)
    {
        puts("打开学生数据库失败");
        return;
    }
    puts("打开学生数据库成功");

    //从文件读取数据
    for(int i=0;i<STU_SIZE;i++)
    {
        fread(&data,sizeof(student),1,fp);
        fprintf(stderr,"[%-03d] %s\t",i,data.name);
        int sum=0;
        for(int j=0;j<SCORE_SIZE;j++)
        {
            fprintf(stderr,"%4d",data.score[j]);
            sum+=data.score[j];
        }
        data.avg=(double)sum/SCORE_SIZE;
        fprintf(stderr,"\t%.2lf\n",data.avg);
    }

    //关闭文件 
    fclose(fp);

}

int main()
{
    puts("=++++++++++++++++++ 1 +++++++++++++++=");
//    test001();
    puts("=++++++++++++++++++ 2 +++++++++++++++=");
//    test002();
    puts("=++++++++++++++++++ 1 +++++++++++++++=");
    test003();
    puts("=++++++++++++++++++ 2 +++++++++++++++=");
    test004();
}