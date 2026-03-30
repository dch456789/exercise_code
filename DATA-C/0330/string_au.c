#include <stdio.h>
#include <malloc.h>
#include <windows.h>

typedef struct 
{
    int ch;
    int freq;
}al_fq_t;

al_fq_t *cal_al_freq(const char *string,int *num);  //函数声明
al_fq_t *cal_al_freq(const char *string,int *num)   //函数原型
{
    int index;
    int freq[256] = {0};    //用来存储出现频次
    int count = 0;          //用来存储字符种类
    int ii = 0;             //单增
    al_fq_t *res;
    for(index = 0;string[index];index++)    //循环条件：当前位不为空
    {
        freq[string[index]]++;              //freq对应ASCII码位的频次+1
    }
    for(index = 0;index < 256;index++)
    {
        if(freq[index])
        {
            count++;                        //计算字符种类
        }
    }
    res = (al_fq_t*)calloc(sizeof(al_fq_t),count);      //申请存放字符和频次的空间
    for(index = 0;index < 256;index++)                  //字符和频次录入
    {
        if(freq[index])
        {
            res[ii].ch = index;                         //字符录入
            res[ii++].freq = freq[index];               //频次录入
        }
    }
    *num = count;                                       //返回字符种类
    return res;
}

/* 
核心思想：将字符串中的字符的ASCII码值当成下标，定义一个
拥有256个元素的数组，所有元素的值均为0
这个数组的下标的范围是：0到255，这在ASCII码取值范围内 */
int main(void)
{
    SetConsoleOutputCP(65001);
    char str[1024];
    int count;
    al_fq_t *alpha_freq = NULL;
    printf("请输入一个字符串：");
    gets(str);
    alpha_freq = cal_al_freq(str, &count);  //函数调用，传入字符指针和count的地址
    for(int index = 0;index < count;index++)
    {
        printf("al:%c  al:%d\n",alpha_freq[index],alpha_freq[index].freq);
    }
    free(alpha_freq);   //释放申请的空间
    return 0;
}