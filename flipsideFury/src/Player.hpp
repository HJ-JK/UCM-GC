#pragma once

#include "ofMain.h"
#include "Rail.hpp"

class Player{

	public:

		int id;
		int points;
		Rail * position;

		Player() {};
		Player(int i, int pts, Rail * pos) { // Constructor with parameters
			id = i;
			points = pts;
			position = pos;
		}
		void setup();
		void update();
		void draw();

		void setId(int newId);
		int getId();

		void setPoints(int newPoints);
		int getPoints();

		void setRail(Rail* newRail);
		Rail* getRail();

		
		
};
