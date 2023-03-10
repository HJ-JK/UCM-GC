#pragma once

#include "ofMain.h"
#include "ofPlayer.h"
#include "Rail.hpp"

class ofApp : public ofBaseApp{

	public:

		int numLines;
		int widthRail;

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);


		// Metodo para establecer posiciones
		void setPositions(vector<Rail *> vc);


		// Posiciones
		vector<Rail *> vecRail;


		// Definimos las lineas donde tendrá lugar el juego
		
		ofPolyline pl1, pl2, pl3, pl4, pl5;



		ofPlayer player1;

		ofVec2f pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8;


		
};
