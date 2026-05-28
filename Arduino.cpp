//============================================================================
// Name        : Arduino.cpp
// Author      : Rafael Grabolus
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <thread>
#include "Signal.h"
#include "Pin.h"
#include "Simulator.h"
#include "Encoder.h"
#include "Arduino.h"

using namespace std;

int main() {

	Pin p1(1024, 5.0);
	Simulator sim1(&p1);
	Encoder e1(sim1);
	e1.encodeWord("sos");

	bool process = 0;


	if (process)
	{
		Arduino a1(&p1);
		std::thread t1(&Arduino::run, &a1);
		a1.delay(500);

		std::thread t2(&Simulator::run, &sim1);
		t2.join();

		a1.stop();
		t1.join();

	}
	else
	{
		for (const auto& signal : sim1.getIntervals())
		    std::cout << signal << "\n";
	}




	return 0;
}
