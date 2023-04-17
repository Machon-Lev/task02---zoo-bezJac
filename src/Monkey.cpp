#include "Monkey.h"
#include <random>
#include <random_util.h>
#include <iostream>

Monkey::Monkey(std::string monkey_name, Location monkey_location) :Animal(monkey_name, monkey_location) {

	generate_direction();
	step_count = 0;
}
void Monkey::printDetails() const
{
	std::cout << "Monkey: ";
	Animal::printDetails();
}
char Monkey::getInitial() const
{
	return 'M';
}



void Monkey::step()
{
    ++step_count;
    if (step_count == 5)
    {
        generate_direction();
        step_count = 0;
    }

    if (!is_freezed)
    {
        switch (moving_direction)
        {
        case 1: //vertical
        {
            location += {(int)step_size* vertical_direction, 0};
            break;
        }
        case 2: //horizontal
        {
            location += {0, (int)step_size* horizontal_direction};
            break;
        }
        default:
            break;
        }
        
        enforceLegalBounds();
    }
    
}

void Monkey::turnVertically() {}
void Monkey::turnHorizontally()
{
	horizontal_direction *= -1;
}

void Monkey::generate_direction()
{
	horizontal_direction = RandomUtil::generateRandomValue(0, 1) == 0 ? -1 : 1;
	vertical_direction = RandomUtil::generateRandomValue(0, 1) == 0 ? -1 : 1;
	moving_direction = RandomUtil::generateRandomValue(1, 2);
	step_size = (size_t)RandomUtil::generateRandomValue(1, 2);
}

void Monkey::enforceLegalBounds()
{
    if (location.row < 0)
        location.row = 0;
    if (location.row > 19)
        location.row = 19;
    if (location.column < 0)
        location.column = 0;
    if (location.column > 39)
        location.column = 39;
}