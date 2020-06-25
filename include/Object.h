#ifndef Object_H
#define Object_H

class Object
{
public:
	int get_state();
	int get_hp();
	int get_fertility();

	void set_state(int state);
	void set_hp(int hp);
	void set_fertility(int fertility);

	Object();
	Object(int state);
	~Object();

private:
	// 0 - void, 1 - stone, 2 - prey, 3 - redator
	int state;
	// health points
	int hp;
	// fertility points: prey - max 2, predator - max 12, default - 0
	int fertility;
};

#endif