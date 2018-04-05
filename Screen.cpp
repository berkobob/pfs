/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Screen.cpp
 * Author: Antoine
 * 
 * Created on 04 April 2018, 17:17
 */

#include "Screen.h"

bool Screen::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return false;
    }

    window = SDL_CreateWindow("Particle Fire Explosion",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
            SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        SDL_Quit();
        return 2;
    }

    renderer = SDL_CreateRenderer(window, -1,
            SDL_RENDERER_PRESENTVSYNC);
    
    texture = SDL_CreateTexture(renderer,
            SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH,
            SCREEN_HEIGHT);

    if (renderer == NULL) {
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

    if (texture == NULL) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

    buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
    buffer2 = new Uint32[SCREEN_SIZE];
    int size = SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32);

    memset(buffer, 0, size);
    memset(buffer2, 0, size);

    return true;
}

void Screen::close() {
    delete [] buffer;
    delete [] buffer2;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Screen::processEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return false;
        }
    }
    return true;
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
    
    if (x<0 || x >= SCREEN_WIDTH || y<0 || y >= SCREEN_HEIGHT)
        return;
    
    Uint32 color = 0;
    
    color += red;
    color <<= 8;
    color += green;
    color <<=8;
    color += blue;
    color <<= 8;
    color += 0xFF;
    
    buffer[(y*SCREEN_WIDTH) + x] = color;
}
/*
void Screen::clear() {
    memset(buffer, 0, SCREEN_SIZE*4);
    memset(buffer2, 0, SCREEN_SIZE*4);
}
*/
void Screen::boxBlur() {
    Uint32 *temp = buffer;
    buffer = buffer2;
    buffer2 = temp;
    
    for (int y=0; y<SCREEN_HEIGHT; y++) {
        for (int x=0; x<SCREEN_WIDTH; x++) {
            
            int redTotal = 0;
            int greenTotal = 0;
            int blueTotal = 0;
            
            for (int row=-1; row<=1; row++) {
                for (int col=-1; col<=1; col++) {
                    int currentX = x+col;
                    int currentY = y+row;
                    
                    if (currentX >= 0 && currentX < SCREEN_WIDTH && 
                        currentY >= 0 && currentY < SCREEN_HEIGHT) {
                        Uint32 color = buffer2[currentY*SCREEN_WIDTH+currentX];
                        Uint8 red = color >> 24;
                        Uint8 green = color >> 16;
                        Uint8 blue = color >>  8;
                        
                        redTotal += red;
                        greenTotal += green;
                        blueTotal += blue;
                    }
                }
            }
            
            Uint8 red = redTotal/9;
            Uint8 green = greenTotal/9;
            Uint8 blue = blueTotal/9;
            
            setPixel(x, y, red, green, blue);
        }
    }
}

Uint32 Screen::test(){
    buffer[240400] = 0xFFFFFFFF;
    return buffer[479999];
}

void Screen::update() {
    SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH*sizeof(Uint32));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

Screen::Screen() :
    window(NULL), renderer(NULL), texture(NULL), buffer(NULL), buffer2(NULL) {
}

Screen::~Screen() {
}

