// eval32 v3.2.6 15/09/2010 Tan KaiShuai @ Antiy Labs.

/*

		ShellEval IS A MINI MATLAB OR MATCOM THAT EXPORTS ABOUT 200 MORE

	FUNCTIONS FOR USER TO SHELL.NOW IT HAS SURPORTED ALMOST ALL FUNCTIONS

	IN MATLAB KERNEL EXCEPT THE FOLLOWING FEATHERS:

	[1] NOT SURPORTED DATATYPE SUCH AS STRUCT CLASS ETC.

	[2] NOT SURPORTED CONTROL COMMAND SUCH AS WHILE FOR BREAK ETC.

	[3] NOT SURPORTED ANY GUI USER INTERFACE WITH CUI REPLACED

	[4] NOT SURPORTED M FILE TO SHELL WITH THE DLL FILE REPLACED

	[5] NOT SURPORTED VARABLE SAVE AND LOAD COMMAND OR FUNCTIONS

		COPYRIGHT (C) 2009-11-30 NEAU Tan KaiShuai Inc.

*/

//EVAL32_H

#ifndef EVAL32_H
#define EVAL32_H

//EXPORT MACRO

#ifdef EVAL32_EXPORTS
#define EVALEXPR_API __declspec(dllexport)
#else  //EVAL32_EXPORTS
#define EVALEXPR_API __declspec(dllimport)
#endif  //EVAL32_EXPORTS

//INCLUDE HEAD FILE

#include <math.h>
#include <malloc.h>
#include <time.h>
#include <tchar.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

//TYPE DEFINE

typedef struct {
	BYTE databuff[92];
}tsTMm;

#ifdef __cplusplus
class tsCMm {
private:
	BYTE databuff[92];
public:
	tsCMm(){}
	~tsCMm(){}
};
#endif  //__cplusplus

typedef double tsDouble;
typedef tsTMm  tsMatrix;

//EXPORTS FUNCTIONS LIST

#ifdef __cplusplus
extern "C" {
#endif  //__cplusplus

EVALEXPR_API INT tsInitialize(VOID * hApp,VOID * hKey,VOID * hWin);
EVALEXPR_API INT tsShellEval();
EVALEXPR_API INT tsShellEvalM();
EVALEXPR_API INT tsWin32ShellEval();
EVALEXPR_API INT tsTerminate();

EVALEXPR_API FARPROC tsRegInitFunc(FARPROC pfnFunc);
EVALEXPR_API FARPROC tsRegTermFunc(FARPROC pfnFunc);
EVALEXPR_API FARPROC tsRegDllMainFunc(FARPROC pfnFunc);

EVALEXPR_API FARPROC tsRegTransExprFunc(FARPROC pfnFunc);
EVALEXPR_API FARPROC tsRegTransExprMFunc(FARPROC pfnFunc);
EVALEXPR_API FARPROC tsRegCalcExprMulFunc(FARPROC pfnFunc);
EVALEXPR_API FARPROC tsRegCalcExprMulMFunc(FARPROC pfnFunc);
EVALEXPR_API FARPROC tsRegStrFuncFunc(FARPROC pfnFunc);
EVALEXPR_API FARPROC tsRegStrFuncMFunc(FARPROC pfnFunc);
EVALEXPR_API FARPROC tsRegStrOpFunc(FARPROC pfnFunc);
EVALEXPR_API FARPROC tsRegStrOpMFunc(FARPROC pfnFunc);
EVALEXPR_API FARPROC tsRegPreTransExprFunc(FARPROC pfnFunc);
EVALEXPR_API FARPROC tsRegStrFuncExternFunc(FARPROC pfnFunc);
EVALEXPR_API FARPROC tsRegPreTransExprMFunc(FARPROC pfnFunc);
EVALEXPR_API FARPROC tsRegStrFuncMExternFunc(FARPROC pfnFunc);

EVALEXPR_API TCHAR * tsRegStrExtOp(const TCHAR * szStrExtOp);
EVALEXPR_API TCHAR * tsRegStrBasOp(const TCHAR * szStrBasOp);

/*
	SOME USEFULL TOOLS
*/

EVALEXPR_API INT tsStrStrKmp(const TCHAR * szStr1,const TCHAR * szStr2);
EVALEXPR_API INT tsStrRep(const TCHAR * szSrc,const TCHAR * szFind,const TCHAR * szReplace,TCHAR * szDst);
EVALEXPR_API INT tsStrRepEx(const TCHAR * szSrc,const TCHAR * szFind,const TCHAR * szReplace,TCHAR * szDst);
EVALEXPR_API INT tsStrRepAssign(const TCHAR * szBuff,TCHAR * szFind,TCHAR * szBuff2);

EVALEXPR_API INT tsCreateDefVariable();
EVALEXPR_API INT tsCreateDefVariableM();
EVALEXPR_API INT tsSetExtVariableNum(INT nVarNum);
EVALEXPR_API INT tsGetExtVariableNum();
EVALEXPR_API INT tsFindFreeVariable();
EVALEXPR_API INT tsFindFreeVariableM();
EVALEXPR_API INT tsFindVariable(const TCHAR * szVarName,INT nVarLen);
EVALEXPR_API INT tsFindVariableM(const TCHAR * szVarName,INT nVarLen);

EVALEXPR_API INT tsCreateVariable(const TCHAR * szVarName,INT nVarLen,tsDouble * vValue);
EVALEXPR_API INT tsCreateVariableM(const TCHAR * szVarName,INT nVarLen,tsMatrix * vValue);
EVALEXPR_API INT tsSetVariable(INT nVarNum,tsDouble * vValue);
EVALEXPR_API INT tsSetVariableM(INT nVarNum,tsMatrix * vValue);
EVALEXPR_API INT tsGetVariable(INT nVarNum,tsDouble * vValue);
EVALEXPR_API INT tsGetVariableM(INT nVarNum,tsMatrix * vValue);
EVALEXPR_API INT tsRemoveVariable(INT nVarNum);
EVALEXPR_API INT tsRemoveVariableM(INT nVarNum);

EVALEXPR_API INT tsAddExternLibrary(const TCHAR * szLibName);
EVALEXPR_API INT tsRemoveExternLibrary(const TCHAR * szLibName);
EVALEXPR_API INT tsRemoveAllExternLibrary();
EVALEXPR_API INT tsSetExtArgcNum(INT nArgc);
EVALEXPR_API INT tsGetExtArgcNum();

EVALEXPR_API INT tsIsContain(INT nReturn,INT nFlag);
EVALEXPR_API INT tsIsNumber(TCHAR ch);
EVALEXPR_API INT tsIsNumberPt(TCHAR ch);

/*
	OPERATORS PROC TOOLS
*/

EVALEXPR_API INT tsIsAOp(TCHAR ch);
EVALEXPR_API INT tsIsBOp(TCHAR ch);
EVALEXPR_API INT tsIsNBOp(TCHAR ch,TCHAR op);
EVALEXPR_API INT tsIs1stOp(TCHAR ch);
EVALEXPR_API INT tsIs2ndOp(TCHAR ch);

/*
	SHOW ABOUT DIALOG
*/

EVALEXPR_API INT tsShowAbout(INT nShow);
EVALEXPR_API INT tsShowMessage(HWND hWnd,INT nShow);

/*
	KERNEL CALC FUNCTIONS
*/

EVALEXPR_API INT tsStrFunc(const TCHAR * pfnFunc,tsDouble * x);
EVALEXPR_API INT tsStrFuncM(const TCHAR * pfnFunc,tsMatrix * x);
EVALEXPR_API INT tsStrOp(tsDouble * a,TCHAR op,tsDouble * b);
EVALEXPR_API INT tsStrOpM(tsMatrix * a,TCHAR op,tsMatrix * b);
EVALEXPR_API INT tsCallStrFunc(const TCHAR * pfnFunc,tsDouble * x,INT len,tsDouble * vValue);
EVALEXPR_API INT tsCallStrFuncM(const TCHAR * pfnFunc,tsMatrix * x,INT len,tsMatrix * vValue);
EVALEXPR_API INT tsCallStrOp(tsDouble * a,const TCHAR * op,tsDouble * b,tsDouble * vValue);
EVALEXPR_API INT tsCallStrOpM(tsMatrix * a,const TCHAR * op,tsMatrix * b,tsMatrix * vValue);

/*
	KERNEL TRANSLATE FUNCTIONS FOR tsShellEvalM
*/

EVALEXPR_API INT tsPopStackBuff(TCHAR * szBuff,INT * pnBuff,TCHAR * szExpr,INT * pnExpr);
EVALEXPR_API INT tsPreTransExpr(const TCHAR * szStr,TCHAR * szBuff);
EVALEXPR_API INT tsPreTransExprM(const TCHAR * szStr,TCHAR * szBuff);
EVALEXPR_API INT tsTransExpr(const TCHAR * szStr,TCHAR * szExpr);
EVALEXPR_API INT tsTransExprM(const TCHAR * szStr,TCHAR * szExpr);
EVALEXPR_API INT tsCalcExpr(const TCHAR * szExpr,tsDouble * vValue);
EVALEXPR_API INT tsCalcExprM(const TCHAR * szExpr,tsMatrix * vValue);
EVALEXPR_API INT tsCalcExprMul(const TCHAR * szExpr,tsDouble * vValue,tsDouble * pValues,INT * nValues);
EVALEXPR_API INT tsCalcExprMulM(const TCHAR * szExpr,tsMatrix * vValue,tsMatrix * pValues,INT * nValues);

/*
	SOME INTERFACE FOR USER
*/

EVALEXPR_API INT tsEvalExpr(const TCHAR * szStr,tsDouble * vValue);
EVALEXPR_API INT tsEvalExprM(const TCHAR * szStr,tsMatrix * vValue);
EVALEXPR_API INT tsEvalFile(const TCHAR * szFileName,tsDouble * vValue);
EVALEXPR_API INT tsEvalFileMul(const TCHAR * szFileName,tsDouble * vValue,tsDouble * pValues,INT * nValues);
EVALEXPR_API INT tsEvalFileM(const TCHAR * szFileName,tsMatrix * vValue);
EVALEXPR_API INT tsEvalFileMulM(const TCHAR * szFileName,tsMatrix * vValue,tsMatrix * pValues,INT * nValues);
EVALEXPR_API INT tsEvalExprMul(const TCHAR * szStr,tsDouble * vValue,tsDouble * pValues,INT * nValues);
EVALEXPR_API INT tsEvalExprMulM(const TCHAR * szStr,tsMatrix * vValue,tsMatrix * pValues,INT * nValues);

/*
THE FOLLOWING FUNCTION USED FOR REPLACE MatCom KERNEL
*/

EVALEXPR_API INT tsSizeofM();
EVALEXPR_API tsMatrix * tsAllocM(INT n);
EVALEXPR_API tsMatrix * tsFreeM(tsMatrix * mmV);
EVALEXPR_API INT tsNDimsM(tsMatrix * mmV);
EVALEXPR_API INT tsSizeM(tsMatrix * mmV,INT ind);
EVALEXPR_API tsDouble * tsAddRM(tsMatrix * mmV,INT m,INT n);
EVALEXPR_API tsDouble * tsAddIM(tsMatrix * mmV,INT m,INT n);
EVALEXPR_API tsMatrix * tsZerosM(INT m,INT n);
EVALEXPR_API tsMatrix * tsOnesM(INT m,INT n);
EVALEXPR_API tsMatrix * tsOnesIM(INT m,INT n);
EVALEXPR_API tsMatrix * tsDispM(tsMatrix * mmV);
EVALEXPR_API tsMatrix * tsAssignM(tsMatrix * mmV,tsMatrix * mmS);
EVALEXPR_API tsMatrix * tsAssignRM(tsMatrix * mmV,INT ind,VOID * szSrc,INT len);
EVALEXPR_API tsMatrix * tsAssignIM(tsMatrix * mmV,INT ind,VOID * szSrc,INT len);
EVALEXPR_API tsMatrix * tsTransposeM(tsMatrix * mmV);
EVALEXPR_API tsMatrix * tsReshapeM(tsMatrix * mmV,INT m,INT n);
EVALEXPR_API tsMatrix * tsRepMatM(tsMatrix * mmV,INT m,INT n);
EVALEXPR_API tsMatrix * tsStrcpyM(tsMatrix * mmV,TCHAR * szDst,INT * len);
EVALEXPR_API tsMatrix * tsStrM(const TCHAR * szStr);

/*
	RunDLL32.exe INTERFACE FUNCTIONS FOR USER
*/

EVALEXPR_API VOID tsEvalExpr_RunDLL(HINSTANCE,HINSTANCE,LPTSTR lpCmdLine,UINT);
EVALEXPR_API VOID tsTransExpr_RunDLL(HINSTANCE,HINSTANCE,LPTSTR lpCmdLine,UINT);
EVALEXPR_API VOID tsCalcExpr_RunDLL(HINSTANCE,HINSTANCE,LPTSTR lpCmdLine,UINT);
EVALEXPR_API VOID tsShowAbout_RunDLL(HINSTANCE,HINSTANCE,LPTSTR lpCmdLine,UINT);
EVALEXPR_API VOID tsEvalExprM_RunDLL(HINSTANCE,HINSTANCE,LPTSTR lpCmdLine,UINT);
EVALEXPR_API VOID tsTransExprM_RunDLL(HINSTANCE,HINSTANCE,LPTSTR lpCmdLine,UINT);
EVALEXPR_API VOID tsCalcExprM_RunDLL(HINSTANCE,HINSTANCE,LPTSTR lpCmdLine,UINT);

/*
	EXPORT TWO TEST FUNCTIONS
*/

EVALEXPR_API INT tsFTest(tsDouble * vBuff,INT * nExtNum);
EVALEXPR_API INT tsFTestM(tsMatrix * vBuff,INT * nExtNum);

EVALEXPR_API BOOL tsStrlike(LPCTSTR szData,LPCTSTR szMatch);
EVALEXPR_API LPCWSTR tsWcschr(LPCWSTR szStr,WCHAR ch);

EVALEXPR_API INT tsInputBox(HWND hWnd,LPTSTR szInputData,LPCTSTR szTitle,LPCTSTR szInfo,LPCTSTR szDefault);
EVALEXPR_API INT tsDecToRoman(INT nNum,LPTSTR szStr,UINT nLen);
EVALEXPR_API INT tsRomanToDec(LPCTSTR szStr);
EVALEXPR_API BOOL tsIsWholeWord(TCHAR cPrev,TCHAR cNext);
EVALEXPR_API size_t tsStrReplace(LPTSTR szDest,LPCTSTR szSource,size_t cbSize,LPCTSTR szFind,LPCTSTR szReplace,BOOL (*pfnNotiyReplace)(TCHAR,TCHAR));
EVALEXPR_API size_t tsStrReplaceMul(LPTSTR szDest,LPCTSTR szSource,size_t cbSize,LPCTSTR * szFind,LPCTSTR * szReplace,size_t numSize,BOOL (*pfnNotiyReplace)(TCHAR,TCHAR));

typedef BOOL (*ENUM_DISK_FILE_PROC)(LPCTSTR szPathFileName);
EVALEXPR_API ULONG tsEnumDiskFile(LPCTSTR szPathFile,ENUM_DISK_FILE_PROC fnEnumDiskFileProc);

#ifdef __cplusplus
}
#endif  //__cplusplus

/*
THE RETURN TAG OF MOST FUNCTION IS INT32 DATA TYPE
YOU CAN CHECK IT LIKE:

	INT nReturn = tsEvalExprM(strSource,(tsMatrix *)(vMatrix));
	if(ISCONTAIN(nReturn,ERROR_PARAMERR)){
		...
	}else if(...){
		...
	}

*/

//Eval Success == 0

#define EVAL_SUCCESS 0x00000000

//Warn Flag > 0

//NO MATCH
#define WARN_NOMATCH 0x00010001
//LOSE SYMBOL
#define WARN_LOSESYM 0x00020002
//PARAM ERROR
#define WARN_PARAMERR 0x00040004
//OTHER CHAR ERROR
#define WARN_OTHERERR 0x00080008

//EXTERN OPERATORS OR LOSE OPERATORS SYMBOL
#define WARN_EXTOPNUM 0x00100010
#define WARN_LOSTOPSYM 0x00100010
//CALL EXTERN FUNC
#define WARN_EXTFUNC 0x00200020

//Error Flag < 0

//PARAM ERROR
#define ERROR_PARAMERR 0x80408040
//CALL DLL ERROR OR NO FIND FUNCTION
#define ERROR_CALLDLLERR 0x80808080
//LOSE ONE OPERATOR SYMBOL
#define ERROR_NOOPNUM1 0x81008100
//LOSE TWO OPERATOR SYMBOLS
#define ERROR_NOOPNUM2 0x82008200
//UNKNOWN SYMBOL
#define ERROR_UNKNOWNSYM 0x84008400
//UNKNOWN FUNCTION
#define ERROR_UNKNOWNFUNC 0x88008800

//Some Useful Macro

#define ISERRORFLAG(nReturn) ((nReturn)&0x80008000)
#define DELERRORFLAG(nReturn) ((nReturn)&0x7fff7fff)
#define ISCONTAIN(nReturn,nFlag) \
(((nFlag)==EVAL_SUCCESS)?((nReturn)==EVAL_SUCCESS):(DELERRORFLAG(nReturn)&(nFlag)))


//Buildin Version

#define INFO_VERSION 0x3206

#ifdef __cplusplus
extern "C" {
#endif  //__cplusplus

/*
	SOME USEFUL DATA VALUE CALC FUNCTIONS
*/

EVALEXPR_API tsDouble linefit(tsDouble * x,tsDouble * y,INT size,tsDouble * a,tsDouble * b);
EVALEXPR_API tsDouble integral(tsDouble (* f)(tsDouble),tsDouble a,tsDouble b,tsDouble tol,LONG n);
EVALEXPR_API tsDouble limit(tsDouble (* f)(tsDouble),tsDouble a,tsDouble b,tsDouble tol,LONG n);
EVALEXPR_API tsDouble diff(tsDouble (* f)(tsDouble),tsDouble a,tsDouble b,tsDouble tol,LONG n);

/*
	SOME IMPORTANT CUI PLOT FUNCTIONS
*/
EVALEXPR_API tsDouble plot(tsDouble * x,INT n,TCHAR c,TCHAR fc);
EVALEXPR_API tsDouble subplot(tsDouble * x,tsDouble * y,INT n,TCHAR xc,TCHAR yc,TCHAR fc);
EVALEXPR_API tsDouble plotxy(tsDouble * x,tsDouble * y,INT n,TCHAR xc,TCHAR yc,TCHAR fc);
EVALEXPR_API tsDouble plotyy(tsDouble * x,tsDouble * y,INT n,TCHAR xc,TCHAR yc,TCHAR fc);
EVALEXPR_API tsDouble fplot(tsDouble (* f)(tsDouble),tsDouble a,tsDouble b,INT n,TCHAR c,TCHAR fc);
EVALEXPR_API tsDouble fplotxy(tsDouble (* f1)(tsDouble),tsDouble a1,tsDouble b1,tsDouble (* f2)(tsDouble),tsDouble a2,tsDouble b2,INT n,TCHAR c1,TCHAR c2,TCHAR fc);
EVALEXPR_API tsDouble fplotyy(tsDouble (* f1)(tsDouble),tsDouble a1,tsDouble b1,tsDouble (* f2)(tsDouble),tsDouble a2,tsDouble b2,INT n,TCHAR c1,TCHAR c2,TCHAR fc);
EVALEXPR_API tsDouble fsubplot(tsDouble (* f1)(tsDouble),tsDouble a1,tsDouble b1,tsDouble (* f2)(tsDouble),tsDouble a2,tsDouble b2,INT n,TCHAR c1,TCHAR c2,TCHAR fc);
EVALEXPR_API tsDouble hplot(tsDouble * x,INT n,TCHAR c,TCHAR fc);
EVALEXPR_API tsDouble fhplot(tsDouble (* f)(tsDouble),tsDouble a,tsDouble b,INT n,TCHAR c,TCHAR fc);
EVALEXPR_API tsDouble hplotxy(tsDouble * x,tsDouble * y,INT n,TCHAR xc,TCHAR yc,TCHAR fc);
EVALEXPR_API tsDouble fhplotxy(tsDouble (* f1)(tsDouble),tsDouble a1,tsDouble b1,tsDouble (* f2)(tsDouble),tsDouble a2,tsDouble b2,INT n,TCHAR c1,TCHAR c2,TCHAR fc);
EVALEXPR_API tsDouble hplotyy(tsDouble * x,tsDouble * y,INT n,TCHAR xc,TCHAR yc,TCHAR fc);
EVALEXPR_API tsDouble fhplotyy(tsDouble (* f1)(tsDouble),tsDouble a1,tsDouble b1,tsDouble (* f2)(tsDouble),tsDouble a2,tsDouble b2,INT n,TCHAR c1,TCHAR c2,TCHAR fc);

#ifdef __cplusplus
}
#endif  //__cplusplus

//DATA STRUCT HEAD FILE

//YOU MAY CHANGE THE MACRO BELLOW IF NESSARY
//INT32 CAN ALSO STORE ANY VAR POINTER

typedef INT ElemType;

//IF ElemType DONOT SURPORT THE FOLLOWING OPERATORS
//SUCH AS:
//    <  >  ==  <=  >=  =
//YOU NEED TO OVERLOAD IT IF NESSARY

//DONOT CHANGE THE FOLLOWING PROGRAM IN ANYCASE

typedef struct BinNode{
       ElemType data;
       BinNode * lchild,* rchild;   
}*BinTree;

typedef struct QueueNode{
       ElemType * szBuff;
       INT nLength;
       INT front,rear;        
}*Queue;

typedef struct StackNode{
       ElemType * szBuff;
       INT nLength;
       INT top; 
}*Stack;

typedef VOID (* VISIT_PROC)(VOID *);

typedef INT (* COMPARE_PROC)(ElemType *,ElemType *);

#define NORMAL_COMP_SORT ((COMPARE_PROC)(0L))
#define REVERSE_COMP_SORT ((COMPARE_PROC)(-1L))
#define INT32PTR_COMP_SORT (tsINT32PTR_COMPARE_SORT)
#define INT16PTR_COMP_SORT (tsINT16PTR_COMPARE_SORT)
#define INT8PTR_COMP_SORT (tsINT8PTR_COMPARE_SORT)
#define FLOATPTR_COMP_SORT (tsFLOATPTR_COMPARE_SORT)
#define DOUBLEPTR_COMP_SORT (tsDOUBLEPTR_COMPARE_SORT)

typedef struct SqNode{
        ElemType data;
        SqNode * head,* tail;        
}*SqList;

typedef struct STNode{
        ElemType * data;
        INT nLength;        
}*SqTable;

#ifdef __cplusplus
extern "C" {
#endif  //__cplusplus

/*
	Queue OPERATOR FUNCTIONS	
*/

EVALEXPR_API Queue tsCreateQueue(INT nLength);
EVALEXPR_API VOID tsDestroyQueue(Queue qp);
EVALEXPR_API INT tsEmptyQueue(Queue qp);
EVALEXPR_API INT tsFullQueue(Queue qp);
EVALEXPR_API VOID tsEnQueue(Queue qp,ElemType data);
EVALEXPR_API VOID tsDeQueue(Queue qp,ElemType * data);

/*
	Stack OPERATOR FUNCTIONS
*/

EVALEXPR_API Stack tsCreateStack(INT nLength);
EVALEXPR_API VOID tsDestroyStack(Stack sp);
EVALEXPR_API INT tsEmptyStack(Stack sp);
EVALEXPR_API INT tsFullStack(Stack sp);
EVALEXPR_API VOID tsPushStack(Stack sp,ElemType data);
EVALEXPR_API VOID tsPopStack(Stack sp,ElemType * data);

/*
	BinTree OPERATOR FUNCTIONS
*/

EVALEXPR_API BinTree tsCreateBinTree(ElemType data);
EVALEXPR_API VOID tsDestroyBinTree(BinTree tp);
EVALEXPR_API INT tsHeightBinTree(BinTree tp);
EVALEXPR_API VOID tsFrontTravBinTree(BinTree tp,VISIT_PROC visit);
EVALEXPR_API VOID tsMiddleTravBinTree(BinTree tp,VISIT_PROC visit);
EVALEXPR_API VOID tsRearTravBinTree(BinTree tp,VISIT_PROC visit);
EVALEXPR_API INT tsNumberBinTree(BinTree tp);
EVALEXPR_API VOID tsIndexTravBinTree(BinTree tp,VISIT_PROC visit);
EVALEXPR_API BinTree tsIndexOfBinTree(BinTree tp,INT index);

/*
	Quick Sort Kernel
*/

EVALEXPR_API VOID tsQuickSortArrayKernel(ElemType * data,INT a,INT b,COMPARE_PROC comp);
EVALEXPR_API VOID tsQuickSortArray(ElemType * data,INT n,COMPARE_PROC comp);
EVALEXPR_API VOID tsPrintData(VOID * ptr);

EVALEXPR_API INT tsINT32PTR_COMPARE_SORT(ElemType * a,ElemType * b);
EVALEXPR_API INT tsINT16PTR_COMPARE_SORT(ElemType * a,ElemType * b);
EVALEXPR_API INT tsINT8PTR_COMPARE_SORT(ElemType * a,ElemType * b);
EVALEXPR_API INT tsFLOATPTR_COMPARE_SORT(ElemType * a,ElemType * b);
EVALEXPR_API INT tsDOUBLEPTR_COMPARE_SORT(ElemType * a,ElemType * b);

/*
	MEMORY ALLOC AND FREE
*/

EVALEXPR_API VOID * tsAllocMemory(size_t size);
EVALEXPR_API VOID * tsReAllocMemory(VOID * buf,size_t size);
EVALEXPR_API VOID tsFreeMemory(VOID * buf);

/*
	SqList OPERATOR FUNCTIONS
*/

EVALEXPR_API SqList tsCreateSqList(ElemType data);
EVALEXPR_API VOID tsDestroySqList(SqList lp);
EVALEXPR_API VOID tsAppendSqList(SqList lp,ElemType data);
EVALEXPR_API SqList tsMergeSqList(SqList lp1,SqList lp2);
EVALEXPR_API SqList tsIndexOfSqList(SqList lp,INT index);
EVALEXPR_API VOID tsInsertSqList(SqList lp,INT index,ElemType data);
EVALEXPR_API VOID tsTailTravSqList(SqList lp,VISIT_PROC visit);
EVALEXPR_API VOID tsHeadTravSqList(SqList lp,VISIT_PROC visit);
EVALEXPR_API INT tsNumberSqList(SqList lp);
EVALEXPR_API VOID tsQuickSortSqListKernel(SqList data_a,SqList data_b,COMPARE_PROC comp);
EVALEXPR_API VOID tsQuickSortSqList(SqList lp,COMPARE_PROC comp);

#ifdef __cplusplus
}
#endif  //__cplusplus

//DEFINE SOME USEFUL CLASSES FOR C++ COMPILERS

#ifdef __cplusplus

typedef class CBinTree{
public:
       BinTree vBinTreePtr;
public:
       CBinTree(){vBinTreePtr=tsCreateBinTree((ElemType)(0L));}
       CBinTree(ElemType data){vBinTreePtr=tsCreateBinTree(data);}
       virtual ~CBinTree(){tsDestroyBinTree(vBinTreePtr);}  
}TBinTree;

typedef class CQueue{
public:
       Queue vQueuePtr;
public:
       CQueue(){vQueuePtr=tsCreateQueue(256);}
       CQueue(INT nLength){vQueuePtr=tsCreateQueue(nLength);}
       virtual ~CQueue(){tsDestroyQueue(vQueuePtr);}  
}TQueue;

typedef class CStack{
public:
       Stack vStackPtr;
public:
       CStack(){vStackPtr=tsCreateStack(256);}
       CStack(INT nLength){vStackPtr=tsCreateStack(nLength);}
       virtual ~CStack(){tsDestroyStack(vStackPtr);}  
}TStack;

typedef class CSqList{
public:
       SqList vSqListPtr;
public:
       CSqList(){vSqListPtr=tsCreateSqList((ElemType)(0L));}
       CSqList(ElemType data){vSqListPtr=tsCreateSqList(data);}
       virtual ~CSqList(){tsDestroySqList(vSqListPtr);}  
}TSqList;

#endif  //__cplusplus

#endif  //EVAL32_H
