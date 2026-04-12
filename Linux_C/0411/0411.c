#include <stdio.h>
#include <stdlib.h>
#include <string.h>





void filadd(FILE *fori, FILE *ftarg);
void filwrite(FILE *fori);
void coppy(int argc, char const **argv, FILE *ftarg);
void try4(int argc, char const **argv);

void filadd(FILE *fori, FILE *ftarg)
{
    char sbt[1024];
    do
    {
        memset(sbt, '\0', sizeof(sbt));
        fgets(sbt, sizeof(sbt), fori);
        fprintf(stderr,"%s",sbt);
        fputs("没有开始录入",stderr);
        if(strlen(sbt) > 0)
            fputs(sbt,ftarg);
    } while (!feof(fori));
}

void filwrite(FILE *fori)
{
    char sbt[1024];
    memset(sbt, '\0', sizeof(sbt));
    fgets(sbt, 1024, stdin);
    fputs(sbt, fori);
    return;
}

void coppy(int argc, char const **argv, FILE *ftarg)
{
    FILE *fori = NULL;
    for (int i = 1; i < argc - 1; i++)
    {
        if (NULL == (fori = fopen(argv[i], "w+")))
        {
            fprintf(stderr, "打开源文件%s失败\n", argv[i]);
            continue;
        }
        fprintf(stderr, "打开源文件%s成功,开始合并到文件%s\n", argv[i], argv[argc - 1]);
        filwrite(fori);
        fprintf(stderr, "完成字符串输入。\n");
        fclose(fori);
    }
     for (int i = 1; i < argc - 1; i++)
    {
        if (NULL == (fori = fopen(argv[i], "r")))
        {
            fprintf(stderr, "打开源文件%s失败\n", argv[i]);
            continue;
        }
        fprintf(stderr, "打开源文件%s成功,开始合并到文件%s\n", argv[i], argv[argc - 1]);
        filadd(fori,ftarg);
        fprintf(stderr, "完成对%s的合并。\n", argv[i]);
        fclose(fori);
    }
}

void try4(int argc, char const **argv)
{
    if (argc < 3)
    {
        fprintf(stderr, "缺少参数\n命令格式为: %s ... ... 目标文件名\n", argv[0]);
        return;
    }
    FILE *ftarg = NULL;
    if (NULL == (ftarg = fopen(argv[argc - 1], "w")))
    {
        fprintf(stderr, "创建目标文件%s失败\n", argv[argc - 1]);
        exit(0);
    }
    fprintf(stderr, "创建目标文件[%s]成功，开始拷贝。\n", argv[argc - 1]);
    coppy(argc, argv,  ftarg);
}

int main(int argc, char const **argv)
{
    try4(argc, argv);
    return 0;
}