/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Particle.h
 * Author: Antoine
 *
 * Created on 05 April 2018, 09:48
 */

#ifndef PARTICLE_H
#define PARTICLE_H

struct Particle {
    double x;
    double y;
    
private:
    double speed;
    double direction;
    
private:
    void init();
    
public:
    Particle();
    virtual ~Particle();
    void update(int);
};

#endif /* PARTICLE_H */

