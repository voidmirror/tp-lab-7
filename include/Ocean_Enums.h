#pragma once
enum class Object_type { empty_space, stone, prey, predator };
enum class Action { reproduce_up, reproduce_down, reproduce_left, reproduce_right,
					move_up, move_down, move_left, move_right,
					eat_up, eat_down, eat_left, eat_right,
					die, nothing};