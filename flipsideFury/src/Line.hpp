#pragma once

#include "ofMain.h"

class Line{

	public:
		int id;
		int pos; // 0 para superior, 1 para inferior
		
		Line(int i = 1, int p = 3) { // Constructor with parameters (TODO quitar valores default)
			id = i;
			pos = p;

		}
};
