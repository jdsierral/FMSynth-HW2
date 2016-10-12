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

	//Function to set BaseFreq, modFreq is set as a
	//multiple of baseFreq in a coarseFactor and a
	//fineFactor. As Coarse is int gives harmonic
	//relationships in contrast fine doesnt
	void setFreq(float newFreq);
	void setModLevel(float newLevelIndB);
	void setLevel(float newLevelIndB);
	void setGain(float newGain);

	void setModTran(float newTran);
	void setModTune(float newTune);
	
	
	//When ever noteEvent is called, both modulator envelope
	// and the general envelope are triggered to start
	void noteEvent(bool isOn);
	
	//Freq can be allowed to move smooth through keyboard
	//sort of portamento
	void isFreqDiscrete(bool isOn);
	
	//Activates Breathh controller so that user can
	//Use mic to modulate the main gain
	void isBreathOn(bool isOn);
	
	//==========================================================================
	//==========================================================================
	
	//Getters for GUI to draw stuff
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
	
	//This object is a holder for a value that is not
	//allowed to change drastically instead of having a s
	//moother for each variable
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
