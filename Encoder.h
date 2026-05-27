#ifndef ENCODER_H
#define ENCODER_H

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

#include "Configuration.h"
#include "Simulator.h"
#include "Signal.h"


class Encoder
{
private:

	Simulator& simulator;

public:

	void encodeWord(std::string message)
	{

		std::string::iterator msgIterator;

	    for (msgIterator = message.begin(); msgIterator != message.end(); msgIterator++)
	    {
	        if (*msgIterator >= 'a' && *msgIterator <= 'z') *msgIterator -= 32;

	        encodeLetter(*msgIterator);
	    }
	}

	void encodeLetter(char c)
	{
		std::string morse = reverseTable.at(c);

		std::string::iterator morseIterator;

		for (morseIterator = morse.begin(); morseIterator != morse.end(); morseIterator++)
			{
				if (*morseIterator == '.')
				{
					Signal<double> s(5.0, Duration::perfectDot);
					simulator.addSignal(s);
				}
				else
				{
					Signal<double> s(0.0, Duration::perfectDash);
					simulator.addSignal(s);
				}
			}
	}

};



#endif
