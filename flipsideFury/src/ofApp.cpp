#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	bool pressed_s = false;
	bool pressed_x = false;
	bool pressed_j = false;
	bool pressed_n = false;

	// Definiciones principales
	numLines= 5;
	widthRail = 25;
	x_init = 100;
	x_lon = 800;
	y_init = 100;



	// Crear las lineas y los rails
	vl = setLines(numLines);
	setRails(vl);

	player1.setId(0);
	player1.setPoints(0);
	player1.setRail(vr[1]);
	player1.position->occupied = true;

	player2.setId(1);
	player2.setPoints(0);
	player2.setRail(vr[6]);
	player2.position->occupied = true;
}

//--------------------------------------------------------------
void ofApp::update(){

	// Mover el jugador 1
	Rail* current_rail1 = player1.getRail();
	int num_rail1 = current_rail1->id;

	if (ofGetKeyPressed('s')) {

		if (pressed_s){
			if (num_rail1 <= 0 && vr[vr.size() - 1]->occupied==false) {
				vr[num_rail1]->occupied = false;
				player1.setRail(vr[vr.size() - 1]);
				player1.position->occupied = true;
			}
			else if (vr[num_rail1 - 1]->occupied==false) {
				vr[num_rail1]->occupied = false;
				player1.setRail(vr[num_rail1 - 1]);
				player1.position->occupied = true;
			}
		}
		pressed_s = false;
	
	}
    if (ofGetKeyPressed('x')) {

		if (pressed_x) {
			if (num_rail1 >= vr.size() - 1 && vr[0]->occupied==false) {
				vr[num_rail1]->occupied = false;
				player1.setRail(vr[0]);
				player1.position->occupied = true;
			}
			else if(vr[num_rail1 + 1]->occupied==false) {
				vr[num_rail1]->occupied = false;
				player1.setRail(vr[num_rail1 + 1]);
				player1.position->occupied = true;
			}
		}
		pressed_x = false;
			
	}


	// Mover el jugador 2
	Rail* current_rail2 = player2.getRail();
	int num_rail2 = current_rail2->id;

	if (ofGetKeyPressed('j')) {

		if (pressed_j) {
			if (num_rail2 <= 0 && vr[vr.size() - 1]->occupied == false) {
				vr[num_rail2]->occupied = false;
				player2.setRail(vr[vr.size() - 1]);
				player2.position->occupied = true;
			}
			else if (vr[num_rail2 - 1]->occupied == false) {
				vr[num_rail2]->occupied = false;
				player2.setRail(vr[num_rail2 - 1]);
				player2.position->occupied = true;
			}
		}
		pressed_j = false;

	}
	if (ofGetKeyPressed('n')) {

		if (pressed_n) {
			if (num_rail2 >= vr.size() - 1 && vr[0]->occupied == false) {
				vr[num_rail2]->occupied = false;
				player2.setRail(vr[0]);
				player2.position->occupied = true;
			}
			else if (vr[num_rail2 + 1]->occupied == false) {
				vr[num_rail2]->occupied = false;
				player2.setRail(vr[num_rail2 + 1]);
				player2.position->occupied = true;
			}
		}
		pressed_n = false;

	}
	

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetColor(ofColor::indianRed);
	player1.draw();
	ofSetColor(ofColor::cornflowerBlue);
	player2.draw();
	
	ofSetColor(ofColor::white);
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

	if (key == 's') {
		pressed_s = true;
	}
	if (key == 'x') {
		pressed_x = true;
	}
	if (key == 'j') {
		pressed_j = true;
	}
	if (key == 'n') {
		pressed_n = true;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

	if (key == 's') {
		pressed_s = false;
	}
	if (key == 'x') {
		pressed_x = false;
	}
	if (key == 'j') {
		pressed_j = false;
	}
	if (key == 'n') {
		pressed_n = false;
	}


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
void ofApp::setRails( vector <Line *> vl) {

	int i; // iterator lines
	int r = 0; // id rails


	vr.push_back(new Rail(r, 1, widthRail, vl[0]->y + 25, false, vl[0])); // r = 0;


	for (i = 1; i < numLines-1; i++) {
		r++;
		vr.push_back(new Rail(r, 0, widthRail, vl[i]->y - 25, false, vl[i]));
		r++;
		vr.push_back(new Rail(r, 1, widthRail, vl[i]->y + 25, false, vl[i]));
	}
	r++;
	vr.push_back(new Rail(r, 0, widthRail, vl[numLines-1]->y - 25, false, vl[numLines-1]));


}

//--------------------------------------------------------------
vector <Line*> ofApp::setLines(int numLines) {

	for (int i = 0; i < numLines; i++) {

		vl.push_back(new Line(i, x_init, y_init*(i+1), x_lon));
	}
	return vl;
}