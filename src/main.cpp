#include "eval32.h"

int main(int argc,char *argv[])
{ 

  tsInitialize(NULL,NULL,NULL); 
    //ShellEval�ں˳�ʼ�� 

  tsShellEvalM(); 
    //����ShellEval tsMatrix������������ͽӿ� 

  tsTerminate(); 
    //ShellEval�ں˵ĳ��� 

  return 0; 
}
