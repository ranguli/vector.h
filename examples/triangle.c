#include "SDL.h"
#include "../vector.h"
#include <stdlib.h>
#include <time.h>

#define POINTS_COUNT 4
#define SCREEN_HEIGHT 1366
#define SCREEN_WIDTH  768
#define TRUE 0
#define FALSE 1

typedef struct Triangle {

    /*       
     *        vertex2 
     *
     *           /\
     *          /  \
     *         /    \
     *        /      \
     *       / center \
     *      /          \
     *     /____________\
     *
     *  vertex1      vertex3
     *
     *    <--------------> scale
     */
    
    Vec2 vertex1;
    Vec2 vertex2;
    Vec2 vertex3;
    
    Vec2 center;

    int point_count; 
    int scale;
    SDL_Point points[4];
    
} Triangle;

void update_triangle(Triangle *triangle, Vec2 center, int scale) {
    
    triangle->center = center;
    triangle->scale = scale; 
    triangle->point_count = 4; 
   
    // This dynamically creates the vertices of the triangle 
    // from directives like the desired center (x,y) of the triangle
    // and the overall scale (line length).
    
    triangle->vertex1.x = center.x - (triangle->scale / 2);
    triangle->vertex1.y = center.y + (triangle->scale / 2);
    
    triangle->vertex2.x = center.x; 
    triangle->vertex2.y = center.y - (triangle->scale / 2); 

    triangle->vertex3.x = center.x + (triangle->scale / 2);
    triangle->vertex3.y = center.y + (triangle->scale / 2); 
   
    // We then convert the x's and y's of the vertices into SDL's
    // preferred structure of choice
    SDL_Point point1 = {triangle->vertex1.x, triangle->vertex1.y}; 
    SDL_Point point2 = {triangle->vertex2.x, triangle->vertex2.y}; 
    SDL_Point point3 = {triangle->vertex3.x, triangle->vertex3.y}; 
    SDL_Point point4 = {triangle->vertex1.x, triangle->vertex1.y}; 
    
    triangle->points[0] = point1;
    triangle->points[1] = point2;
    triangle->points[2] = point3;
    triangle->points[3] = point4;

}

int main(int argc, char* argv[]) {
    srand(time(NULL));
    int MAX_RAND = SCREEN_WIDTH;
    int arrived = TRUE; 

    Triangle triangle;
    Triangle *p_triangle = &triangle;
    
    Vec2 center = {200, 200};
    Vec2 new_center;
    int scale = 250;
    update_triangle(p_triangle, center, scale);

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window;
    SDL_Renderer* renderer = NULL;
    int posX = 100, posY = 100; 
    window = SDL_CreateWindow("Hello World", posX, posY, SCREEN_HEIGHT,SCREEN_WIDTH,  0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


    SDL_bool done = SDL_FALSE;

    while (!done) {
        SDL_Event event;

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawLines(renderer, triangle.points, triangle.point_count);
        SDL_RenderPresent(renderer);

        // If the triangle has arrived at the random spot it travelled
        // to, give it another one.
        if (p_triangle->center.y == new_center.y && p_triangle->center.x == new_center.x)
            arrived = TRUE;
        if (arrived == TRUE) { 
            new_center.x = rand() % MAX_RAND;
            new_center.y = rand() % MAX_RAND;
            arrived = FALSE;
        }
        // Until the triangle arrives, move it
        else {
            if (p_triangle->center.x < new_center.x)
                center.x += 0.25; 
            if (p_triangle->center.x > new_center.x)
                center.x -= 0.25;
            if (p_triangle->center.y < new_center.y)
                center.y += 0.25;
            if (p_triangle->center.y > new_center.y)
                center.y -= 0.25;

        }
        update_triangle(p_triangle, center, scale);

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

