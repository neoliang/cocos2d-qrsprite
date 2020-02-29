# cocos2d-qrsprite
在cocos2d-x中绘制二维码, QRSprite继承自Sprite,二维码大小自动适应文本长度和容错率，通过缩放来得到期望尺寸的二维码


## example
on cocos2d v3.x

```cpp
Scene* scene = Scene::create();
QRSprite* qr = QRSprite::create("hello world", 128);
scene->addChild(qr);
```
