//
//  QRSprite.hpp
//  CGame
//
//  Created by neo on 15/12/16.
//
//

#ifndef QRSprite_hpp
#define QRSprite_hpp

#include "cocos2d.h"

class QRSprite : public cocos2d::CCLayerColor{//tolua_export
    
    
private:
    cocos2d::CCTexture2D* _texture;
    struct {cocos2d::ccTex2F a;cocos2d::ccTex2F b;cocos2d::ccTex2F c;cocos2d::ccTex2F d; } _texCoord;
    virtual void draw();
    
    QRSprite();
    ~QRSprite();
    
    void listenBackToForeground(cocos2d::CCObject *obj);
    void loadShaderVertex(const char *vert, const char *frag);
public:
    
    bool initWithString(const std::string& code,int size = 128);
    
    //tolua_begin
    static QRSprite* create(const std::string& code,int size = 128);
};
//tolua_end

#endif /* QRSprite_hpp */
