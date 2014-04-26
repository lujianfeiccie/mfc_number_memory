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
	// 显示图像的控件
	CStatic* m_picbox_pic;
	// 显示当前图像的名称
	CStatic* m_txt_image_name;
	 CRect rect;

	 CDialogEx *dialog;
};

