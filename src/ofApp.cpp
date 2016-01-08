#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(225, 225, 225);
	ofSetCircleResolution(80);
    ofSetLogLevel(OF_LOG_VERBOSE);


	balls.assign(10, Ball());

	arrow.load("arrow.png");
	arrow.setAnchorPercent(1.0, 0.5);

	// initialize all of the Ball particles
	for(int i=0; i<balls.size(); i++){
		balls[i].init(i);
	}
}


//--------------------------------------------------------------
void ofApp::update() {
	for(int i=0; i < balls.size(); i++){
		balls[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofEnableAlphaBlending();
	ofSetColor(255);

	ofPushStyle();
		ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
		for(int i = 0; i< balls.size(); i++){
			balls[i].draw();
		}
	ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::exit(){

}

/*
void ofApp::mousePressed(ofMouseEventArgs &mouse)
{
    ofLog(OF_LOG_VERBOSE, "touch %d down at (%i,%i)", 0, (int)mouse.x, (int)mouse.y);
	balls[0].moveTo(mouse.x, mouse.y);
	balls[0].bDragged = true;
}
*/

//--------------------------------------------------------------
void ofApp::touchDown(ofTouchEventArgs & touch){
    ofLog(OF_LOG_VERBOSE, "touch %d down at (%i,%i)", touch.id, (int)touch.x, (int)touch.y);
	balls[touch.id].moveTo(touch.x, touch.y);
	balls[touch.id].bDragged = true;
}

//--------------------------------------------------------------
void ofApp::touchMoved(ofTouchEventArgs & touch){
    ofLog(OF_LOG_VERBOSE, "touch %d moved at (%i,%i)", touch.id, (int)touch.x, (int)touch.y);
	balls[touch.id].moveTo(touch.x, touch.y);
	balls[touch.id].bDragged = true;
}

//--------------------------------------------------------------
void ofApp::touchUp(ofTouchEventArgs & touch){
    ofLog(OF_LOG_VERBOSE, "touch %d up at (%i,%i)", touch.id, (int)touch.x, (int)touch.y);
	balls[touch.id].bDragged = false;
}

//--------------------------------------------------------------
void ofApp::touchDoubleTap(ofTouchEventArgs & touch){
    ofLog(OF_LOG_VERBOSE, "touch %d double tap at (%i,%i)", touch.id, (int)touch.x, (int)touch.y);
}

//--------------------------------------------------------------
void ofApp::touchCancelled(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}
