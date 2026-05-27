#ifndef SIGNAL_H
#define SIGNAL_H

#include <iostream>
#include <iomanip>

template <class T> class Signal
{
private:

	T value;
	unsigned long duration_ms;

public:

	T getValue() const
	{
		return value;
	}

	void setValue(T value)
	{
		this->value = value;
	}

	unsigned long getDuration() const
	{
		return duration_ms;
	}

	void setDuration(unsigned long duration)
	{
		this->duration_ms = duration;
	}

	Signal(T value, unsigned long duration_ms)
	{
		this->value = value;
		this->duration_ms = duration_ms;
	}

};

template <class T> std::ostream& operator<< (std::ostream& os, const Signal<T>& signal)
{
	os << "Duration: " << std::setfill(' ') << std::setw(4) << signal.getDuration();
	os << " Value: " << std::setfill(' ') << std::setw(4) << std::fixed << std::setprecision(1) << signal.getValue();
	return os;
}


#endif
