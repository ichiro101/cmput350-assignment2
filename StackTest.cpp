// Uncomment the following line if you wish to run the Unit Tests
// To run the unit tests YOU MUST have WinUnit and use the MSVC compiler
#define TEST_STACK

#ifdef TEST_STACK

#include "WinUnit.h"
#include "Stack.h"

BEGIN_TEST(TestStackCreation){
	Stack<int> s;
}END_TEST

BEGIN_TEST(SimplePush){
	Stack<int> s;
	s.push(5);

	int elem = s.top();
	WIN_ASSERT_EQUAL(5, elem);
}END_TEST

BEGIN_TEST(StackSize) {
	Stack<int> s;
	WIN_ASSERT_EQUAL(0, s.size());

	s.push(5);
	WIN_ASSERT_EQUAL(1, s.size());
}END_TEST

#endif