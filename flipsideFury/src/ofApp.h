#pragma once

#include "ofMain.h"
#include "Player.hpp"
#include "Rail.hpp"

class ofApp : public ofBaseApp{

	public:

		int numLines;
		int widthRail;
		int x_init;
		int x_lon;
		int y_init;

		bool pressed_s;
		bool pressed_x;

		bool pressed_j;
		bool pressed_n;

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
		void setRails(vector <Line *> vl);
		// Metodo para establecer lineas
		vector <Line*> setLines(int numLines);
		// Metodo draw lines
		void drawLines(vector <Line*> vl);

		// Posiciones
		vector<Rail *> vr;

		// Lineas
		vector <Line*> vl;

		Player player1;
		Player player2;
};
