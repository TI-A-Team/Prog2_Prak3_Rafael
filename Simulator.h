#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <vector>
#include <chrono>
#include <thread>

#include "Pin.h"
#include "Signal.h"

class Simulator
{
private:

	Pin* pin_ptr;
	std::vector<Signal<double>> intervals;

public:

	const std::vector<Signal<double>>& getIntervals() const
	{
	    return intervals;
	}

	void addSignal(Signal <double> signal)
	{
		intervals.push_back(signal);
	}

	void clear()
	{
		intervals.clear();
	}

	void run()
	{
	    for (const auto& interval : intervals)
	    {
	        pin_ptr->setVoltage(interval.getValue());

	        std::this_thread::sleep_for(std::chrono::milliseconds(interval.getDuration()));
	    }

	    intervals.clear();
	}

	Simulator(Pin* pin_ptr)
	{
		this->pin_ptr = pin_ptr;
	}


};


#endif
