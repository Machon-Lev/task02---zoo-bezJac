/**
 * @file random_util.h
 * @brief Defines a utility namespace for generating random values.
 */

#ifndef RANDOM_UTIL_H
#define RANDOM_UTIL_H

#include <random>

namespace RandomUtil {

	/**
	 * @brief Generates a Normal distributed random integer between a lower and upper bound (inclusive).
	 *
	 * @param lower_bound The lower bound of the range (inclusive).
	 * @param upper_bound The upper bound of the range (inclusive).
	 * @return A random integer between the lower and upper bounds.
	 */
	inline int generateRandomValue(int lower_bound, int upper_bound)
	{
		std::random_device rd; 
		std::mt19937 gen(rd()); 
		std::uniform_int_distribution<int> dist(lower_bound, upper_bound); 
		return dist(gen); 

	}
}

#endif