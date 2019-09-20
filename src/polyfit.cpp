#include "eval32.h"


int main(int argc,char *argv[])
{ 
  tsInitialize(NULL,NULL,NULL); 

  //4�ζ���ʽ��ϣ�y = ax^4 + bx^3 + cx^2+ dx + e
  tsMatrix * pmX = tsAllocM(1);
  
  int ret = tsEvalExprM("x = 1:10; y = exp(-x); polyfit(x, y, 4)", pmX);
  if(ret >= 0)
  {
  	assert(5 == tsSizeM(pmX, 2));      //���Ӧ���� 1x5�ľ���
  	
  	double *pfX = tsAddRM(pmX, 1, 1);  //ȡ����ʵ������
  	
  	printf("%f %f %f %f %f\n", pfX[0], pfX[1], pfX[2], pfX[3], pfX[4]);
  }
  
  tsFreeM(pmX);

  tsTerminate(); 
  return 0; 
}
