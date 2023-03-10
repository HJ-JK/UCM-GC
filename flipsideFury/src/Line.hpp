#pragma once

#include "ofMain.h"

class Line : public ofBaseApp {

	public:
		int id;
		int x; // 0 para superior, 1 para inferior
		int y;
		int lon;
		
		Line(int i, int x, int y, int lon) { // Constructor with parameters
			id = i;
			x = x;
			y = y;
		}
		void draw();

		ofPolyline line;
};
