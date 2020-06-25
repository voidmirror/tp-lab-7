#include "gtest/gtest.h"
#include "Cell.h"
#include "Object.h"

TEST(lab7, task1)	//done
{
	Cell *cell = new Cell();
	EXPECT_EQ(0, (*cell).isEmpty());
}

TEST(lab7, task2)	//done
{
	Object *obj = new Object(3);
	EXPECT_EQ(6, (*obj).get_hp());
}

TEST(lab7, task3)	//done
{
	Object *obj = new Object(1);
	EXPECT_EQ(1, (*obj).get_hp());
}

TEST(lab7, task4)	//done
{
	Object *obj = new Object(2);
	EXPECT_EQ(4, (*obj).get_hp());
}


TEST(lab7, task5)	//done
{
	Object *obj = new Object(4);
	EXPECT_EQ(0, (*obj).get_fertility());
}

TEST(lab7, task6)	//done
{
	Object *obj = new Object(4);
	(*obj).set_fertility(4);
	EXPECT_EQ(4, (*obj).get_fertility());
}
