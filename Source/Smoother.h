/*
  ==============================================================================

    Smoother.h
    Created: 9 Oct 2016 8:03:36pm
    Author:  Juan David Sierra

  ==============================================================================
*/

#ifndef SMOOTHER_H_INCLUDED
#define SMOOTHER_H_INCLUDED


class Smooth{
private:
	double delay,s;
	
public:
	Smooth():delay(0.0),s(0.0){}
	
	~Smooth(){}
	
	// set the smoothing (pole)
	void setSmooth(double smooth){
		s = smooth;
	}
	
	// compute one sample
	double tick(double input){
		double currentSample = input * (1.0-s);
		currentSample = currentSample + delay;
		delay = currentSample * s;
		return currentSample;
	}
};



#endif  // SMOOTHER_H_INCLUDED
