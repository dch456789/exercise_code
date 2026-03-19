#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *united(const char *str1,const char *str2)  //字符串的扩容
{
    size_t str1_len = strlen(str1);
    size_t str2_len = strlen(str2);
    size_t result_len = str1_len + str2_len + 1;
    char *result = malloc(result_len);
    if(result == NULL)
    {
        puts("内存分配失败。");
        return NULL;
    }
    strcpy(result,str1);
    strcpy(result,str2);
    result[result_len-1] = '\0';
    return result;
}
void try1(void)
{
    char str1[] = "hello,";
    char str2[] = "World!";
    char *realstr = united(str1,str2);
    printf("%s",realstr);
    free(realstr);
    realstr = NULL;
    return;
}
//________________________________________
char *input_str(void)    //字符串的输入扩容
{
    int capacity = 10; //只能输入9个字符
    char *result = malloc(capacity);
    if(result == NULL)
    {
        puts("内存分配失败！");
        return NULL;
    }
    puts("请输入字符串:");
    int c;
    int count = 0;
    while((c = getchar()) != '\n')
    {
        if(count >= capacity-1)
        {
            capacity *= 2;
            char *new_ptr = realloc(result,capacity);
            if(result == NULL)
            {
                puts("内存分配失败！");
                free(result);
                return NULL;
            }
            puts("扩容成功！");
            result = new_ptr;
        }
        result[count++] = c;

    }
    result[count++] = '\0';
    return result;
}
void try2(void)
{
    char *ptr = input_str();
    printf("\n%s",ptr);
    free(ptr);
    ptr = NULL;
}

int main(void)
{
    try2();
    return 0;
}