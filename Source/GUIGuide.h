/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.2.4

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_B3C94D25B95B4EE6__
#define __JUCE_HEADER_B3C94D25B95B4EE6__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class GUIGuide  : public Component,
                  public SliderListener,
                  public ButtonListener,
                  public LabelListener
{
public:
    //==============================================================================
    GUIGuide ();
    ~GUIGuide();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void labelTextChanged (Label* labelThatHasChanged) override;
    void mouseDown (const MouseEvent& e) override;
    void mouseDrag (const MouseEvent& e) override;
    void mouseUp (const MouseEvent& e) override;
    void mouseDoubleClick (const MouseEvent& e) override;
    void mouseWheelMove (const MouseEvent& e, const MouseWheelDetails& wheel) override;
    bool keyPressed (const KeyPress& key) override;
    bool keyStateChanged (const bool isKeyDown) override;
    void modifierKeysChanged (const ModifierKeys& modifiers) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

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
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GUIGuide)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_B3C94D25B95B4EE6__
