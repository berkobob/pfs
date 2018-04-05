/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Antoine
 *
 * Created on 02 April 2018, 15:07
 */

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Screen.h"
#include "Swarm.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {  
    srand(time(NULL));
    Screen screen;  
    
    if(screen.init() == false) 
        cout << "Error initialising SDL." << endl;
    
    Swarm swarm;
     
    while(true) {
        //update particles
        int elapsed = SDL_GetTicks();
        //screen.clear();
        swarm.update(elapsed);
        //draw particles     
        unsigned char red = (unsigned char)((1+ sin(elapsed * 0.0001)) * 128);
        unsigned char green = (unsigned char)((1+ sin(elapsed * 0.0002)) * 128);
        unsigned char blue = (unsigned char)((1+ sin(elapsed * 0.0003)) * 128);
        
        const Particle * const particles = swarm.getParticles();
        
        for (int i=0; i < Swarm::NPARTICLES; i++) {
            Particle particle = particles[i];
            int x = (particles[i].x + 1) * Screen::SCREEN_WIDTH / 2;
            int y = particle.y * Screen::SCREEN_WIDTH / 2 + 
                Screen::SCREEN_HEIGHT/2;
            screen.setPixel(x, y, red, green, blue);
        }
             
        //draw the screen
        screen.boxBlur();
        screen.update();

        //check for messages/events
        if(screen.processEvents() == false) {
            cout << "Stopping" << endl;
            break;
        }
    }
    
    screen.close();
    return 0;
}

