#pragma once

#include "ofMain.h"
#include "Player.hpp"
#include "Rail.hpp"
#include "Obstacle.hpp"

#define N_SOUNDS 5

class SoundData {
public:
    int     soundID;
    bool bHit;
};

class ofApp : public ofBaseApp{

	public:

		bool gameOn;

        int numObstacles;
		int numLines;
		int widthRail;
		int x_init;
		int x_lon;
		int y_init;

		bool pressed_s;
		bool pressed_x;

		bool pressed_j;
		bool pressed_n;

		int sound_ticks_1;
		int sound_ticks_2;

		bool play_sound_1;
		bool play_sound_2;

		int count_pts;

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
        void colision();
		void soundControl();
		void updateObstacles();


		// Metodo para establecer posiciones
		void setRails(vector <Line *> vl);
		// Metodo para establecer lineas
		vector <Line*> setLines(int numLines);
		// Metodo draw lines
		void drawLines(vector <Line*> vl);
    
        // Metodo para establecer lineas
        vector <Obstacle*> setObstacles(int numObstacles);
		// Metodo draw lines
		void drawObstacles(vector <Obstacle*> vo);

		// Posiciones
		vector<Rail *> vr;

		// Lineas
		vector <Line*> vl;
        
        // Obstaculos
        vector <Obstacle*> vo;

		Player player1;
		Player player2;
        
        Obstacle Obstacle1;
        Obstacle Obstacle2;
    
        ofSoundPlayer  sound[N_SOUNDS];
    
};
