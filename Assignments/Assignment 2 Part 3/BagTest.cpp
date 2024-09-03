#include <iostream>
#include <vector>
#include "receiptbag.h"
#include <gtest/gtest.h>
using namespace std;


static TEST(BagUnitTests, DefaultConstructor)
{
	Bag<int> aBag;
	Expect_EQ(aBag.size(), 0);
	Expect_EQ(aBag.count(42), 0);
}

static Test(BagUnitTests, InsertNewThing)
{
	Bag<int> aBag;
	Expect_EQ(aBag.size(), 0);
	Expect_EQ(aBag.count(10,0);
	aBag.insert(42);
	Expect_EQ(aBag.size(), 1);
	Expect_EQ(aBag.count(42), 1);
	aBag.insert(59);
	Expect_EQ(aBag.size(),2);
	Expect_EQ(aBag.count(59), 1);
}
