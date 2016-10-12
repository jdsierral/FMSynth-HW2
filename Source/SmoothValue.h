/*
  ==============================================================================

    SmoothValue.h
    Created: 10 Oct 2016 12:27:14am
    Author:  Juan David Sierra

  ==============================================================================
*/

#ifndef SMOOTHVALUE_H_INCLUDED
#define SMOOTHVALUE_H_INCLUDED


class SmoothValue{
public:
	SmoothValue() : delay(0.0), p(0.0) {
	}
	
	~SmoothValue(){}
	
	// set the smoothing (pole)
	void setPole(double newPole){
		p = newPole;
	}
	
	void setValue(double newValue) {
		value = newValue;
	}
	
	// compute one sample
	double tick(){
		double currentSample = value * (1.0 - p);
		currentSample = currentSample + delay;
		delay = currentSample * p;
		return currentSample;
	}
	
	double get(){
		return value;
	}
private:
	double delay, p, value;
};





#endif  // SMOOTHVALUE_H_INCLUDED
