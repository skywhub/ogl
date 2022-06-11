#pragma once
#include <iostream>

class Logger
{
public:
	template<typename ...T>
	constexpr void Log(T&&... params)
	{
		Log_N(std::forward<T>(params)...);
	}

private:
	template<typename T, typename ...Ts>
	constexpr void Log_N(T&& param, Ts&&... params)
	{
		std::cout << param;
		Log_N(std::forward<Ts>(params)...);
	}
	
	template<typename T>
	constexpr void Log_N(T&& param)
	{
		std::cout << param << std::endl;
	}
};

extern Logger GLogger;

#define LOG(...) GLogger.Log(__FILE__, " ", __LINE__, ":", __VA_ARGS__)
