// CMyNewDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCcom.h"
#include "CMyNewDlg.h"
#include "afxdialogex.h"


// CMyNewDlg 对话框

IMPLEMENT_DYNAMIC(CMyNewDlg, CDialogEx)

CMyNewDlg::CMyNewDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
	
}

CMyNewDlg::~CMyNewDlg()
{
}

void CMyNewDlg::DoDataExchange(CDataExchange* pDX)
{

	CDialogEx::DoDataExchange(pDX);
	
}


BEGIN_MESSAGE_MAP(CMyNewDlg, CDialogEx)
END_MESSAGE_MAP()


// CMyNewDlg 消息处理程序
