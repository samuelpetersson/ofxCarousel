#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    colors.push_back(new ofColor(255, 0, 0));
    colors.push_back(new ofColor(0, 255, 0));
    colors.push_back(new ofColor(0, 0, 255));
    colors.push_back(new ofColor(255, 255, 0));
    colors.push_back(new ofColor(0, 255, 255));
    colors.push_back(new ofColor(255, 0, 255));
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    float slideWidth = ofGetWindowWidth();
    
    carousel.pagingSize = slideWidth;
    carousel.length = slideWidth * colors.size();
    
    carousel.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    
    float slideWidth = ofGetWindowWidth();
    float slideHeight = ofGetWindowHeight();
    
    for(int i = 0; i<colors.size(); i++) {
        
        float x = carousel.positionForTile(i, 6, slideWidth);
        
        ofSetColor(*colors[i]);
        ofRect(x, 0, slideWidth, slideHeight);
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    carousel.drag(-x);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    carousel.grab(-x);
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
