/*
 ==============================================================================
 
 MainProcessor.h
 Created: 9 Oct 2016 8:01:57pm
 Author:  Juan David Sierra
 
 ==============================================================================
 */

#ifndef MAINPROCESSOR_H_INCLUDED
#define MAINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscillator.h"
#include "Enveloper.h"
#include "smoother.h"
#include "SmoothValue.h"


class MainEditor;

class MainProcessor		: public AudioAppComponent
{
	public :
	//==========================================================================
	
	MainProcessor();
	~MainProcessor();
	
	//==========================================================================
	//==========================================================================
	
	void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
	
	void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
	
	void releaseResources() override;
	
	//==========================================================================
	//==========================================================================
	
	void paint (Graphics& g) override;
	void resized() override;
	
	//==========================================================================
	//==========================================================================

	void setFreq(float newFreq);
	void setModLevel(float newLevelIndB);
	void setLevel(float newLevelIndB);
	void setGain(float newGain);

	void setModTran(float newTran);
	void setModTune(float newTune);
	
	void noteEvent(bool isOn);
	
	void isFreqDiscrete(bool isOn);
	void isBreathOn(bool isOn);
	
	//==========================================================================
	//==========================================================================
	
	float getFreq();
	float getGain();
	bool getNoteState();

	//==========================================================================
	//==========================================================================
	
	ScopedPointer<Oscillator> carOsc;
	ScopedPointer<Oscillator> modOsc;
	ScopedPointer<Enveloper> genEnv;
	ScopedPointer<Enveloper> modEnv;
	
private:
	
	SmoothValue mainGain;
	SmoothValue mainLevel;
	SmoothValue modLevel;
	SmoothValue baseFreq;
	
	float inEnv;
	float modFreq;
	float modTran;
	float modTune;
	bool breathOn;
	
	ScopedPointer<MainEditor> editor;
	Smooth modFreqSmoo;
	Smooth modLevelSmoo;
	Smooth gainLSmoo;
	Smooth gainRSmoo;
	
	//==========================================================================
	//==========================================================================
	
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainProcessor)
};


// (This function is called by the app startup code to create our main component)
#endif  // MAINPROCESSOR_H_INCLUDED
