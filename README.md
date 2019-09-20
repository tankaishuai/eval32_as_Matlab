# eval32_as_Matlab

迷你版仿Matlab矩阵表达式计算解释器

========================================

这是大学期间开发的一款 精简版 Matlab 解释器，麻雀虽小却五脏俱全。

解决了安装Matlab这一大块头的麻烦问题，同时也便于嵌入其他应用程序中使用。

实际完整包包含了 ANSI/Unicode版本、矩阵计算/标量计算版本、ActiveX控件、

   插件开发SDK、示例源代码、VB/js/Matlab/批处理等多语言开发包、帮助文档等等内容。
    
此处一律精简掉，未提供。（仅保留了ANSI的最简SDK）

========================================

用法示例如下：

![eval32](https://github.com/tankaishuai/eval32_as_Matlab/blob/master/doc/1.png)

![eval32](https://github.com/tankaishuai/eval32_as_Matlab/blob/master/doc/2.png)

![eval32](https://github.com/tankaishuai/eval32_as_Matlab/blob/master/doc/3.png)

![eval32](https://github.com/tankaishuai/eval32_as_Matlab/blob/master/doc/4.png)

![eval32](https://github.com/tankaishuai/eval32_as_Matlab/blob/master/doc/5.png)

========================================

使用 eval32 SDK 进行4次多项式拟合：y = ax^4 + bx^3 + cx^2+ dx + e：

#include "eval32.h"

int main(int argc,char *argv[])
{ 
  tsInitialize(NULL,NULL,NULL); 

  //4次多项式拟合：y = ax^4 + bx^3 + cx^2+ dx + e
  tsMatrix * pmX = tsAllocM(1);
  
  int ret = tsEvalExprM("x = 1:10; y = exp(-x); polyfit(x, y, 4)", pmX);
  if(ret >= 0)
  {
  	assert(5 == tsSizeM(pmX, 2));      //结果应该是 1x5的矩阵
  	
   double *pfX = tsAddRM(pmX, 1, 1);  //取矩阵实部数据
  	
   printf("%f %f %f %f %f\n", pfX[0], pfX[1], pfX[2], pfX[3], pfX[4]);
  }
  
  tsFreeM(pmX);

  tsTerminate(); 
  return 0; 
}

![eval32](https://github.com/tankaishuai/eval32_as_Matlab/blob/master/doc/6.jpg)
