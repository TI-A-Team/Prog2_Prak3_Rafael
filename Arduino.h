#ifndef ARDUINO_H
#define ARDUINO_H

#include "Pin.h"
#include "Signal.h"
#include <chrono>
#include <thread>
#include <iostream>

class Arduino
{
private:

	Pin* a0_ptr;
	Pin* a1_ptr;
	bool running;

public:

	unsigned long millis()
	{
		return std::chrono::duration_cast<std::chrono::milliseconds>(
		        std::chrono::system_clock::now().time_since_epoch()
		    ).count();
	}

	unsigned int analogRead(int number)
	{
		switch (number)
		{
		case 0: if (a0_ptr == nullptr)
				{
				return 0;
				}
				return a0_ptr->analogRead();

		case 1: if (a1_ptr == nullptr)
				{
				return 0;
				}
				return a1_ptr->analogRead();

		default: return 0;
		}
	}

	void setup()
	{

	}

	void process()
	{
		std::cout << analogRead(0) << std::endl;

		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}

	void stop()
	{
		running = false;
	}

	void run()
	{
		running = true;

		setup();

		while(running) process();
	}

	void delay(unsigned long duration_ms)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(duration_ms));
	}

	Arduino(Pin* a0_ptr, Pin* a1_ptr)
	{
		this->a0_ptr = a0_ptr;
		this->a1_ptr = a1_ptr;

		running = false;
	}

	Arduino(Pin* a0_ptr)
	{
		this->a0_ptr = a0_ptr;
		this->a1_ptr = nullptr;

		running = false;
	}

	Arduino()
	{
		this->a0_ptr = nullptr;
		this->a1_ptr = nullptr;

		running = false;
	}


};

#endif
