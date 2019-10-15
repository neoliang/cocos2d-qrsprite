//
//  QRSprite.cpp
//  CGame
//
//  Created by neo on 15/12/16.
//
//

#include "QRSprite.h"
#include "libqrencode/qrencode.h"
#include "libqrencode/qrspec.h"

using namespace cocos2d;

bool QRSprite::initWithString(const std::string& code,int size)
{
	bool flag = false;
    QRcode* _qrcode = QRcode_encodeString(code.c_str(), 0, QR_ECLEVEL_H, QR_MODE_8, 1);
    if (_qrcode != nullptr) {
		int width = _qrcode->width;
		unsigned char* imageData = new unsigned char[width * width*4];
		memset(imageData, 255, width*width*4);  //默认为白色

		Texture2D* texture = new (std::nothrow) Texture2D();
        for (int i =0; i<_qrcode->width; ++i) {
            for (int j = 0; j<_qrcode->width; ++j) {
               if( (_qrcode->data[i * _qrcode->width +j] & 1) == 1)
               {
				   imageData[i * _qrcode->width * 4 + j * 4] = 0;     //r
                   imageData[i * _qrcode->width * 4 + j * 4 + 1] = 0; //g
                   imageData[i * _qrcode->width * 4 + j * 4 + 2] = 0; //b
               }
            }
        }
		texture->setAliasTexParameters();  //关闭抗锯齿，防止缩放后线条粘连
		Size s = Size(width, width);

		//使用RGBA8888格式以支持截图png
		texture->initWithData(imageData, width * width, Texture2D::PixelFormat::RGBA8888, width, width, s);
		flag = initWithTexture(texture);

		setScale(size / width);
        QRcode_free(_qrcode);
    }
    return flag;
}


QRSprite* QRSprite::create(const std::string& code,int size)
{
    QRSprite* s = new QRSprite;
    s->autorelease();
    if(s->initWithString(code,size))
    {
        return s;
    }
    return nullptr;
}

QRSprite::QRSprite()
{
}
QRSprite::~QRSprite()
{
}
