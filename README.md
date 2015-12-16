# cocos2d-qrsprite
在cocos2d-x中绘制二维码


#example
on cocos2d v2.x

CCScene* scene = CCScene::create();
QRSprite* qr = QRSprite::create("hello world");
scene->addChild(qr);
