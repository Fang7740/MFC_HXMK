// CMFC_UARTDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCcom.h"
#include "CMFC_UARTDlg.h"
#include "afxdialogex.h"


// CMFC_UARTDlg 对话框

IMPLEMENT_DYNAMIC(CMFC_UARTDlg, CDialog)

CMFC_UARTDlg::CMFC_UARTDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_MFCCOM_DIALOG, pParent)
{

}

CMFC_UARTDlg::~CMFC_UARTDlg()
{
}

void CMFC_UARTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMFC_UARTDlg, CDialog)
END_MESSAGE_MAP()


// CMFC_UARTDlg 消息处理程序
