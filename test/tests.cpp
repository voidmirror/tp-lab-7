#include "gtest/gtest.h"
#include "Ocean"

TEST(testCell, IG_test) {
	Cell cell;
	cell.init({ 3, 5 }, NULL);
	EXPECT_EQ(3, cell.getCouple().x);
}

TEST(testCell, Obj_test) {
	Cell cell;
	cell.init({ 3, 5 }, NULL);
	cell.createObj(PREY);
	EXPECT_EQ(2, cell.getObject()->getObjectType());
}

TEST(testPrey, Power_test) {
	Prey prey;
	EXPECT_EQ(100, prey.getPower());
}

TEST(testPredator, P_Live_test) {
	Predator pr;
	vector<Cell*> ngbs = {};
	EXPECT_EQ(1, pr.live(ngbs));
}

TEST(testRock, R_Live_test) {
	Rock rock;
	vector<Cell*> ngbs = {};
	EXPECT_EQ(1, rock.live(ngbs));
}

