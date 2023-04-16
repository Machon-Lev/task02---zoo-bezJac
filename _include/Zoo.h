#include "Animal.h"
#include <vector>

class Zoo {
	std::vector<std::unique_ptr<Animal>> animals;
	void stop(int index);
	void move(int index);
	void create(std::string animal_type, std::string animal_name);
	void del(int index);
	void delAll(char class_name);
	void help();
	void step();
	void printZooMap();
	void printAnimalList();
public:
	void run();
};