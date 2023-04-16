#include "Zoo.h"
#include "Lion.h"
#include "Monkey.h"
#include "Shark.h"
#include "Animal.h"
#include <stdexcept>
#include <algorithm>


void Zoo::stop(int index)
{
	if(index >= animals.size())
		throw std::out_of_range("Index is out of range.");
	animals[index]->stop();
}
void Zoo::move(int index)
{
	if (index >= animals.size())
		throw std::out_of_range("Index is out of range.");
	animals[index]->move();
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
	if (index >= animals.size())
		throw std::out_of_range("Index is out of range.");
	animals.erase(animals.begin() + index);
}
void Zoo::delAll(char class_name) {
	animals.erase(std::remove_if(animals.begin(), animals.end(), [class_name](const std::unique_ptr<Animal>& elem) { return elem->getInitial() == class_name; }), animals.end());
}
void Zoo::help() {}
void Zoo::step()
{
	std::for_each(animals.begin(), animals.end(), [](const std::unique_ptr<Animal>& a) { a->step(); });
	
}
// TODO implemnt game - printing of map and list and execution of commands from user
void Zoo::run(){}