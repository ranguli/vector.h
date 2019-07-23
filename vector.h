#include <stdio.h>

typedef struct Vec2  {
    int x;
    int y;

} Vec2;

/** 
 * Swaps the x and y values of a Vector
 * @param [in] Vec2 Pointer to a vector 
 * @return none  
*/

void vec2_swap_points(Vec2 *vector) {
    int temp;
    
    temp = vector->x;
    vector->x = vector->y;
    vector->y = temp;

}
