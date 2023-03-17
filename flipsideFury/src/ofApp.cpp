#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	// Definiciones principales
	numLines= 5;
	widthRail = 25;
	x_init = 100;
	x_lon = 800;
	y_init = 100;



	// Crear las lineas y los rails
	vl = setLines(numLines);
	setRails(vr, vl);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	player1.draw();

	drawLines(vl);
}

//--------------------------------------------------------------
void ofApp::drawLines(vector <Line*> vl) {

	for (Line* l : vl){
		l->draw();
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
void ofApp::setRails(vector<Rail *> vr, vector <Line *> vl) {

	int i; // iterator lines
	int r = 0; // id rails

	vr.push_back(new Rail(r, 1, widthRail, vl[0]->y + 25, vl[0])); // r = 0;

	for (i = 1; i < numLines-1; i++) {
		r++;
		vr.push_back(new Rail(r, 0, widthRail, vl[i]->y - 25, vl[i]));
		r++;
		vr.push_back(new Rail(r, 1, widthRail, vl[i]->y + 25, vl[i]));
	}
	vr.push_back(new Rail(r, 0, widthRail, vl[numLines-1]->y - 25, vl[numLines-1]));

}

//--------------------------------------------------------------
vector <Line*> ofApp::setLines(int numLines) {

	for (int i = 0; i < numLines; i++) {

		vl.push_back(new Line(i, x_init, y_init*(i+1), x_lon));
	}
	return vl;
}