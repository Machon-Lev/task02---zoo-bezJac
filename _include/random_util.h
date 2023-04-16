#ifndef RANDOM_UTIL_H
#define RANDOM_UTIL_H

#include <random>

namespace RandomUtil {
	inline int generateRandomValue(int lower_bound, int upper_bound)
	{
		std::random_device rd; // create a random_device object to seed the random number generator
		std::mt19937 gen(rd()); // create a Mersenne Twister engine with rd as the seed
		std::uniform_int_distribution<int> dist(lower_bound, upper_bound); // create a uniform distribution object with range [0,1]
		return dist(gen); // generate a random number using gen and dist, and set choice to -1 or 1 based on the result

	}
}

#endif