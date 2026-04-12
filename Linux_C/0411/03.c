#include  <stdio.h>
//./app  a1  b1 c1 d1 
//char *argv[]={"./app" ," a1", " b1" ,"c1" ,"d1" }

//./app  a1 b1 
int main(int argc, char const  **argv)
{
    //fprintf(stderr,"argc:%d\n",argc);
    //for(int i=0;i<argc;i++)
    //{
    //    fprintf(stderr,"[%d]:%s\n",i,argv[i]);
    //}

    if (argc < 3)
    {
        fprintf(stderr,"缺少参数\n命令格式为: %s ... ... 目标文件名\n", argv[0]);
        return;
    }
    FILE* fpSour, * fpTarget;

    //先打开目标文件
    if (NULL == (fpTarget = fopen(argv[argc - 1], "w")))
    {
        fprintf(stderr,"创建目标文件%s失败\n", argv[argc - 1]);
        exit(0);
    }
    fprintf(stderr,"创建目标文件%s成功,开始拷贝文件\n", argv[argc - 1]);
    for (int i=1;i<argc-1;i++)
    {
        if (NULL == (fpSour = fopen(argv[i], "r")))
        {
            fprintf(stderr,"打开源文件%s失败\n", argv[i]);
            continue;
        }
        fprintf(stderr,"打开源文件%s成名,开始合并到文件%s\n", argv[i],argv[argc - 1]);
        char buf[1024];
        do
        {
            memset(buf,'\0',sizeof(buf));
            fgets(buf,sizeof(buf)-1,fpSour);
            if(strlen(buf)>0)
            {
                fputs(buf,fpTarget);    
            }
        } while (!feof(fpSour));

        fputc('\n', fpTarget);
        fprintf(stderr,"合并%s到文件%s完成\n", argv[i],argv[argc - 1]);
        fclose(fpSour);
        fprintf(stderr,"关闭源文件%s\n",argv[i]);
    }

    fclose(fpTarget);
    fprintf(stderr,"操作完成,关闭目标文件%s\n",fpTarget);

    return 0;
}