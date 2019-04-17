
// MFCcomDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCcom.h"
#include "MFCcomDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCcomDlg 对话框



CMFCcomDlg::CMFCcomDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCCOM_DIALOG, pParent)
	, m_EditSend(_T(""))
	, m_EditRecive(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCcomDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO2, m_Combo);
	DDX_Text(pDX, IDC_EDIT1, m_EditSend);
	DDX_Text(pDX, IDC_EDIT2, m_EditRecive);
	DDX_Control(pDX, IDC_MSCOMM1, m_cmsCom);
	DDX_Control(pDX, IDC_BORT, m_Baud);

}

BEGIN_MESSAGE_MAP(CMFCcomDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_OPEN, &CMFCcomDlg::OnBnClickedButtonOpen)
	ON_BN_CLICKED(IDC_BUTTON_SEND, &CMFCcomDlg::OnBnClickedButtonSend)
	ON_CBN_SELCHANGE(IDC_BORT, &CMFCcomDlg::OnCbnSelchangeBort)
	ON_BN_CLICKED(IDC_BUTTON_CLEAN, &CMFCcomDlg::OnBnClickedButtonClean)
	ON_BN_CLICKED(IDC_BOTTON_CLOSE, &CMFCcomDlg::OnBnClickedBottonClose)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CMFCcomDlg::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDC_RADIO1, &CMFCcomDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMFCcomDlg::OnBnClickedRadio2)
END_MESSAGE_MAP()


// CMFCcomDlg 消息处理程序

BOOL CMFCcomDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码



		CButton* radio = (CButton*)GetDlgItem(IDC_RADIO2);
		radio->SetCheck(1);
		m_Combo.AddString(_T("COM1"));
		m_Combo.AddString(_T("COM2"));
		m_Combo.AddString(_T("COM3"));
		m_Combo.AddString(_T("COM4"));
		m_Combo.AddString(_T("COM5"));
		m_Combo.AddString(_T("COM6"));
		m_Combo.AddString(_T("COM7"));
		m_Combo.AddString(_T("COM8"));
		m_Combo.AddString(_T("COM9"));
		m_Combo.SetCurSel(2);//初始时下拉列表为COM1
		m_Baud.AddString(_T("1200"));
		m_Baud.AddString(_T("4800"));
		m_Baud.AddString(_T("9600"));
		m_Baud.AddString(_T("19200"));
		m_Baud.AddString(_T("115200"));
		m_Baud.SetCurSel(4);//初始时下拉列表为COM1
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCcomDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCcomDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCcomDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BEGIN_EVENTSINK_MAP(CMFCcomDlg, CDialogEx)
	ON_EVENT(CMFCcomDlg, IDC_MSCOMM1, 1, CMFCcomDlg::OnCommMscomm1, VTS_NONE)
END_EVENTSINK_MAP()


void CMFCcomDlg::OnCommMscomm1()
{
	// TODO: 在此处添加消息处理程序代码
	VARIANT variant_inp; //Variant 是一种特殊的数据类型，除了定长String数据及用户定义类型外，可以包含任何种类的数据。
	COleSafeArray safearray_inp;
	LONG len, k;
	BYTE bt;
	BYTE rxdata[2048]; //设置BYTE数组 An 8-bit integer that is not signed.
	CString strtemp;
	if (m_cmsCom.get_CommEvent() == 2) //事件值为2表示接收缓冲区内有字符
	{
		////////以下你可以根据自己的通信协议加入处理代码
		variant_inp = m_cmsCom.get_Input();	//读缓冲区
		safearray_inp = variant_inp;	//VARIANT型变量转换为ColeSafeArray型变量
		len = safearray_inp.GetOneDimSize();	//得到有效数据长度
		for (k = 0; k < len; k++)
			safearray_inp.GetElement(&k, rxdata + k);//转换为BYTE型数组
		for (k = 0; k < len; k++) //将数组转换为Cstring型变量
		{
			bt = *(char*)(rxdata + k);//字符型
			if(HEX==0)
			{ 
			 strtemp.Format(_T("%x"), bt); //将字符送入临时变量strtemp存放
			}
			else
			{
			 strtemp.Format(_T("%c"), bt); //将字符送入临时变量strtemp存放
			}
			m_EditRecive += strtemp; //加入接收编辑框对应字符串
		}
	
	}
	UpdateData(FALSE); //更新编辑框内容
}


void CMFCcomDlg::OnBnClickedButtonOpen()    //打开串口
{
	// TODO: 在此添加控件通知处理程序代码
	m_iComNum=m_Combo.GetCurSel();//获取编辑框中的串口编号
	m_cmsCom.put_CommPort(m_iComNum+1);
	m_cmsCom.put_PortOpen(TRUE);		//打开串口
	m_cmsCom.put_RThreshold(1);			//收到1个字节引发OnComm事件	
	m_cmsCom.put_InputMode(1);			//输入模式选为二进制
	m_strComP= TEXT("n");; m_strComD = TEXT("8"); m_strComS = TEXT("1");
	CString s;
	s.Format(TEXT("%s,%s,%s,%s"), m_strComBBB, m_strComP, m_strComD, m_strComS);
	m_cmsCom.put_Settings(s);			//设置串口参数，波特率，无奇偶校验，位停止位，位数据位    
	m_cmsCom.put_InputLen(0);			//设置当前接收区数据长度为默认值 
	m_cmsCom.get_Input();				//先预读缓冲区以清除残留数据  
	//SetTimer(1, 500, 0);   //定时更新接收/发送的字节数
}


void CMFCcomDlg::OnBnClickedButtonSend()    //发送按键
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE); //读取编辑框内容
	//cm_EditSend=m_EditSend;
	m_cmsCom.put_Output(COleVariant(m_EditSend)); //发送数据
}




void CMFCcomDlg::OnCbnSelchangeBort()   ///选择波特率
{
	// TODO: 在此添加控件通知处理程序代码
	m_Baud.GetLBText(m_Baud.GetCurSel(), m_strComBBB);
}


void CMFCcomDlg::OnBnClickedButtonClean()  ///清除接收
{
	// TODO: 在此添加控件通知处理程序代码
	m_EditRecive = (_T(""));
	GetDlgItem(IDC_EDIT2)->SetWindowText(_T(""));  

}


void CMFCcomDlg::OnBnClickedBottonClose()
{
	// TODO: 在此添加控件通知处理程序代码
	CMyNewDlg  Dlg;
	Dlg.DoModal();
}


void CMFCcomDlg::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
}




void CMFCcomDlg::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
	HEX = 0;
}


void CMFCcomDlg::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
	HEX = 1;
}
