/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Screen.h
 * Author: Antoine
 *
 * Created on 04 April 2018, 17:17
 */

#ifndef SCREEN_H
#define SCREEN_H

#include <SDL2/SDL.h>
#include <cstring>

class Screen {
public:
    const static int SCREEN_WIDTH = 800;
    const static int SCREEN_HEIGHT = 600;
    const static int SCREEN_SIZE = SCREEN_WIDTH * SCREEN_HEIGHT;
    Screen();
    bool init();
    void close();
    bool processEvents();
    void setPixel(int, int, Uint8, Uint8, Uint8);
    void update();
    Screen(const Screen& orig);
    virtual ~Screen();
    Uint32 test();
    void clear();
    void boxBlur();
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    Uint32 *buffer;
    Uint32 *buffer2;
};

#endif /* SCREEN_H */

