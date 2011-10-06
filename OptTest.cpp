// UNCOMMENT THE FOLLOWING if you wish to run the unit tests
// #define TEST

#ifdef TEST

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

	WIN_ASSERT_FALSE(o.get_switch("-s"));
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

BEGIN_TEST(DefaultBoolOption) {
	Opt o;
	o.add_bool("-b", "Test boolean", true);
	o.add_bool("-a", "Test another boolean", false);

	WIN_ASSERT_EQUAL(true, o.get_bool("-b"));
	WIN_ASSERT_EQUAL(false, o.get_bool("-a"));
}
END_TEST

BEGIN_TEST(DefaultDoubleOption) {
	Opt o;
	o.add_double("-d", "Test double", 1.33);
	o.add_double("-a", "Test double", 2.0);

	WIN_ASSERT_EQUAL(1.33, o.get_double("-d"));
	WIN_ASSERT_EQUAL(2.0, o.get_double("-a"));
}
END_TEST

BEGIN_TEST(ProcessingSwitchOption) {
	Opt o;
	o.add_switch("-s", "Test Switch");
	WIN_ASSERT_FALSE(o.get_switch("-s"));

	int argc = 2;
	char* argv[2];
	argv[0] = "programName";
	argv[1] = "-s";

	o.process(argc, argv);
	WIN_ASSERT_TRUE(o.get_switch("-s"));
}
END_TEST

BEGIN_TEST(ProcessingIntegerOption) {
	Opt o;
	o.add_int("-i", "Integer test", 3);
	WIN_ASSERT_EQUAL(3, o.get_int("-i"));

	int argc = 3;
	char* argv[3];
	argv[0] = "programName";
	argv[1] = "-i";
	argv[2] = "5";

	o.process(argc, argv);

	WIN_ASSERT_EQUAL(5, o.get_int("-i"));
}
END_TEST

BEGIN_TEST(ProcessBooleanAndIntegerOption) {
	Opt o;
	o.add_int("-i", "Integer test", 3);
	o.add_switch("-s", "Switch test");
	WIN_ASSERT_EQUAL(3, o.get_int("-i"));
	WIN_ASSERT_EQUAL(false, o.get_switch("-s"));

	int argc = 3;
	char* argv[3];
	argv[0] = "programName";
	argv[1] = "-i";
	argv[2] = "5";

	o.process(argc, argv);

	WIN_ASSERT_EQUAL(5, o.get_int("-i"));
	WIN_ASSERT_EQUAL(false, o.get_switch("-s"));
}
END_TEST

BEGIN_TEST(ProcessStringOption) {
	Opt o;
	o.add_string("-s", "String test", "default 1");
	o.add_string("-a", "Another String test", "default 2");
	WIN_ASSERT_STRING_EQUAL("default 1", o.get_string("-s").c_str());
	WIN_ASSERT_STRING_EQUAL("default 2", o.get_string("-a").c_str());

	int argc = 3;
	char* argv[3];
	argv[0] = "programName";
	argv[1] = "-s";
	argv[2] = "ipsum";

	o.process(argc, argv);
	WIN_ASSERT_STRING_EQUAL("ipsum", o.get_string("-s").c_str());
	WIN_ASSERT_STRING_EQUAL("default 2", o.get_string("-a").c_str());
}
END_TEST

BEGIN_TEST(ProcessStringAndBoolOption) {
	Opt o;
	o.add_string("-s", "String test", "default 1");
	o.add_string("-a", "Another String test", "default 2");
	o.add_bool("-b", "Bool test 1", true);
	o.add_bool("-c", "Bool test 2", false);
	WIN_ASSERT_STRING_EQUAL("default 1", o.get_string("-s").c_str());
	WIN_ASSERT_STRING_EQUAL("default 2", o.get_string("-a").c_str());
	WIN_ASSERT_TRUE(o.get_bool("-b"));
	WIN_ASSERT_FALSE(o.get_bool("-c"));

	int argc = 5;
	char* argv[5];
	argv[0] = "programName";
	argv[1] = "-s";
	argv[2] = "ipsum";
	argv[3] = "-b";
	argv[4] = "0";

	o.process(argc, argv);
	WIN_ASSERT_STRING_EQUAL("ipsum", o.get_string("-s").c_str());
	WIN_ASSERT_STRING_EQUAL("default 2", o.get_string("-a").c_str());
	WIN_ASSERT_FALSE(o.get_bool("-b"));
	WIN_ASSERT_FALSE(o.get_bool("-c"));
}
END_TEST
#endif