
// MFCcomDlg.h: 头文件
//

#pragma once
#include "mscomm.h"
#include   "CMyNewDlg.h "
// CMFCcomDlg 对话框
class CMFCcomDlg : public CDialogEx
{
// 构造
public:
	CMFCcomDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCCOM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int m_iComNum;
	int m_iRecvBytes;       //已经接收的字节数
	int m_iSendBytes;       //已经发送的字节数  
	CString m_strComBBB;	//波特率
	CString m_strComP;      //奇偶校验位
	CString m_strComD;      //数据位数
	CString m_strComS;      //停止位

	CComboBox m_Combo;
	CString m_EditSend;
	char*    cm_EditSend;
	CString m_EditRecive;

	CMscomm m_cmsCom;
	DECLARE_EVENTSINK_MAP()
	void OnCommMscomm1();
	afx_msg void OnBnClickedButtonOpen();
	afx_msg void OnBnClickedButtonSend();
	CComboBox m_Baud;
	afx_msg void OnCbnSelchangeBort();
	afx_msg void OnBnClickedButtonClean();
	afx_msg void OnBnClickedBottonClose();
	afx_msg void OnCbnSelchangeCombo2();
	BOOL   HEX=1;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
};
