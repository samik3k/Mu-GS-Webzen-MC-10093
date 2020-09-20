//*---------------------------------------------------------------
// << CCallStackTrace CLASS >>
// BUILT BY H.J.I.
//
// FILE : CallStackTrace.H
// DESC : ȣ�⽺�� ��� Ŭ���� (�������Ͽ� �ݵ�� .pdb (�ɺ�����) ÷�� �ʿ�. ������ �����Ͱ� ��������)
// INIT BUILT DATE : 2004. 09. 16
// LAST BUILT DATE : 2004. 09. 16
//
//*---------------------------------------------------------------

#pragma warning (disable : 4786)

#ifndef _CALLSTACKTRACE_H_
#define _CALLSTACKTRACE_H_

#include <WINDOWS.H>			// MFC �϶��� stdafx.h
#include <STRING>

#define DEF_LOG_FILE_NAME		"LOGDATA"
#define DEF_LOG_DIRECTORY_NAME	"LOG"

using namespace std;


///////////////////////////////////////////////////////////////////
//	DECLARATION
///////////////////////////////////////////////////////////////////


//*---------------------------------------------------------------
// TYPE : CLASS
// NAME : CCallStackTrace
//*---------------------------------------------------------------
// DESC : ȣ�⽺�� ��� Ŭ����
// PROGRAMMER : H.J.I.
//*---------------------------------------------------------------
class CCallStackTrace
{
public:
	CCallStackTrace							(
		char szLogID [MAX_PATH],			// �� ��ü�� �ĺ��� ����� ���� ID (�ݵ�� �ʿ�)
		char szLogFileName [MAX_PATH] = DEF_LOG_FILE_NAME,				// �α����� �̸� 
		char szLogDirectoryName [MAX_PATH] = DEF_LOG_DIRECTORY_NAME		// �α����� ���丮 �̸�
		);
	virtual ~CCallStackTrace();

	int		SaveCallStack					(BOOL bWriteInFile = TRUE);
	char *	GetCallStackLogBuffer			()	{	return &m_strCallStackLog[0]; }		// ���� ���ϱ���� ������ ��� �α׹��� �����͸� �ٷ� ������

private:
	VOID	Output							();
	int		TraceStack						(BOOL bWriteInFile = TRUE);
	DWORD	ConvertAddress					(HANDLE hProcess, DWORD address, char* output_buffer);
	static DWORD __stdcall GetModuleBase	(HANDLE hProcess, DWORD address);

private:
	FILE *				m_fLogFile;
	char				m_szLogID				[MAX_PATH];
	char				m_szLogFileName			[MAX_PATH];
	char				m_szLogDirectoryName	[MAX_PATH];

	char				m_szCallFuncName		[MAX_PATH];		// TraceStack() �� ȣ���� �Լ���

	CRITICAL_SECTION	m_critLogToFile;

	string				m_strCallStackLog;
};


#endif
