//
//  Obstacle.hpp
//  flipsideFury
//
//  Created by Hanjie Zhu on 17/3/23.
//

#ifndef Obstacle_hpp
#define Obstacle_hpp

#include <stdio.h>
#include "Rail.hpp"

class Obstacle{

    public:
        int type;
        int x_coord;

        Rail* rail;
        Obstacle(){};
        Obstacle(int t, int x, Rail* r) { // Constructor with parameters
            type = t;
            x_coord = x;
            rail = r;
        }
    
    void draw();
    void setRail(Rail* newRail);
    Rail* getRail();
};

#endif /* Obstacle_hpp */
