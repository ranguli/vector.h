#include <stdio.h>  
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "vector.h"

// Shout out to this internet stranger for a great CUnit tutorial:
// https://wpollock.com/CPlus/CUnitNotes.htm


/* Test suite setup and cleanup functions: */

int init_suite(void) {
    return 0; 
}
int clean_suite(void) { 
    return 0;
}

/* Test case functions */

// Sanity check accessing of x and y points

void vec2_test_points(void) {
    Vec2 vector = {3, 4};
    CU_ASSERT(vector.x == 3);
    CU_ASSERT(vector.y == 4);

}

// Check that we can swap the x and y of a Vec2
void vec2_test_swap(void) {
    Vec2 vector = {3, 4};
    Vec2 *p_vector = &vector;
    vec2_swap_points(p_vector);
    
    CU_ASSERT(vector.x == 4);
    CU_ASSERT(vector.y == 3);

}

/* Test runner code goes here */

int main (void) {
   CU_pSuite pSuite = NULL;

   /* Initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* Create a test suite and add it to the registry */
   pSuite = CU_add_suite("test_suite", init_suite, clean_suite);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* Add our tests to the suite */
   if ( (NULL == CU_add_test(pSuite, "vec2_test_points", vec2_test_points)) ||
        (NULL == CU_add_test(pSuite, "vec2_test_swap", vec2_test_swap)) //||
        //(NULL == CU_add_test(pSuite, "max_test_3", max_test_3))
      )
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* Run all tests using the basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   printf("\n");
   CU_basic_show_failures(CU_get_failure_list());
   printf("\n\n");
   
   /* Clean up registry and return */
   CU_cleanup_registry();
   return CU_get_error();
}
