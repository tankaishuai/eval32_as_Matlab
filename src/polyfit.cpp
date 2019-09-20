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
