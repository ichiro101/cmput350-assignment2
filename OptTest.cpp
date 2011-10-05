#include "WinUnit.h"
#include "Opt.H"

BEGIN_TEST(TestCreation) {
	Opt* o = new Opt();
	WIN_ASSERT_NOT_NULL(o);
}
END_TEST

BEGIN_TEST(SwitchOption) {
	Opt o;
	o.add_switch("-s", "Test switch");

	WIN_ASSERT_TRUE(o.get_swtich("-s"));

	WIN_ASSERT_FALSE(o.get_swtich("-a"));
}
END_TEST

BEGIN_TEST(IntOption) {
	Opt o;
	o.add_int("-i", "Test Integer", 2);

	WIN_ASSERT_EQUAL(2, o.get_int("-i"));
}
END_TEST