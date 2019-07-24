#include "SDL.h"
#include "../vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_HEIGHT 1366
#define SCREEN_WIDTH  768
#define TRUE 0
#define FALSE 1

int main(int argc, char* argv[]) {
    
    Vec2Line line1; 

    line1.p1.x = 600.0;
    line1.p1.y = 600.0;
    line1.p2.x = 700.0;
    line1.p2.y = 700.0;
    
    Vec2 *ptr_line1; 
    ptr_line1 = &line1.p1;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window;
    SDL_Renderer* renderer = NULL;
    int posX = 100, posY = 100; 
    window = SDL_CreateWindow("Vector Example", posX, posY, SCREEN_HEIGHT,SCREEN_WIDTH,  0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_bool done = SDL_FALSE;

    while (!done) {
      
        SDL_Event event;
       
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);

        // Draw the first line
        vec2_rotate(ptr_line1, -1);
        printf("Line 1: (%f,%f) and (%f,%f)\n", line1.p1.x, line1.p1.y, line1.p2.x, line1.p2.y);
        SDL_RenderDrawLine(renderer, line1.p1.x, line1.p1.y, line1.p2.x, line1.p2.y);
        
        // Why does this only seem to work the first time?
        // Everytime this is called we should see the line rotate
        // by 1 deg
        
        SDL_RenderPresent(renderer);

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                done = SDL_TRUE;
            }
        }
    }

    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }
    if (window) {
        SDL_DestroyWindow(window);
    }

    SDL_Quit();
    return 0;
}
