#include "../test-framework/unity.h"

void setUp(void){
}
void tearDown(void){
}
#include "../src/main.h"
#include <stdlib.h>

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_not_allergic_to_anything_for_eggs(void)
{
   TEST_ASSERT_FALSE(is_allergic_to(ALLERGEN_EGGS, 0));
}

