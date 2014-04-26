
// NumberMemoryDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "NumberMemory.h"
#include "NumberMemoryDlg.h"
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
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CNumberMemoryDlg 对话框




CNumberMemoryDlg::CNumberMemoryDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNumberMemoryDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_imagePlayer = NULL;
}

void CNumberMemoryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_STATIC_PIC, m_picbox_pic);
	DDX_Control(pDX, IDC_EDIT1, m_edit_pos);
	DDX_Control(pDX, IDC_STATIC_NUM, m_txt_num);
	DDX_Control(pDX, IDC_STATIC_IMAGE, m_txt_image_name);
}

BEGIN_MESSAGE_MAP(CNumberMemoryDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CNumberMemoryDlg::OnBnBackward)
	ON_BN_CLICKED(IDC_BTN_GO, &CNumberMemoryDlg::OnBnClickedBtnGo)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDCANCEL, &CNumberMemoryDlg::OnBnForward)
END_MESSAGE_MAP()


// CNumberMemoryDlg 消息处理程序

BOOL CNumberMemoryDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	//下面为新添加的加载图片的代码
    
	 
	 SetWindowPos(&wndTop,0,0,GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN),SWP_SHOWWINDOW);
	 CRect rect;
	 m_picbox_pic.GetWindowRect(&rect);
	 //m_picbox_pic.ScreenToClient(&rect);
	 rect.right = GetSystemMetrics(SM_CXSCREEN)-rect.left;
	 rect.bottom = GetSystemMetrics(SM_CYSCREEN);
	 rect.top -= 30;
	 m_picbox_pic.MoveWindow(rect);	 
	 
	 m_imagePlayer = new ImagePlayer(&m_picbox_pic,&m_txt_image_name,this);
	 m_imagePlayer->play();
	 Util::LOG("OnInitDialog %d %d ",rect.left,rect.top);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CNumberMemoryDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CNumberMemoryDlg::OnPaint()
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
		CDialog::UpdateWindow(); //更新windows窗口，如果无这步调用，图片显示还会出现问题
		if(m_imagePlayer!=NULL){
		m_imagePlayer->updateImage();     //重绘图片函数
		}
		Util::LOG("OnPaint");
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CNumberMemoryDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CNumberMemoryDlg::OnBnBackward()
{
	m_imagePlayer->backward();
	m_imagePlayer->play();
}

void CNumberMemoryDlg::OnClose()
{
	CDialog::OnClose();
	if(m_imagePlayer!=NULL)
	{
		delete m_imagePlayer;
		m_imagePlayer = NULL;
	}
}

void CNumberMemoryDlg::OnBnClickedBtnGo()
{
	CString num;
	m_edit_pos.GetWindowTextA(num);
	int pos = atoi(num);
	m_imagePlayer->seekTo(pos);
	m_imagePlayer->play();
}


void CNumberMemoryDlg::OnBnForward()
{
	m_imagePlayer->forward();
	m_imagePlayer->play();
}
