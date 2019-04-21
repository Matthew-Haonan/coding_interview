#double数值的整数次方
***
## 题目描述：  
实现函数double Power(double base, int exponent),求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。  
#### 样例输入：
2   3  
3.0 2  
2.0 -1  
0   0  
0   -1  
5   100  
#### 样例输出：
2.000000 ^ 3 = 8.000000  
3.000000 ^ 2 = 9.000000  
2.000000 ^ -1 = 0.500000  
Invalid Input!!  
Invalid Input!!  
5.000000 ^ 100 =7888609052210122777055599015258336957644248558834845341259549357637632.000000  
  
##需要注意的点
1.  scanf()在扫描double的时,应该使用"%lf"；而在printf()时，“%f”和“%lf”都可以；
2.  注意指数为负以及底数为0这些特殊情况的处理；