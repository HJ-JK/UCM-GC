//
//  Obstacle.cpp
//  flipsideFury
//
//  Created by Hanjie Zhu on 17/3/23.
//

#include "Obstacle.hpp"

void Obstacle::draw(){
    ofTranslate(800, rail -> y_coord - 20);
    ofDrawTriangle(50,10,30,40,70,40);
}

void Obstacle::setRail(Rail* newRail) {
    rail = newRail;
}

//--------------------------------------------------------------
Rail* Obstacle::getRail() {
    return rail ;
}
