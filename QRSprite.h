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

class CC_DLL QRSprite : public cocos2d::Sprite {  
    
private:
    
    QRSprite();
    ~QRSprite();
    
    void loadShaderVertex(const char *vert, const char *frag);
public:
    
    bool initWithString(const std::string& code,int size = 128);
    
    //tolua_begin
    static QRSprite* create(const std::string& code,int size = 128);
};
//tolua_end

#endif /* QRSprite_hpp */
