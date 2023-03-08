#pragma once

#include "ofMain.h"

class ofPlayer : public ofBaseApp{

	public:

		int id;
		int points;
		int position;


		void setup();
		void update();
		void draw();
		
};
