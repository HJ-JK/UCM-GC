#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	// Definiciones principales
	numLines= 5;
	widthRail = 25;


	// Creamos el escenario

	pl1.lineTo(100, 100);
	pl1.lineTo(1000, 100);

	pl2.lineTo(100, 200);
	pl2.lineTo(1000, 200);

	pl3.lineTo(100, 300);
	pl3.lineTo(1000, 300);

	pl4.lineTo(100, 400);
	pl4.lineTo(1000, 400);

	pl5.lineTo(100, 500);
	pl5.lineTo(1000, 500);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	pl1.draw();
	pl2.draw();
	pl3.draw();
	pl4.draw();
	pl5.draw();

	player1.draw();

	

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

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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

//--------------------------------------------------------------
void ofApp::setPositions(vector<Rail *> vc) {

	int i;

	vc.push_back(new Rail(0, 1, widthRail));

	for (i = 1; i < numLines; i+2) {
		vc.push_back(new Rail(i, 0, widthRail));
		vc.push_back(new Rail(i+1, 1, widthRail));
	}

	vc.push_back(new Rail(numLines, 0, widthRail));

}
