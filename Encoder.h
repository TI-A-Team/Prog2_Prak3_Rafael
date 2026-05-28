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

	    Signal<double> wGap(0.0, Duration::perfectWordGap);
		simulator.addSignal(wGap);


	}

	void encodeLetter(char c)
	{
		std::string morse = reverseTable.at(c);

		std::string::iterator morseIterator;

		for (morseIterator = morse.begin(); morseIterator != morse.end(); morseIterator++)
			{
				if (*morseIterator == '.')
				{
					Signal<double> dot(5.0, Duration::perfectDot);
					Signal<double> sGap(0.0, Duration::perfectSymbolGap);
					simulator.addSignal(dot);
					simulator.addSignal(sGap);
				}
				else
				{
					Signal<double> dash(5.0, Duration::perfectDash);
					Signal<double> sGap(0.0, Duration::perfectSymbolGap);
					simulator.addSignal(dash);
					simulator.addSignal(sGap);
				}
			}

		Signal<double> lGap(0.0, Duration::perfectLetterGap);
		simulator.addSignal(lGap);
	}

	Encoder(Simulator& sim) : simulator(sim)
	{

	}

};



#endif
