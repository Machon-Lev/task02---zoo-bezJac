#include "Animal.h"
#include <vector>

class Zoo {
	std::vector<std::unique_ptr<Animal>> animals;
	void stop(const int index);
	void move(const int index);
	void create(const std::string animal_type, const std::string animal_name);
	void del(const int index);
	void delAll(const char class_name);
	void help();
	void step();
	void printZooMap();
	void printAnimalList();
	static bool compareByLocation( const std::unique_ptr<Animal>& a1,const  std::unique_ptr<Animal>& a2);
public:
	void run();
};