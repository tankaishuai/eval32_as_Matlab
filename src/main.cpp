#include "eval32.h"

int main(int argc,char *argv[])
{ 

  tsInitialize(NULL,NULL,NULL); 
    //ShellEval内核初始化 

  tsShellEvalM(); 
    //调用ShellEval tsMatrix矩阵类命令解释接口 

  tsTerminate(); 
    //ShellEval内核的撤销 

  return 0; 
}
