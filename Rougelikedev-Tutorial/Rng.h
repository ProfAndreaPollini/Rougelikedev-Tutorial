#pragma once

#include <random>




class Rng
{
public:
	static Rng& Instance()
	{
		static Rng instance;
		return instance;
	}
	Rng(Rng const &) = delete;
	void operator=(Rng const&) =delete;

	auto random()
	{
		return dist_(rng_);
	}

	auto RandomIntInRange(int min, int max)
	{
		const std::uniform_int_distribution<int> dist_int_range_{min,max};
		return dist_int_range_(rng_);
	}
	
private:
	Rng() : rng_{std::random_device()()},dist_{0.0,1.0}
	{
		
	}
	std::mt19937 rng_;
	std::uniform_real_distribution<double> dist_;
	
};

