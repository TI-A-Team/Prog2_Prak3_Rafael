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
		size_t sCount = 0;

		    for (char symbol : morse)
		    {
		        if (symbol == '.')
		        {
		            Signal<double> s(5.0, Duration::perfectDot);
		            simulator.addSignal(s);
		        }
		        else
		        {
		            Signal<double> s(5.0, Duration::perfectDash);
		            simulator.addSignal(s);
		        }

		        sCount++;
		        if (sCount < morse.size())
		        {
		        	Signal<double> sGap(0.0, Duration::perfectSymbolGap);
		            simulator.addSignal(sGap);
		        }
		        else
		        {
		        	Signal<double> lGap(0.0, Duration::perfectLetterGap);
					simulator.addSignal(lGap);
		        }
		    }
	}

	Encoder(Simulator& sim) : simulator(sim)
	{

	}

};



#endif
