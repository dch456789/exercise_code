#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int *insert_arr(int *size)    //动态扩容的数组录入
{
    int index = 0;
    int num;
    int capacity = MAX;
    int *arr = malloc(sizeof(int)*MAX);
    if(arr == NULL)
    {
        puts("内存分配失败！");
        return NULL;
    }
    puts("请输入数字.");
    while(num!=-1)
    {
        scanf("%d",&num);
        if(index >= capacity)
        {
            capacity *= 2;
            int *new_ptr = realloc(arr,sizeof(int)*capacity);
            if(new_ptr == NULL)
            {
                puts("扩容失败.");
                free(arr);
                *size = 0;
                return NULL;
            }
            puts("扩容成功！");
            arr = new_ptr;
        }
        arr[index++] = num;

    }
    *size = index-1;
    return arr;

}
void try1()
{
    int size = 0;
    int *ptr = NULL;
    ptr = insert_arr(&size);
    for(int i = 0;i < size;i++)
    {
        printf("%d ",ptr[i]);
    }
    free(ptr);
    ptr = NULL;
}
int main(void)
{
    try1();
    return 0;
}