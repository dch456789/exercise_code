#include <stdio.h>
#include <malloc.h>
#include <windows.h>

typedef struct 
{
    int ch;
    int freq;
}al_fq_t;

al_fq_t *cal_al_freq(const char *string,int *num);
al_fq_t *cal_al_freq(const char *string,int *num)
{
    int index;
    int freq[256] = {0};
    int count = 0;
    int ii = 0;
    al_fq_t *res;
    for(index = 0;string[index];index++)
    {
        freq[string[index]]++;
    }
    for(index = 0;index < 256;index++)
    {
        if(freq[index])
        {
            count++;
        }
    }
    res = (al_fq_t*)calloc(sizeof(al_fq_t),count);
    for(index = 0;index < 256;index++)
    {
        if(freq[index])
        {
            res[ii].ch = index;
            res[ii++].freq = freq[index];
        }
    }
    *num = count;
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
    alpha_freq = cal_al_freq(str, &count);
    for(int index = 0;index < count;index++)
    {
        printf("al:%c  al:%d\n",alpha_freq[index],alpha_freq[index].freq);
    }
    free(alpha_freq);
    return 0;
}