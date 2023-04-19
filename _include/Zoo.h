#include "Animal.h"
#include <vector>

/**
 * A class representing a zoo that contains various types of animals.
 * The zoo can be interacted with through a command-line interface, allowing users to
 * create, delete, and move animals around the zoo's map.
 */
class Zoo {
private:
	std::vector<std::unique_ptr<Animal>> animals;  // The collection of animals in the zoo.



	/**
	 * @brief Freeze an animals movement,
	 * when applied, '.' command will not affect the animal this function is called on.
	 * @param index: index of animal in the list.
	 * @throws std::out_of_range If the index is out of range.
	 */
	void stop(const int index);
	/**
	 * @brief Unfreeze an animal.
	 * @param index: index of animal in the list.
	 * @throws std::out_of_range If the index is out of range.
	 */
	void move(const int index);
	/**
	 * @brief Add a new animal to the zoo.
	 * @param animal_type: name of any class extending the Animal class.
	 * @param animal_name: name of the animal.
	 *  @throws std::invalid_argument If the class does not extend the Animal class.
	 */
	void create(const std::string animal_type, const std::string animal_name);
	/**
	* @brief Remove an animal from the zoo.
	* @param index: index of animal in the list.
	* @throws std::out_of_range If the index is out of range.
	*/
	void del(const int index);
	/**
	* @brief Remove all animals of a specific type from the zoo.
	* @param class_name: initila letter of any class name extending the Animal class.
	* @throws std::invalid_argument If the class_name does not extend the Animal class.
	*/
	void delAll(const char class_name);
	/**
	* @brief Print to console help message explaining the commands.
	*/
	void help();
	/**
	* @brief Move all animals in the zoo one legal step.
	*/
	void step();
	/**
	* @brief Print the zoo map to the console.
	*/
	void printZooMap();
	/**
	* @brief Print the list of animals in the zoo to the console.
	*/
	void printAnimalList();

	// A static comparison function for sorting animals by location.
	static bool compareByLocation(const std::unique_ptr<Animal>& a1, const std::unique_ptr<Animal>& a2);

public:
	/**
	 * Runs the main loop of the zoo simulation, prompting the user for commands
	 * and updating the state of the zoo based on those commands.
	 */
	void run();
};
