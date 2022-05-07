num=[1,2];
den=[1, -4, 8]; %开环传函分母多项式系数
sys=tf(num,den);                         %系统传递函数模型
rlocus(sys);                             %绘制系统的根轨迹图