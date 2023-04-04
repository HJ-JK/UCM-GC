//
//  Obstacle.cpp
//  flipsideFury
//
//  Created by Hanjie Zhu on 17/3/23.
//

#include "Obstacle.hpp"

void Obstacle::draw(){
    if (type == 0){
        ofTranslate(800 + x_coord, rail -> y_coord - 16);
        ofDrawTriangle(0,40,20,0,40,40);
    }else if (type == 1){
        ofTranslate(800 + x_coord, rail -> y_coord - 50);
        ofDrawRectangle(0, 0, 10, 75);
    }
}

void Obstacle::setRail(Rail* newRail) {
    rail = newRail;
}

Rail* Obstacle::getRail() {
    return rail ;
}

void Obstacle::setType(int newtype) {
    type = newtype;
}

int Obstacle::getType() {
    return type;
}

void Obstacle::setXcoord(int newXcoord) {
    x_coord = newXcoord;
}

int Obstacle::getXcoord() {
    return x_coord;
}

void Obstacle::setSpeed(int newSpeed) {
    speed = newSpeed;
}

int Obstacle::getSpeed() {
    return speed;
}

