#include "WinUnit.h"
#include "Opt.H"

#include <string>

BEGIN_TEST(TestCreation) {
	Opt* o = new Opt();
	WIN_ASSERT_NOT_NULL(o);
}
END_TEST

BEGIN_TEST(DefaultSwitchOption) {
	Opt o;
	o.add_switch("-s", "Test switch");

	WIN_ASSERT_TRUE(o.get_swtich("-s"));
	WIN_ASSERT_FALSE(o.get_swtich("-a"));
}
END_TEST

BEGIN_TEST(DefaultIntOption) {
	Opt o;
	o.add_int("-i", "Test Integer", 2);
	o.add_int("-a", "Test another integer", 3);

	WIN_ASSERT_EQUAL(2, o.get_int("-i"));
	WIN_ASSERT_EQUAL(3, o.get_int("-a"));
}
END_TEST

BEGIN_TEST(ProcessingOptions) {
	std::string s = "hello";
	std::string s2 = "hello";
}
END_TEST