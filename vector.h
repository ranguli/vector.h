#include <stdio.h>
#include <math.h>

/** Simple structure for a 2D vector
 * @param [in] x coordinate of the vector
 * @param [in] y coordinate of the vector
 */
typedef struct Vec2  {
    int x;
    int y;

} Vec2;

/** Simple structure for a 3D vector
 * @param [in] x coordinate of the vector
 * @param [in] y coordinate of the vector
 * @param [in] z coordinate of the vector 
 */
typedef struct Vec3  {
    int x;
    int y;
    int z;

} Vec3;

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

/** 
 * Gets the dsiatance between two 2D vectors 
 * @param [in] Vec2 vector1 
 * @param [in] Vec2 vector2 
 * @return double The distance between them.
*/

int vec2_distance(Vec2 vector1, Vec2 vector2) {
    float distance;
    distance = sqrt(pow(vector2.x - vector1.x, 2) + pow(vector2.y - vector1.y, 2));
    distance = (distance * 100.0) / 100.0;
    return (int)distance;
}

