#include "StdAfx.h"
#include "ImagePlayer.h"


ImagePlayer::ImagePlayer(CStatic* m_picbox_pic,CStatic* m_txt_image_name,CDialogEx *dialog)
{	
	 this->pos = 0;
	 this->m_picbox_pic = m_picbox_pic;
	 this->m_txt_image_name = m_txt_image_name;
	 this->dialog = dialog;
	 m_picbox_pic->GetClientRect(&rect);     //m_picture为Picture Control控件变量，获得控件的区域对象
}
ImagePlayer::ImagePlayer(CStatic* m_picbox_pic)
{
	ImagePlayer(m_picbox_pic,NULL,NULL);
}
ImagePlayer::ImagePlayer(void)
{
	ImagePlayer(NULL);
}


ImagePlayer::~ImagePlayer(void)
{
}

bool ImagePlayer::forward()
{
	if((pos+1)<=100)
	{
		++pos;
		return true;
	}
	else
	{
		return false;
	}
}
bool ImagePlayer::backward()
{
	if((pos-1)>=0)
	{
		--pos;
		return true;
	}
	else
	{
		return false;
	}
}

void ImagePlayer::updateImage()
{
	//if(m_picbox_pic==NULL) return;
	CImage image;       //使用图片类
	CString filename;
	filename.Format("images\\%d.jpg",pos);
	image.Load(filename);   //装载路径下图片信息到图片类
	CDC* pDC = m_picbox_pic->GetWindowDC();    //获得显示控件的DC
	image.Draw( pDC -> m_hDC,rect.left,rect.top);      //图片类的图片绘制Draw函数		
	dialog->ReleaseDC(pDC);
}
bool ImagePlayer::seekTo(int pos)
{
	if(pos<0 || pos>100)
	{
		return false;
	}
	else
	{
		this->pos = pos;
		return true;
	}
}
void ImagePlayer::play()
{
	CString filename;
	filename.Format("sounds\\%d.wav",pos);
	PlaySound(filename,NULL,SND_FILENAME | SND_ASYNC);
	if(dialog!=NULL)
	{
		dialog->Invalidate();
	//	updateImage();
	}
}