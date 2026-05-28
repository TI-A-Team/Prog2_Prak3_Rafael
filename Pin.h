#ifndef PIN_H
#define PIN_H

#include <algorithm>
#include <mutex>
#include <thread>

class Pin
{
private:

	int steps;
	double voltage_v;
	double aref_v;

	mutable std::mutex m;

public:

	double getVoltage() const
	{
		std::lock_guard<std::mutex> lock(m);

		return voltage_v;
	}

	void setVoltage(double voltage_v)
	{
		std::lock_guard<std::mutex> lock(m);

		this->voltage_v = voltage_v;
	}

	unsigned int analogRead()
	{
		int result = static_cast<int>((std::min(voltage_v, aref_v) / aref_v) * steps);
		return std::max(0, std::min(result, steps - 1));
	}

	//2-Parameter Konstruktor
	Pin (int steps, double aref_v)
	{
		this->steps = steps;
		this->aref_v = aref_v;
		this->voltage_v = 0;
	}

	//leerer Konstruktor
	Pin ()
	{
		this->steps = 1024;
		this->aref_v = 5.0;
		this->voltage_v = 0;
	}
};

#endif
