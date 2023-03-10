#pragma once

#include "ofMain.h"
#include "Line.hpp"

class Rail{

	public:
		int id;
		int width;
		int pos; // 0 para superior, 1 para inferior
		Line line;
		
		Rail(int i, int p, int w, Line l) { // Constructor with parameters
			id = i;
			width = w;
			pos = p;
			line = l;
		}
};
