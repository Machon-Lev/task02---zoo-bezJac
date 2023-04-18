#include "Zoo.h"
#include "Lion.h"
#include "Monkey.h"
#include "Shark.h"
#include "Animal.h"
#include <random_util.h>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <sstream>

#define MAP_ROWS 20
#define MAP_COLUMNS 40

std::vector<std::string> parse_command()
{
	std::string line;
	std::getline(std::cin, line);  // read a line of input from the user


	std::istringstream iss(line);  // create an istringstream object from the line
	std::vector<std::string> tokens;  // create a vector to hold the tokens
	if (!line.empty()) {

		// read each whitespace-separated token into the vector
		std::string token;
		while (iss >> token) {
			tokens.push_back(token);
		}

	}
	return tokens;

}

void Zoo::stop(const int index)
{
	if (index >= animals.size())
		throw std::out_of_range("Index is out of range.\n");
	animals[index]->stop();
}
void Zoo::move(const int index)
{
	if (index >= animals.size())
		throw std::out_of_range("Index is out of range.\n");
	animals[index]->move();
}
void Zoo::create(const std::string animal_type, const std::string animal_name)
{
	if (animal_type != "Lion" && animal_type != "Monkey" && animal_type != "Shark")
		throw std::invalid_argument("Animal type must be either Lion, Monkey, or Shark.\n");
	Location l = Location(RandomUtil::generateRandomValue(0, 19), RandomUtil::generateRandomValue(0, 39));
	if (animal_type == "Lion")
		animals.emplace_back(std::make_unique<Lion>(animal_name, l));
	if (animal_type == "Monkey")
		animals.emplace_back(std::make_unique<Monkey>(animal_name, l));
	if (animal_type == "Shark")
		animals.emplace_back(std::make_unique<Shark>(animal_name, l));

}
void Zoo::del(const int index) {
	if (index >= animals.size())
		throw std::out_of_range("Index is out of range.\n");
	animals.erase(animals.begin() + index);
}
void Zoo::delAll(const char class_name) {
	if (class_name != 'L' && class_name != 'M' && class_name != 'S')
		throw std::invalid_argument("Class type must be either L -> Lion, M -> Monkey, or S -> Shark.\n");
	animals.erase(std::remove_if(animals.begin(), animals.end(), [class_name](const std::unique_ptr<Animal>& elem) { return elem->getInitial() == class_name; }), animals.end());
}
void Zoo::help() {
	std::cout << "Welcome to the Zoo Management System! Here are the available commands:\n\n"
		"    stop <index> - Disables an animal from moving. <index> is the number of the animal in the list.\n"
		"    move <index> - Unfreezes the animal. <index> is the number of the animal in the list.\n"
		"    create <animal_type> <animal_name> - Adds a new animal to the zoo. <animal_type> can be \"Lion\", \"Monkey\", or \"Shark\".\n"
		"	                                 <animal_name> is the name of the animal.\n"
		"    del <index> - Removes an animal from the zoo. <index> is the number of the animal in the list.\n"
		"    delAll <class_name> - Removes all animals of a specific type from the zoo. <class_name> can be 'L' for lions,\n"
		"                          'M' for monkeys, or 'S' for sharks.\n"
		"    step - Moves all animals one step. Press '.' to execute this command.\n"
		"    help - Prints this list of commands and parameters.\n"
		"    exit - terminate the program\n" << std::endl;
}
void Zoo::step() { std::for_each(animals.begin(), animals.end(), [](const std::unique_ptr<Animal>& a) { a->step(); }); }


void Zoo::printZooMap()
{
	std::cout << std::endl << "Zoo Map:\n";
	int animals_index = 0;
	int animals_size = animals.size();

	// Print the top border of the grid
	std::cout << "+";
	for (int j = 0; j < MAP_COLUMNS; j++)
	{
		std::cout << "-";
	}
	std::cout << "+" << std::endl;

	for (int i = 0; i < MAP_ROWS; i++)
	{
		std::cout << "|"; // Start each row with a vertical bar

		for (int j = 0; j < MAP_COLUMNS; j++)
		{
			Location tmp = Location(i, j);

			if (animals_index < animals_size && animals[animals_index]->getLocation() == tmp)
			{
				std::cout << animals[animals_index]->getInitial();
				while (animals_index < animals_size && animals[animals_index]->getLocation() == tmp)
					++animals_index;
			}
			else
				std::cout << " ";
		}

		std::cout << "|" << std::endl; // End each row with a vertical bar
	}

	// Print the bottom border of the grid
	std::cout << "+";
	for (int j = 0; j < MAP_COLUMNS; j++)
	{
		std::cout << "-";
	}
	std::cout << "+\n\n";
}
void Zoo::printAnimalList()
{
	std::sort(animals.begin(), animals.end(), compareByLocation);
	std::cout << "Animal list:\n";
	for (size_t i = 0; i < animals.size(); i++)
	{
		std::cout << i + 1 << ". ";
		animals[i]->printDetails();
		std::cout << std::endl;
	}
}
bool Zoo::compareByLocation(const std::unique_ptr<Animal>& a1, const std::unique_ptr<Animal>& a2)
{
	Location l1 = a1->getLocation();
	Location l2 = a2->getLocation();
	return l1 < l2;
}

void Zoo::run() {

	std::vector<std::string> commands_list = { "stop","move","create","del","delAll",".","help","exit" };
	bool game_runing = true;
	bool no_error = true;
	std::vector<std::string> command_and_args;
	std::string command;
	char command_type;
	int index;

	help();

	create("Lion", "Simba");
	create("Lion", "Mufasa");
	create("Monkey", "Rafiki");
	create("Shark", "Jaws");

	while (game_runing)
	{
		if (no_error)
		{
			printAnimalList();
			printZooMap();
		}
		command = "";
		std::cout << "Enter your command:\n";
		command_and_args = parse_command();
		if (!command_and_args.empty())
			command = command_and_args[0];
		if (command != "" && (std::find(commands_list.begin(), commands_list.end(), command) != commands_list.end()))
		{
			no_error = true;
			command_type = command[0];
			switch (command_type)
			{
			case 's': {

				try
				{
					index = std::stoi(command_and_args[1]) - 1;
					stop(index);
				}
				catch (const std::exception& e) { std::cout << e.what(); no_error = false; }
				break;
			}
			case 'm':
			{
				try
				{
					index = std::stoi(command_and_args[1]) - 1;
					move(index);
				}
				catch (const std::exception& e) { std::cout << e.what(); no_error = false; }
				break;
			}
			case 'c':
			{
				try
				{
					create(command_and_args[1], command_and_args[2]);
				}
				catch (const std::exception& e) { std::cout << e.what(); no_error = false; }
				break;
			}
			case 'd':
			{

				try
				{
					if (command.size() < 4)
					{
						index = std::stoi(command_and_args[1]) - 1;
						del(index);
					}
					else
						delAll(command_and_args[1].at(0));

				}
				catch (const std::exception& e) { std::cout << e.what(); no_error = false; }
				break;

			}
			case 'h':
			{
				help();
				break;
			}
			case '.':
			{
				step();
				break;
			}

			case 'e':
			{
				game_runing = false;
				break;
			}

			}
		}
		else
		{
			std::cout << "Please use valid commands only!\nFor list of valid commands type 'help'\n";
			no_error = false;
		}
	}
	animals.clear();
}

