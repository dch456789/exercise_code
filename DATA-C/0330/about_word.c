#include <stdio.h>
#include <ctype.h>
#include <string.h>
void output_word(char *contex);
void output_word(char *contex)
{
    int cur;
    int pre = ' ';
    int index;
    char word[81];
    int word_index = 0;
    index = 0;
    do{
        cur = contex[index];
        if(!isalnum(pre) && isalnum(cur))
        {
            word_index = 0;
            word[word_index++] = cur;
        }
        else if(isalnum(pre) && isalnum(cur)){
            word[word_index++] = cur;
        }
        else if(isalnum(pre) && !isalnum(cur)){
            word[word_index] = 0;
            puts(word);
        }
        pre = cur;
        ++index;
    }
    while(cur);
    //printf("sizeof contex:%d\n",sizeof(contex));
}
int main(void)
{
    char str[81];

    printf("请输入一个字符串：\n");
    gets(str);
    output_word(str);
    return 0;
}