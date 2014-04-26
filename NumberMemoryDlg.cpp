
// NumberMemoryDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "NumberMemory.h"
#include "NumberMemoryDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CNumberMemoryDlg �Ի���




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


// CNumberMemoryDlg ��Ϣ�������

BOOL CNumberMemoryDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	//����Ϊ����ӵļ���ͼƬ�Ĵ���
    
	 
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
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CNumberMemoryDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
		CDialog::UpdateWindow(); //����windows���ڣ�������ⲽ���ã�ͼƬ��ʾ�����������
		if(m_imagePlayer!=NULL){
		m_imagePlayer->updateImage();     //�ػ�ͼƬ����
		}
		Util::LOG("OnPaint");
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
