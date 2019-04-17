#pragma once


// CMFC_UARTDlg 对话框

class CMFC_UARTDlg : public CDialog
{
	DECLARE_DYNAMIC(CMFC_UARTDlg)

public:
	CMFC_UARTDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CMFC_UARTDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCCOM_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
