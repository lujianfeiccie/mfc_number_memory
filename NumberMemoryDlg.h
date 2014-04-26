
// NumberMemoryDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "ImagePlayer.h"

// CNumberMemoryDlg 对话框
class CNumberMemoryDlg : public CDialogEx
{
// 构造
public:
	
	CNumberMemoryDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_NUMBERMEMORY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnGo();
	
	// 显示图像的控件
	CStatic m_picbox_pic;
	// 定位到图片代表的数字
	CEdit m_edit_pos;
	// 显示当前的数字
	CStatic m_txt_num;
	// 显示当前图像的名称
	CStatic m_txt_image_name;

	ImagePlayer *m_imagePlayer;
	afx_msg void OnBnBackward();

	void Show_picture();
	afx_msg void OnBnForward();
};
