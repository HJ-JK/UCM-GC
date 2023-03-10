#pragma once

#include "ofMain.h"

class Rail{

	public:
		int id;
		int width;
		int pos; // 0 para superior, 1 para inferior
		
		Rail(int i, int p, int w) { // Constructor with parameters
			id = i;
			width = w;
			pos = p;
		}
};
