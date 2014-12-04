#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    
    images.push_back(new ofImage("flower1.jpg"));
    images.push_back(new ofImage("flower2.jpg"));
    images.push_back(new ofImage("flower3.jpg"));
    images.push_back(new ofImage("flower4.jpg"));
    images.push_back(new ofImage("flower5.jpg"));
    images.push_back(new ofImage("flower6.jpg"));
    images.push_back(new ofImage("flower7.jpg"));
    
    
    carousel.pagingSize = carousel.length / images.size();
}

//--------------------------------------------------------------
void ofApp::update(){
    carousel.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofPushMatrix();
    
    ofTranslate(ofGetWindowWidth() * 0.5, ofGetWindowHeight() * 0.5);
    
    float radius = 600.0;
    
    ofTranslate(0, 0, -radius);
    
    ofEnableDepthTest();
    ofEnableNormalizedTexCoords();
    
    int numImages = images.size();
    float arc = carousel.length / numImages;
    
    for(int i = 0; i < numImages; i++) {
        
        ofPushMatrix();
        
        ofRotateY(carousel.position + i * arc);
        ofTranslate(0, 0, radius);
        
        ofImage image = *images[i];
        image.bind();
        ofDrawPlane(0, 0, image.width, image.height);
        image.unbind();
        
        ofPopMatrix();
    }

    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == OF_KEY_LEFT) {
        carousel.drop(1);
    }
    else if(key == OF_KEY_RIGHT) {
        carousel.drop(-1);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    carousel.drag(x / 10);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    carousel.grab(x / 10);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    carousel.drop();
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
