#include "ofPlayer.h"
#include "Line.hpp"

void Line::draw() {

	line.lineTo(x, y);
	line.lineTo(x+lon, y);
	
}