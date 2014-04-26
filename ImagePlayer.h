#pragma once
class ImagePlayer
{
public:
	
	ImagePlayer(CStatic* m_picbox_pic,CStatic* m_txt_image_name,CDialogEx *dialog);
	ImagePlayer(CStatic* m_picbox_pic);
	ImagePlayer(void);
	~ImagePlayer(void);
	bool forward();
	bool backward();
	bool seekTo(int pos);
	void updateImage();
	void play();
private:
	int pos;
	// ��ʾͼ��Ŀؼ�
	CStatic* m_picbox_pic;
	// ��ʾ��ǰͼ�������
	CStatic* m_txt_image_name;
	 CRect rect;

	 CDialogEx *dialog;
};

