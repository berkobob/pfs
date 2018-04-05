/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Swarm.cpp
 * Author: Antoine
 * 
 * Created on 05 April 2018, 09:48
 */

#include "Swarm.h"

Swarm::Swarm(): lastTime(0) {
    particles = new Particle[NPARTICLES];
}

void Swarm::update(int elapsed) {
    int interval = elapsed - lastTime;
    for (int i=0; i<Swarm::NPARTICLES; i++) {
        particles[i].update(interval);
    }
    lastTime = elapsed;
}

Swarm::Swarm(const Swarm& orig) {
}

Swarm::~Swarm() {
    delete [] particles;
}

