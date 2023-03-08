#pragma once

#include "ofMain.h"

class Carril{

	public:
		int id;
		int ancho;
		int pos; // 0 para superior, 1 para inferior
		
		Carril(int i, int p, int a) { // Constructor with parameters
			id = i;
			ancho = a;
			pos = p;
		}
};
