/*
  ==============================================================================

    MainEditor.h
    Created: 9 Oct 2016 8:01:50pm
    Author:  Juan David Sierra

  ==============================================================================
*/

#ifndef MAINEDITOR_H_INCLUDED
#define MAINEDITOR_H_INCLUDED
#include "../JuceLibraryCode/JuceHeader.h"
#include "MainProcessor.h"
#include "SmoothValue.h"
#include "guiStyle.h"

class MainEditor  : public Component,
					public SliderListener,
					public ButtonListener,
					public LabelListener,
					public Timer
{
public:
	//==============================================================================
	MainEditor (MainProcessor* p);
	~MainEditor();
	
	//==============================================================================
	
	void paint (Graphics& g) override;
	void resized() override;
	void sliderValueChanged (Slider* slider) override;
	void buttonClicked (Button* button) override;
	void labelTextChanged (Label* label) override; 
	
	
	void mouseDown (const MouseEvent& e) override;
	void mouseDrag (const MouseEvent& e) override;
	void mouseUp (const MouseEvent&) override;
	void mouseMove (const MouseEvent& e) override;
	
	
	void timerCallback() override;
	
	
	void setGuiLevel(float newGuiLevel);
	void setGuiFreq(float newGuiFreq);

	
private:
	
	int counter;
	SmoothValue guiFreq;
	SmoothValue guiLevel;
	
	int octave = 0;
	const float playSpaceX = 16;
	const float playSpaceY = 312;
	const float playSpaceWidth = 569;
	const float playSpaceHeight = 72;
	
	MainProcessor* processor;
	
	MyLookAndFeel myLookAndFeel;
	//==============================================================================
	ScopedPointer<Slider> fineTuneSlider;
	ScopedPointer<Slider> coarseTuneSlider;
	ScopedPointer<Slider> modComplSlider;
	ScopedPointer<Slider> carCompSlider;
	ScopedPointer<Label> noteLabel;
	ScopedPointer<Slider> attackSlider;
	ScopedPointer<Slider> decaySlider;
	ScopedPointer<Slider> sustainSlider;
	ScopedPointer<Slider> releaseSlider;
	ScopedPointer<Slider> modAttackSlider;
	ScopedPointer<Slider> modDecaySlider;
	ScopedPointer<Slider> modSustainSlider;
	ScopedPointer<Slider> modReleaseSlider;
	ScopedPointer<Slider> modLevelSlider;
	ScopedPointer<Slider> levelSlider;
	ScopedPointer<ToggleButton> discreteFreqButton;
	ScopedPointer<ToggleButton> breathButton;
	ScopedPointer<Slider> octaveSlider;
	ScopedPointer<Label> mainLevelLabel;
	ScopedPointer<Label> modLevelLabel;
	ScopedPointer<Label> mainDistLabel;
	ScopedPointer<Label> modDistLabel;
	ScopedPointer<Label> coarseToneLabel;
	ScopedPointer<Label> fineToneLabel;
	Path internalPath1;
	Path internalPath2;
	
	
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainEditor)
};





#endif  // MAINEDITOR_H_INCLUDED
