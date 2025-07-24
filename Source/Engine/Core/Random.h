#pragma once
#include <cstdlib>

namespace fox {
	namespace random {
		/// <summary>
		/// Generates a random integer value.
		/// </summary>
		/// <returns>A pseudo-random integer value.</returns>
		int getRandomInt() { return rand(); }

		/// <summary>
		/// 
		/// </summary>
		/// <param name="max"></param>
		/// <returns></returns>
		int getRandomInt(int max) { return rand() % max; }
	
		/// <summary>
		/// 
		/// </summary>
		/// <param name="min"></param>
		/// <param name="max"></param>
		/// <returns></returns>
		int getRandomInt(int min, int max) { return min + getRandomInt(max - min + 1); }
		
		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		inline float getRandomFloat() { return rand() / (float)RAND_MAX; }

		// Overload for a range [min, max)
		inline float getRandomFloat(float min, float max) {
			return min + (max - min) * getRandomFloat();
		}
	}
}