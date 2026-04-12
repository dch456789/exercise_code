#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 标准IO：通过FILE*指针操作文件
// 文件的打开
// FILE * fopen(const char *FileName,const char  *Mode)
// FileName：文件路径
// Mode:操作方式
// r读  w写 a 追加 +可读可写 b二进制方式  rwa不会同时使用
// w a 如果文件不存在，则重新创建
// w 如果文件已经存在，则删除旧的文件重新创建
// a 如果文件已经存在，则直接打开
// r 如果文件不存在,则出错，如果存在，则直接打开

// 文件关闭
// int fclose(FILE*)

// 标准输入文件 stdin
// 标准输出文件 stdout  有缓冲区
// 标准错误文件 stderr  没有缓冲区

// 文件结束符E -1  OF
// 判断文件是否结束 feof(FILE*)

// 文本方式操作文件
// int fgetc(FILE *)  	从文件读取一个字符，并返回该字符
// fputc(char c,FILE*)  	将字符c写入文件

// fgetc(stdin);		 //从键盘读取1个字符
// fputc(ch,stdout);   //输出字符到显示器

// fgets(char *str,int count,FILE*) ;//从文件读取count字节到内存str
// fputs(const char *str,FILE*) ;//将字符串str中的有效内容输出到文件

// fscanf(FILE*,"格式控制符",内存指针列表)  //从文件按格式读取数据到内存
// fprintf(FILE*,"格式控制符",变量列表) //按格式将内存中的数据输出到文件

// scanf("格式控制符",)  printf("格式控制符",)

// 二进制方式操作文件
// fread  fwrite

// 技术点1:文件的打开和关闭
void test001()
{
	FILE *fp = NULL;
	fp = fopen("./a1.txt", "w");
	if (fp == NULL)
	{
		puts("打开文件失败，请确认路径");
		return;
	}
	puts("打开文件成功");

	fclose(fp);
	puts("文件关闭");
}

// 技术点2:按字符读写文件
void test002()
{
	FILE *fp = fopen("a.txt", "r");
	if (fp == NULL)
	{
		puts("打开文件错误");
		return;
	}
	puts("打开文件成功");
	// char ch=fgetc(fp);
	char ch = fgetc(fp);
	// while(ch!=-1)
	while (ch != EOF)
	{
		// putchar(ch);
		fputc(ch, stdout);
		ch = fgetc(fp);
		// printf("ch=%c ch=%d\n",ch,ch);
		// getchar();
	}

	fclose(fp);
	puts("打开关闭");
}

// 技术点3://键盘录入一段文字保存到文件b.txt,回车录入结束
void test003()
{
	FILE *fp = NULL;
	if ((fp = fopen("b.txt", "w")) == NULL)
	{
		puts("打开文件失败");
		return;
	}
	puts("创建文件成功");

	char c = fgetc(stdin);
	int size = 0;
	while (c != 10)
	{
		fputc(c, fp);
		size++;
		c = fgetc(stdin);
	}

	printf("共输入%d字节\n", size);

	fclose(fp);
}

// 技术点4：按字符串读写文件
void test004()
{
	FILE *fp = NULL;
	if ((fp = fopen("a.txt", "r")) == NULL)
	{
		puts("打开文件失败");
		return;
	}
	puts("打开文件成功");
	char buf[300] = "\0";

	do
	{
		fgets(buf, 300, fp);
		printf("读取到数据:%s\n", buf);
	} while (!feof(fp));

	fclose(fp);
	puts("文件关闭");
}

// 技术点5：按字符串读写操作方式实现两个文件的拷贝
void test005()
{
	FILE *fp = NULL;
	if ((fp = fopen("a.txt", "r")) == NULL)
	{
		puts("打开文件失败");
		return;
	}
	puts("打开源文件成功");

	FILE *fpRes = NULL;
	if ((fpRes = fopen("b.txt", "w")) == NULL)
	{
		puts("打开目标文件失败");
		return;
	}
	puts("打开目标文件成功");

	char buf[300] = "\0";
	int totalSize = 0;
	// 读取源文件，保存到目标文件
	do
	{
		fgets(buf, 300, fp);
		fputs(buf, fpRes);
		totalSize += strlen(buf);
	} while (!feof(fp));

	// 关闭文件
	fclose(fpRes);
	fclose(fp);
	printf("拷贝完毕，文件已关闭,共复制%d字节\n", totalSize);
	return;
}

// 技术点6：fscanf和fprintf的简单用法
void test006()
{
	char name[128];
	int age;
	puts("请输入内容");
	scanf("%s %d", name, &age);
	printf("Name:%s  Age:%d\n", name, age);

	fputs("请输入内容\n", stdout);
	fscanf(stdin, "%s %d", name, &age);
	fprintf(stdout, "name:%s  age:%d\n", name, age);

	return;
}


struct  student
{
	char name[128];
	int age;
};


void initStudent(struct  student*s)
{
	if(s)
	{
		fputs("请输入内容\n", stdout);
		fscanf(stdin, "%s %d", s->name, &(s->age));
	}
}
void printStudent(struct student *s)
{
	if(s)
	{
		fprintf(stdout, "%-16s %d\n", s->name, s->age);
	}
}

//fscanf和fprintf完成数据的输入输出
void test007()
{
	struct   student  s[1024];
	int size=0;
	puts("请输入要初始化的个数:");
	fscanf(stdin,"%d",&size);
	if(size<0||size>1023)
	{
		puts("输入无效");
		return;
	}

	for(int i=0;i<size;i++)
	{
		initStudent(s+i);
	}
	
	for(int i=0;i<size;i++)
	{
		printStudent(s+i);
	}

	return;
}

//fscanf和fprintf完成数据的输入输出
//fscanf和fprintf完成数据从文件载入并保存到文件
void test008()
{
	struct   student  s[1024];


	//输出数据保存到数据库文件
	FILE  *data=NULL;
	if((data=fopen("db.db","r"))==NULL)
	{
		puts("打开数据库失败");
		return;
	}
	puts("打开数据库成功");


	//从文件读取数据到内存数组
	int index=0;
	do
	{
		struct student  temp;
		fscanf(data,"%20s%6d",temp.name,&(temp.age));
		s[index]=temp;
	} while (!feof(data));

	//输出读取的数据
	for(int i=0;i<index;i++)
	{
		printStudent(s+i);
	}

	//接受用户输入的新数据
	int size=0;
	puts("请输入要新增的个数:");
	fscanf(stdin,"%d",&size);
	if(size<0||size-index>1023)
	{
		puts("输入无效");
		return;
	}

	for(int i=0;i<size;i++)
	{
		initStudent(s+index+i);
	}
	
	//输出新数据到显示器
	for(int i=0;i<size;i++)
	{
		printStudent(s+i);
	}

	//输出所有数据保存到数据库文件
	FILE  *fp=NULL;
	if((fp=fopen("db.db","w"))==NULL)
	{
		puts("创建文件失败");
		return;
	}

	puts("创建文件成功");
	for(int i=0;i<index+size;i++)
	{
		fprintf(fp,"%-20s%-6d\n",s[i].name,s[i].age);
	}
	puts("保存数据成功");

	fclose(fp);
}


int main(int argc, char const *argv[])
{
	puts("++++++++++++++++ 1 ++++++++++++++++");
	// test001();

	puts("++++++++++++++++ 2 ++++++++++++++++");
	// test002();

	puts("++++++++++++++++ 3 ++++++++++++++++");
	// test003();

	puts("++++++++++++++++ 4 ++++++++++++++++");
	// test004();

	puts("++++++++++++++++ 5 ++++++++++++++++");
	// test005();

	puts("++++++++++++++++6 ++++++++++++++++");
	//test006();

	puts("++++++++++++++++7 ++++++++++++++++");
	//test007();

	puts("++++++++++++++++8 ++++++++++++++++");
	test008();
	return 0;
}


//作业:
//程序启动，输入多个文件名，完成文件内容的合并
//  ./app a b c d e f g h j  k   //合并a b c d e f g h j的内容到k