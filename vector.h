#include <stdio.h>
#include <math.h>

/** Simple structure for a 2D vector
 * @param [in] x coordinate of the vector
 * @param [in] y coordinate of the vector
 */
typedef struct Vec2  {
    float x, y;
} Vec2;

typedef struct Vec2Line {
    Vec2 p1;
    Vec2 p2;
} Vec2Line;

/** Simple structure for a 3D vector
 * @param [in] x coordinate of the vector
 * @param [in] y coordinate of the vector
 * @param [in] z coordinate of the vector 
 */
typedef struct Vec3  {
    float x, y, z;
} Vec3;

/** 
 * Swaps the x and y values of a Vector
 * @param [in] Vec2 Pointer to a vector 
 * @return none  
*/
void vec2_swap_points(Vec2 *vector) {
    int temp = vector->x;
    vector->x = vector->y;
    vector->y = temp;
}

double to_radians(double degrees) {
    return degrees * (M_PI / 180);
}

void vec2_rotate(Vec2 *vector, float angle) {
    // This is a called a rotation matrix.
    // https://en.wikipedia.org/wiki/Rotation_matrix
    
    // The cos() and sin() functions expect radians!
    
    if (vector->x > 2000)
       exit(0); 
    angle = to_radians(angle);
    vector->x = vector->x * cos(angle) - vector->x * sin(angle);
    vector->y = vector->x * sin(angle) + vector->y * cos(angle);
}

/** 
 * Gets the distance between two 2D vectors 
 * @param [in] Vec2 vector1 
 * @param [in] Vec2 vector2 
 * @return double The distance between them.
*/

int vec2_distance(Vec2 vector1, Vec2 vector2) {
    float distance = (sqrt(pow(vector2.x - vector1.x, 2) + pow(vector2.y - vector1.y, 2))) * 100.0 / 100;
    return (int)distance;
}
