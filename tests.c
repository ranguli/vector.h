#include <stdio.h>  
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "vector.h"

// Shout out to this internet stranger for a great CUnit tutorial:
// https://wpollock.com/CPlus/CUnitNotes.htm

// Test suite setup and cleanup functions

int init_suite(void) {
    return 0; 
}
int clean_suite(void) { 
    return 0;
}

// Test case functions 

/** Check we can access x and y points */
void vec2_test_points(void) {
    Vec2 vector = {3, 4};
    CU_ASSERT(vector.x == 3);
    CU_ASSERT(vector.y == 4);
}

/** Check that we can swap the x and y of a Vec2 */
void vec2_test_swap(void) {
    Vec2 vector = {3, 4};
    Vec2 *p_vector = &vector;
    vec2_swap_points(p_vector);
    
    CU_ASSERT(vector.x == 4);
    CU_ASSERT(vector.y == 3);
}

/** Check the validity of our distance function */
void vec2_test_distance1(void) {
    float result;

    Vec2 vector1 = {1, 2};
    Vec2 vector2 = {1, 3};

    // If the points are 1 unit away from each other, it should return 1.0 
    result = vec2_distance(vector1, vector2);
    CU_ASSERT(result == 1);
}    

/** Check that when points are the same, the distance is 0 */
void vec2_test_distance2(void) {
    float result;

    Vec2 vector1 = {1, 1};
    Vec2 vector2 = {1, 1};
    
    result = vec2_distance(vector1, vector2);
    CU_ASSERT(result == 0);
}

/** Another arbitrary test case of the distance function */
void vec2_test_distance3(void) {
    float result;
    Vec2 vector1 = {2, 3};
    Vec2 vector2 = {5, 7};
    
    result = vec2_distance(vector1, vector2);
    CU_ASSERT(result == 5);
}

// Test runner code goes here

int main (void) {
   CU_pSuite pSuite = NULL;

   // Initialize the CUnit test registry
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   // Create a test suite and add it to the registry 
   pSuite = CU_add_suite("test_suite", init_suite, clean_suite);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   // Add our tests to the suite 
   if ((NULL == CU_add_test(pSuite, "vec2_test_points", vec2_test_points))       ||
       (NULL == CU_add_test(pSuite, "vec2_test_swap", vec2_test_swap))           || 
       (NULL == CU_add_test(pSuite, "vec2_test_distance1", vec2_test_distance1)) || 
       (NULL == CU_add_test(pSuite, "vec2_test_distance2", vec2_test_distance2)) || 
       (NULL == CU_add_test(pSuite, "vec2_test_distance3", vec2_test_distance3)) 
      )
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   // Run all tests using the basic interface
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_basic_show_failures(CU_get_failure_list());
   
   // Clean up registry and return
   CU_cleanup_registry();
   return CU_get_error();
}
