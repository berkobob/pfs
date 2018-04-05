/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Swarm.h
 * Author: Antoine
 *
 * Created on 05 April 2018, 09:48
 */

#ifndef SWARM_H
#define SWARM_H

#include "Particle.h"

class Swarm {
public:
    const static int NPARTICLES = 5000;
    const Particle * const getParticles() {return particles;};
    void update(int);
    Swarm();
    Swarm(const Swarm& orig);
    virtual ~Swarm();
private:
    Particle *particles; 
    int lastTime;
};

#endif /* SWARM_H */

