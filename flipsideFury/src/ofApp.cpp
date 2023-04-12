#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetWindowTitle("Flipside Game");
	//ofSetBackgroundColor(ofColor :: cadetBlue);
    imageBG.load("BG2.jpg");
    
	gameOn = true;

	bool pressed_s = false;
	bool pressed_x = false;
	bool pressed_j = false;
	bool pressed_n = false;

	sound_ticks_1 = 0;
	sound_ticks_2 = 0;
	play_sound_1 = false;
	play_sound_2 = false;

	// Definiciones principales
	numLines= 5;
    
	widthRail = 25;
	x_init = 100;
	x_lon = 1400;
	y_init = 100;



	// Crear las lineas y los rails
	vl = setLines(numLines);
	setRails(vl);

	// Numero de obstaculos = numero de rails
	numObstacles = vr.size();
    
    // Crear Obstaculos
    vo = setObstacles(numObstacles);

	player1.setId(0);
	player1.setPoints(0);
	player1.setRail(vr[1]);
	player1.position->occupied = true;

	player2.setId(1);
	player2.setPoints(0);
	player2.setRail(vr[6]);
	player2.position->occupied = true;
    

    
    for (int i=0; i<N_SOUNDS; i++) {
        sound[i].load("sfx/"+ofToString(i)+".mp3");
        sound[i].setMultiPlay(true);
        sound[i].setLoop(false);
    }
    
    verdana.load("Arial Unicode.ttf", 25, true, true);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

	if (gameOn) {


		colision();

		soundControl();

		// Stop the game 
		int score_p1 = player1.getPoints();
		int score_p2 = player2.getPoints();
		// One loose
		if (score_p1 < 0 or score_p2 < 0) {
			gameOn = false;
		}
		// Too long
		if (score_p1 > 100000 or score_p2 > 100000) {
			gameOn = false;
		}

		// Mover el jugador 1
		Rail* current_rail1 = player1.getRail();
		int num_rail1 = current_rail1->id;

		if (ofGetKeyPressed('s')) {

			if (!pressed_s && !pressed_x) { // if S wasnt pressed
				if (num_rail1 <= 0) { // If player is on rail 0
					if (vr[vr.size() - 1]->occupied == false) { // if last rail is free
						vr[num_rail1]->occupied = false;
						player1.setRail(vr[vr.size() - 1]);
						player1.position->occupied = true;
					}
				}
				else { // if player isnt on rail 0
					if (vr[num_rail1 - 1]->occupied == false) { //if rail above is free
						vr[num_rail1]->occupied = false;
						player1.setRail(vr[num_rail1 - 1]);
						player1.position->occupied = true;
					}
				}
				pressed_s = true;
			}
		}
		else {
			pressed_s = false;
		}

		if (ofGetKeyPressed('x')) {

			if (!pressed_s && !pressed_x) { // if X wasnt pressed
				if (num_rail1 >= vr.size() - 1) { // if player is on last rail
					if (vr[0]->occupied == false) { // if rail 0 is free
						vr[num_rail1]->occupied = false;
						player1.setRail(vr[0]);
						player1.position->occupied = true;
					}

				}
				else { // if player isnt on last rail
					if (vr[num_rail1 + 1]->occupied == false) { // if rail below is free
						vr[num_rail1]->occupied = false;
						player1.setRail(vr[num_rail1 + 1]);
						player1.position->occupied = true;
					}
				}
				pressed_x = true;
			}
		}
		else {
			pressed_x = false;
		}

		// Mover el jugador 2
		Rail* current_rail2 = player2.getRail();
		int num_rail2 = current_rail2->id;

		if (ofGetKeyPressed('j')) {

			if (!pressed_j && !pressed_n) { // if J wasnt pressed
				if (num_rail2 <= 0) { // If player is on rail 0
					if (vr[vr.size() - 1]->occupied == false) { // if last rail is free
						vr[num_rail2]->occupied = false;
						player2.setRail(vr[vr.size() - 1]);
						player2.position->occupied = true;
					}
				}
				else { // if player isnt on rail 0
					if (vr[num_rail2 - 1]->occupied == false) { //if rail above is free
						vr[num_rail2]->occupied = false;
						player2.setRail(vr[num_rail2 - 1]);
						player2.position->occupied = true;
					}
				}
				pressed_j = true;
			}
		}
		else {
			pressed_j = false;
		}

		if (ofGetKeyPressed('n')) {

			if (!pressed_j && !pressed_n) { // if N wasnt pressed
				if (num_rail2 >= vr.size() - 1) { // if player is on last rail
					if (vr[0]->occupied == false) { // if rail 0 is free
						vr[num_rail2]->occupied = false;
						player2.setRail(vr[0]);
						player2.position->occupied = true;
					}

				}
				else { // if player isnt on last rail
					if (vr[num_rail2 + 1]->occupied == false) { // if rail below is free
						vr[num_rail2]->occupied = false;
						player2.setRail(vr[num_rail2 + 1]);
						player2.position->occupied = true;
					}
				}
				pressed_n = true;
			}
		}
		else {
			pressed_n = false;
		}

 		// Rewarding players every 30 updates
		if (count_pts >= 30) {
			count_pts=0;
			player1.setPoints(player1.getPoints() + 1);
			player2.setPoints(player2.getPoints() + 1);
		}
		count_pts++;

		updateObstacles();

	}
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    imageBG.draw(0, 0, ofGetWidth(), ofGetHeight());

	if (gameOn) {
		// Score
		ofSetColor(ofColor :: white);
        verdana.drawString("Score", ofGetWidth() / 2 - 30, 600);
        verdana.drawString("P1", ofGetWidth() / 2 - 200, 650);
        verdana.drawString("P2", ofGetWidth() / 2 + 200, 650);
        /*
		ofDrawBitmapString("Score", ofGetWidth() / 2 - 5, 600);
		ofDrawBitmapString("P1", ofGetWidth() / 2 - 50, 650);
		ofDrawBitmapString("P2", ofGetWidth() / 2 + 50, 650);
        */
		int score_p1 = player1.getPoints();
		int score_p2 = player2.getPoints();
        verdana.drawString(ofToString(score_p1), ofGetWidth() / 2 - 200, 700);
        verdana.drawString(ofToString(score_p2), ofGetWidth() / 2 + 200, 700);
        /*
		ofDrawBitmapString(score_p1, ofGetWidth() / 2 - 50, 700);
		ofDrawBitmapString(score_p2, ofGetWidth() / 2 + 50, 700);
        */

		// Players
		ofSetColor(ofColor::indianRed);
		player1.draw();
		ofSetColor(ofColor::cornflowerBlue);
		player2.draw();

		// Obstacles
		drawObstacles(vo);

		// Lines
		ofSetColor(ofColor::white);
		drawLines(vl);

	}
	else {
		// Score
		ofSetColor(ofColor::white);
        verdana.drawString("Score", ofGetWidth() / 2 - 50, ofGetHeight()/2 - 100);
        verdana.drawString("P1", ofGetWidth() / 2 - 200, ofGetHeight() / 2 - 50);
        verdana.drawString("P2", ofGetWidth() / 2 + 180, ofGetHeight() / 2 - 50);
        /*
		ofDrawBitmapString("Score", ofGetWidth() / 2 - 5, ofGetHeight()/2 - 100);
		ofDrawBitmapString("P1", ofGetWidth() / 2 - 50, ofGetHeight() / 2 - 50);
		ofDrawBitmapString("P2", ofGetWidth() / 2 + 50, ofGetHeight() / 2 - 50);
        */
		int score_p1 = player1.getPoints();
		int score_p2 = player2.getPoints();
        verdana.drawString(ofToString(score_p1), ofGetWidth() / 2 - 200, ofGetHeight() / 2);
        verdana.drawString(ofToString(score_p2), ofGetWidth() / 2 + 200, ofGetHeight() / 2);
        /*
		ofDrawBitmapString(score_p1, ofGetWidth() / 2 - 50, ofGetHeight() / 2);
		ofDrawBitmapString(score_p2, ofGetWidth() / 2 + 50, ofGetHeight() / 2);
        */

		// Too long
		if (score_p1 > 100000 or score_p2 > 100000) {
			verdana.drawString("Congrats! You both win (long game)", ofGetWidth() / 2 - 150, ofGetHeight() / 2 + 50);
		}
		// One loose
		if (score_p1 < 0 and score_p2 < 0) {
            verdana.drawString("You both loose :(", ofGetWidth() / 2 - 100, ofGetHeight() / 2 + 50);
		}
		else if (score_p1 < 0) {
            verdana.drawString("Player 2 win", ofGetWidth() / 2 - 50, ofGetHeight() / 2 + 50);
		}
		else if (score_p2 < 0) {
            verdana.drawString("Player 1 win", ofGetWidth() / 2 - 50, ofGetHeight() / 2 + 50);
		}

	}

}
	

//--------------------------------------------------------------
void ofApp::drawLines(vector <Line*> vl) {

	for (Line* l : vl){
		l->draw();
	}
}

//--------------------------------------------------------------
void ofApp::drawObstacles(vector <Obstacle*> vo) {

	for (Obstacle* o : vo) {
		ofPushMatrix();
		o->draw();
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

//--------------------------------------------------------------
vector <Obstacle*> ofApp::setObstacles(int numObstacles) {

	int i = 0;

	vector<bool> auxVec;
	for (i = 0; i < numObstacles; i++) {
		auxVec.push_back(false);
	}

    for (i = 0; i < numObstacles; i++) {
        // TODO set id, cambiar modulo more types, set speed random
			
		int auxRandom = rand() % numObstacles;

		while (auxVec[auxRandom]) { // Randomize 
			
			auxRandom = rand() % numObstacles;
		}

		int auxSpeed = rand() % 5;
		if (auxSpeed == 0) {
			auxSpeed = 1;
		}
		vo.push_back(new Obstacle(rand() % 3, x_lon, auxSpeed, vr[auxRandom]));
		auxVec[auxRandom] = true;
        
    }
    return vo;
}


//--------------------------------------------------------------
void ofApp::colision(){

	for (int i = 0; i < numObstacles; i++) {
		if (player1.position == vo[i]->getRail() and vo[i]->getXcoord() < 175) {
			player1.setPoints(player1.getPoints() - 1000);
			sound[0].play();
			play_sound_1 = true;

			// updates obstacle
			vo[i]->setXcoord(x_lon); // reset position
			int auxSpeed = rand() % 5;
			if (auxSpeed == 0) {
				auxSpeed = 5;
			}
			vo[i]->setSpeed(auxSpeed);
			vo[i]->setType(rand() % 3);

		}
	}

	for (int i = 0; i < numObstacles; i++) {
		if (player2.position == vo[i]->getRail() and vo[i]->getXcoord() < 175) {
			player2.setPoints(player2.getPoints() - 1000); // - vo[i].getPenalty()
			sound[1].play();
			play_sound_2 = true;



			// updates obstacle
			vo[i]->setXcoord(x_lon); // reset position
			int auxSpeed = rand() % 5;
			if (auxSpeed == 0) {
				auxSpeed = 5;
			}
			vo[i]->setSpeed(auxSpeed);
			vo[i]->setType(rand() % 3);
		}
	}
    
}
//--------------------------------------------------------------
void ofApp::soundControl() {
	if (play_sound_1 && sound_ticks_1 <= 100) {
		sound_ticks_1++;
	}
	else {
		play_sound_1 = false;
		sound_ticks_1 = 0;
		sound[0].stop();
	}

	if (play_sound_2 && sound_ticks_2 <= 10) {
		sound_ticks_1++;
	}
	else {
		play_sound_2 = false;
		sound_ticks_2 = 0;
		sound[1].stop();
	}

}

//--------------------------------------------------------------
void ofApp::updateObstacles() {


	// Actualizar posicion obstaculos
	for (int i = 0; i < numObstacles; i++) {
		vo[i]->setXcoord(vo[i]->getXcoord() - vo[i]->getSpeed());


		if (vo[i]->getXcoord() < 100) {

			vo[i]->setXcoord(x_lon); // reset position
			int auxSpeed = rand() % 5;
			if (auxSpeed == 0) {
				auxSpeed = 5;
			}
			vo[i]->setSpeed(auxSpeed);
			vo[i]->setType(rand() % 3);
		}
	}
}
