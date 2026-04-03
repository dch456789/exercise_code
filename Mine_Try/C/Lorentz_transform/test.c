#include <stdio.h>
#include <math.h>
#include <windows.h>

#include "Lorentz_transform.h"

int main(void)
{
    SetConsoleOutputCP(65001);
    double velocity;
    double speed0flight;
    double gamma;
    int i = 0;
    while(0 == i){
        speed0flight = 1;
        printf("请输入物体相对静止坐标系的速度(单位:3e8m/s,必须小于一):");
        scanf("%lf",&velocity);
        printf("请输入你设想的运动坐标系的真空光速(静止真空光速的倍数):");
        scanf("%lf",&speed0flight);
        gamma = calculateGamma(velocity,speed0flight);
        printf("洛伦兹变换因子Gamma为：%.4lf,当前光速为：%.4lfc \n",gamma,speed0flight);
        printf("当前参考系下的单位坐标变换为：%.4lf ,运动系下单位长度为现实长度的：%.4lf \n",calculate_x(gamma,velocity),1/calculate_x(gamma,velocity));

        printf("当前参考系下的单位时间变换为：%.4lf ,运动系下每秒为现实时间的：%.4lf 秒。\n",calculate_t(gamma,velocity),1/calculate_t(gamma,velocity));
        puts("是否继续？1/0");
        scanf("%d",&i);
        if(i) i=0;
        else return 0;
    }
}