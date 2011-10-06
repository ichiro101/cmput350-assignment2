// Uncomment the following line if you wish to run the Unit Tests
// To run the unit tests YOU MUST have WinUnit and use the MSVC compiler
// #define TEST_STACK

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

BEGIN_TEST(SimplePop) {
	Stack<int> s;
	WIN_ASSERT_EQUAL(0, s.size());

	s.push(1);
	s.push(2);

	int currentTop = s.top();
	WIN_ASSERT_EQUAL(2, s.top());

	s.pop();
	currentTop = s.top();
	WIN_ASSERT_EQUAL(1, s.top());
}END_TEST

BEGIN_TEST(LotsOfElements) {
	Stack<int> s;
	WIN_ASSERT_EQUAL(0, s.size());

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	WIN_ASSERT_EQUAL(6, s.size());

	int currentTop = s.top();
	WIN_ASSERT_EQUAL(6, currentTop);

	s.pop();
	currentTop = s.top();
	WIN_ASSERT_EQUAL(5, s.size());
	WIN_ASSERT_EQUAL(5, currentTop);
	s.pop();
	currentTop = s.top();
	WIN_ASSERT_EQUAL(4, currentTop);
	s.pop();
	currentTop = s.top();
	WIN_ASSERT_EQUAL(3, currentTop);
}END_TEST

#endif