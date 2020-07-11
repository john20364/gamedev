#ifndef _RANDOM_UTIL_H_
#define _RANDOM_UTIL_H_
#include <random>

namespace su {
//	std::default_random_engine generator(std::random_device{}());
//	std::uniform_int_distribution<int> distribution(0, 3);
//	auto generate = std::bind (distribution, generator);
	class RandomFloat {
	public:
		RandomFloat(double max) : 
			generator(std::default_random_engine(std::random_device{}())),
			distribution(std::uniform_real_distribution<double>(0.0, max)) {
		}

		RandomFloat(double min, double max) : 
			generator(std::default_random_engine(std::random_device{}())),
			distribution(std::uniform_real_distribution<double>(min, max)) {
		}

		double generate() {
			return distribution(generator);
		}	

	private:
		std::default_random_engine generator;
		std::uniform_real_distribution<double> distribution;
	};

	class Random {
	public:
		Random(int max) : 
			generator(std::default_random_engine(std::random_device{}())),
			distribution(std::uniform_int_distribution<int>(0, max)) {
		}

		Random(int min, int max) : 
			generator(std::default_random_engine(std::random_device{}())),
			distribution(std::uniform_int_distribution<int>(min, max)) {
		}

		int generate() {
			return distribution(generator);
		}	

	private:
		std::default_random_engine generator;
		std::uniform_int_distribution<int> distribution;
	};

	class NormalDistribution {
	public:
		NormalDistribution(double mean, double deviation) :
			generator(std::default_random_engine(std::random_device{}())),
			distribution(std::normal_distribution<double>(mean, deviation)) {
		}

		double generate() {
			return distribution(generator);
		}	

	private:
		std::default_random_engine generator;
		std::normal_distribution<double> distribution;
	};
}
#endif
