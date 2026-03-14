#include <stdio.h>

int main(void)
{
    int a = 0b11010010;
    int b = -0b00101110;
    printf("a(0b11010010)=%d\tb(-0b00101110)=%d\n",a,b);
    printf("a的浮点数输出:%f\n",a);
    printf("a的十六进制输出:%X\n",a);
    printf("a的八进制输出:%o\n",a);
    printf("a的输出为%%4d:%4d\n",a);
    printf("a的输出为%%04d:%04d\n",a);
    printf("a的输出为%%-5d:%-5d\n",a);
    printf("A的八进制表示输出\\101：%c\n",'\101');
    printf("\\x64的10进制表示：%d\n",'\x64');
    int x = 0x1aa;
    printf("1aa的十进制输出为：%d\n",x);
    x = 077;
    printf("077的十进制输出为：%d\n",x);
    printf("0x1aa的十进制直接转换输出为：%d\n",0x1aa);
    printf("sizeof(int)=%d\n",sizeof(int));
    printf("sizeof(char)=%d\n",sizeof(char));
    printf("sizeof(short)=%d\n",sizeof(short));
    printf("sizeof(long)=%d\n",sizeof(long));
    printf("sizeof(float)=%d\n",sizeof(float));
    printf("sizeof(double)=%d\n",sizeof(double));
    puts("接下来输出0x1aa与077中较大的那个，使用 ?: 方式：\n\t0x1aa > 077 ? 0x1aa : 077;");
    printf("\n\t结果为：%d\n",0x1aa > 077 ? 0x1aa : 077);
    int c = 100;
    printf("int 100强制转换float：(float)100 == %.3f\n",(float)c);
    return(0);
}