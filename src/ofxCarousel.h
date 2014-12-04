#pragma once
#include "ofMain.h"

enum ofxCarouselMode {
    ofxCarouselModeWrap,
    ofxCarouselModeStop
};

class ofxCarousel {

public:
    ofxCarouselMode mode;
    
    float length;
    float position;
    float velocity;
    float friction;
    float bounce;
    float elastic;
    
    float pagingSize;

    ofxCarousel();
    
    void grab(float reference);
    void drag(float reference);
    
    void move(float target, float duration);
    void drop();
    void drop(float velocity);
    void update();
    
    float positionForTile(int tile, int numberOfTiles, float tileSize, int* index = 0);

private:
    float stretched;
    
    float grabReference;
    
    float moveTarget;
    float moveOffset;

    float animateTime;
    float animateDuration;
    float animateBegin;
    float animateDelta;

    int updateState;

    void updateMove();
    void updateAnimate();
    void updateDecelerate();
};