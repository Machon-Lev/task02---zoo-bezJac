#include "Zoo.h"
#include "Lion.h"
#include "Monkey.h"
#include "Shark.h"
#include "Animal.h"
#include <stdexcept>
#include <algorithm>
#include <iostream>


#define MAP_ROWS 20
#define MAP_COLUMNS 40


void Zoo::stop(int index)
{
	if(index-1 >= animals.size())
		throw std::out_of_range("Index is out of range.");
	animals[index-1]->stop();
}
void Zoo::move(int index)
{
	if (index-1 >= animals.size())
		throw std::out_of_range("Index is out of range.");
	animals[index-1]->move();
}
void Zoo::create(std::string animal_type, std::string animal_name)
{
	if (animal_type == "Lion")
		animals.emplace_back(std::make_unique<Lion>(animal_name));
	if (animal_type == "Monkey")
		animals.emplace_back(std::make_unique<Monkey>(animal_name));
	if (animal_type == "Shark")
		animals.emplace_back(std::make_unique<Shark>(animal_name));

}
void Zoo::del(int index){
	if (index-1 >= animals.size())
		throw std::out_of_range("Index is out of range.");
	animals.erase(animals.begin() + index-1);
}
void Zoo::delAll(char class_name) {
	animals.erase(std::remove_if(animals.begin(), animals.end(), [class_name](const std::unique_ptr<Animal>& elem) { return elem->getInitial() == class_name; }), animals.end());
}
void Zoo::help() {}
void Zoo::step()
{
	std::for_each(animals.begin(), animals.end(), [](const std::unique_ptr<Animal>& a) { a->step(); });
	
}

// TODO  - implement Zoo map printing.
void Zoo::printZooMap()
{
	
}
void Zoo::printAnimalList()
{
	for (size_t i = 0; i < animals.size(); i++)
	{
		std::cout << i + 1 << ". ";
		animals[i]->printDetails();
		std::cout << std::endl;
	}
}
// TODO implemnt game - printing of map and list and execution of commands from user
void Zoo::run(){
	/*create("Lion", "Simba");
	create("Lion", "Mufasa");
	create("Monkey", "Rafiki");
	create("Shark", "Jaws");
	printZooMap();
	printAnimalList();
	del(1);
	printAnimalList();
	animals.clear();*/
}