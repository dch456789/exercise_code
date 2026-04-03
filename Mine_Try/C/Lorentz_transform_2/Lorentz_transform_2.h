#ifndef LORENTZ_TRANSFORM_H
#define LORENTZ_TRANSFORM_H

// 洛伦兹因子 γ
double calculateGamma(double v, double c);

// 正变换：静止系 → 运动系
double lorentz_x(double gamma, double x, double v, double t);
double lorentz_t(double gamma, double t, double v, double x, double c);

// 逆变换：运动系 → 静止系
double inverse_lorentz_x(double gamma, double x_prime, double v, double t_prime);
double inverse_lorentz_t(double gamma, double t_prime, double v, double x_prime, double c);

// ==================== 新增全套相对论公式 ====================
// 长度收缩（静止长度 → 运动长度）
double lengthContraction(double L0, double gamma);

// 时间膨胀（固有时 → 运动时）
double timeDilation(double properTime, double gamma);

// 相对论速度叠加（u：物体在运动系速度，v：系相对速度 → 地面速度）
double velocityAddition(double u, double v, double c);

#endif

