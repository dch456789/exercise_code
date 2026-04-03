#include <math.h>
#include "Lorentz_transform.h"

// 洛伦兹因子 γ
double calculateGamma(double v, double c)
{
	return 1.0 / sqrt(1.0 - pow(v / c, 2));
}

// 正变换
double lorentz_x(double gamma, double x, double v, double t)
{
	return gamma * (x - v * t);
}

double lorentz_t(double gamma, double t, double v, double x, double c)
{
	return gamma * (t - (v * x) / (c * c));
}

// 逆变换
double inverse_lorentz_x(double gamma, double x_prime, double v, double t_prime)
{
	return gamma * (x_prime + v * t_prime);
}

double inverse_lorentz_t(double gamma, double t_prime,double v,double x_prime,double c)
{
	return gamma * (t_prime + (v * x_prime) / (c * c));
}

// ==================== 长度收缩 ====================
// 运动的物体看起来变短
// L = L0 / γ
double lengthContraction(double L0, double gamma)
{
	return L0 / gamma;
}

// ==================== 时间膨胀 ====================
// 运动的钟走得更慢
// t = γ * τ
double timeDilation(double properTime, double gamma)
{
	return properTime * gamma;
}

// ==================== 相对论速度叠加 ====================
// 永远不会超过光速！
// u' = (u + v) / (1 + uv/c²)
double velocityAddition(double u, double v, double c)
{
	return (u + v) / (1.0 + (u * v) / (c * c));
}

