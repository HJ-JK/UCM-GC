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

        Rail* line;
        
        Obstacle(int t, int x, Rail* Rail) { // Constructor with parameters
            type = t;
            x_coord = x;
            line = l;
        }
    
    void draw();
};

#endif /* Obstacle_hpp */
