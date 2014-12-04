#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    numCols = 100;
    numRows = 200;
    
    tileSize = 100;
    viewSize = 500;
    
    carouselX.mode = ofxCarouselModeStop;
    carouselX.length = numCols * tileSize - viewSize;
    
    carouselY.mode = ofxCarouselModeStop;
    carouselY.length = numRows * tileSize - viewSize;

}

//--------------------------------------------------------------
void ofApp::update(){
    
    carouselX.update();
    carouselY.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofPushMatrix();
    ofTranslate(ofGetWindowWidth() * 0.5 - viewSize * 0.5, ofGetWindowHeight() * 0.5 - viewSize * 0.5);
    
    
    int colIndex;
    int rowIndex;
    float colPosition;
    float rowPosition;

    int numTileCols = 6;
    int numTileRows = 6;
    
    for(int col = 0; col<numTileCols; col++) {

        colPosition = carouselX.positionForTile(col, numTileCols, tileSize, &colIndex);
        
        if(colIndex > -1 && colIndex < numCols) {
        
            for(int row = 0; row<numTileRows; row++) {

                rowPosition = carouselY.positionForTile(row, numTileRows, tileSize, &rowIndex);
                
                if(rowIndex > -1 && rowIndex < numRows) {
                    ofSetHexColor(0xFF0099);
                    ofRect(colPosition, rowPosition, tileSize - 1, tileSize - 1);
                
                    ofSetHexColor(0);
                    ofDrawBitmapString(ofToString(colIndex) + "x" + ofToString(rowIndex), colPosition, rowPosition + 10);
                }
            }
                
        }

    }

    ofSetColor(0, 0, 0, 50);
    ofRect(0, 0, viewSize, viewSize);
    
    ofPopMatrix();
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
    carouselX.drag(-x);
    carouselY.drag(-y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    carouselX.grab(-x);
    carouselY.grab(-y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    carouselX.drop();
    carouselY.drop();
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
