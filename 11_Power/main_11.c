#include <stdio.h>
#define true 1
#define false 0
#define bool int 

bool global_InvalidInput = false;		//定义一个全局标志位，默认是flase，也就是有效输入
bool equal(double, double);
double Power(double, int);
double UnsignedPower(double , int);
int 
main(int argc, char* argv[])
{
	freopen("sample.txt","r",stdin);
	double base;
	int exponent;
	while(scanf("%lf",&base) != EOF)			//double在scanf时必须是%lf，在printf时可以是%f或者%lf
	{
		scanf("%d",&exponent);
		double result = Power(base,exponent);
		if(global_InvalidInput == true)
			printf("Invalid Input!!\n");
		else
			printf("%f ^ %d = %f\n",base,exponent,result);
	}
	return 0;
}

double 
Power(double base, int exponent)
{
	global_InvalidInput = false;		//每次进入Power函数都要重置
	if(equal(base, 0.0) && exponent <= 0)	//底数为0时，此时认为指数为小于等于0的值都是没意义的
	{	
		global_InvalidInput = true;
		return 0.0;
	}
	int UnsignedExponent = exponent;
	if (exponent < 0)
		UnsignedExponent = -exponent;
	double result = UnsignedPower(base, UnsignedExponent);
	if(exponent < 0)
		result = 1/result; 
	return result;
}

bool 
equal(double x1, double x2)
{
	if (x1 - x2 > -0.0000001 && x1 - x2 < 0.0000001)
		return true;
	else
		return false;
}

double
UnsignedPower(double base, int usignexponent)
{
	int i;
	double result = 1.0;
	if (0 == usignexponent)					//如果指数是0，值为1（因为Power函数中的前期处理，指数为0时，底数一定不为0）
		return result;
	for(i = 0; i < usignexponent; i++)
		result *= base;
	return result;
}