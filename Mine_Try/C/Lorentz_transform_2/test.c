#include <stdio.h>
#include "Lorentz_transform.h"
#include <windows.h>

int main(void) {
	SetConsoleOutputCP(65001);
	int i;
	int j = 0;
	AGAIN :
	puts("请选择：1:(百分比输入)  0:(m/s输入)=>");
	scanf("%d",&i);
	double k = 0;
	double c = 299792458;
	double v;
	if(i){
		puts("请输入速度(百分比)：");
		scanf("%lf",&k);
		v = k * c;
	}
	else{
		puts("请输入速度(静止速度)：");
		scanf("%lf",&v);	
	}
	double gamma = calculateGamma(v, c);
	
	printf("γ = %.4f\n\n", gamma);
	
	// 长度收缩
	double L0;  
	puts("请输入静止长度(m)：");
	scanf("%lf",&L0);
	double L = lengthContraction(L0, gamma);
	printf("长度收缩：%.4lf米 → %.4f米\n",L0,L);
	
	// 时间膨胀
	double properTime;
	puts("请输入坐标系下时间长度(s)：");
	scanf("%lf",&properTime);
	double t = timeDilation(properTime, gamma);
	printf("时间膨胀：%.4lf秒 → 外界 %.4f秒\n",properTime,t);

	//逆变换
	puts("");
	printf("运动参考系%.4lf米 -> 外界%.4lf米\n",L0,c/inverse_lorentz_x(calculateGamma(v,c),L0,v,properTime));
	printf("运动参考系%.4lf秒 -> 外界%.4lf秒\n",properTime,inverse_lorentz_t(calculateGamma(v,c),properTime,v,L,c));
	puts("");
	// 速度叠加
	double u;
	if(i){
	u = (k * c);
	}
	else {
		u = v;
	}
	double uTotal = velocityAddition(u, v, c);
	printf("速度叠加：%.4lf m/s + %.4lf m/s = %.4lf c\n",u,v, uTotal / c);
	puts("是否继续？1/0");
	scanf("%d",&j);
	if(j)
		goto AGAIN;
	return 0;
}

