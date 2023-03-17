#pragma once

#include "ofMain.h"
#include "Line.hpp"

class Rail{

	public:
		int id;
		int width;
		int pos; // 0 para superior, 1 para inferior
		int y_coord;
		Line* line;
		
		Rail(int i, int p, int w, int y, Line* l) { // Constructor with parameters
			id = i;
			width = w;
			pos = p;
			y_coord = y;
			line = l;
		}
};
