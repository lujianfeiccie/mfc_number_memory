
// NumberMemoryDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "ImagePlayer.h"

// CNumberMemoryDlg �Ի���
class CNumberMemoryDlg : public CDialogEx
{
// ����
public:
	
	CNumberMemoryDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_NUMBERMEMORY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnGo();
	
	// ��ʾͼ��Ŀؼ�
	CStatic m_picbox_pic;
	// ��λ��ͼƬ���������
	CEdit m_edit_pos;
	// ��ʾ��ǰ������
	CStatic m_txt_num;
	// ��ʾ��ǰͼ�������
	CStatic m_txt_image_name;

	ImagePlayer *m_imagePlayer;
	afx_msg void OnBnBackward();

	void Show_picture();
	afx_msg void OnBnForward();
};
