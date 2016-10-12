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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "GUIGuide.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
GUIGuide::GUIGuide ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (fineTuneSlider = new Slider ("Fine Tune Slider"));
    fineTuneSlider->setRange (0, 1, 0);
    fineTuneSlider->setSliderStyle (Slider::LinearHorizontal);
    fineTuneSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    fineTuneSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    fineTuneSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    fineTuneSlider->addListener (this);

    addAndMakeVisible (coarseTuneSlider = new Slider ("Coarse Tune Slider"));
    coarseTuneSlider->setRange (1, 10, 1);
    coarseTuneSlider->setSliderStyle (Slider::LinearHorizontal);
    coarseTuneSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    coarseTuneSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    coarseTuneSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    coarseTuneSlider->addListener (this);

    addAndMakeVisible (modComplSlider = new Slider ("Modulator Complexity Slider"));
    modComplSlider->setRange (-20, 20, 0.1);
    modComplSlider->setSliderStyle (Slider::LinearHorizontal);
    modComplSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    modComplSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    modComplSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    modComplSlider->addListener (this);

    addAndMakeVisible (carCompSlider = new Slider ("Carrier Complexity Slider"));
    carCompSlider->setRange (-20, 20, 0.1);
    carCompSlider->setSliderStyle (Slider::LinearHorizontal);
    carCompSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    carCompSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    carCompSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    carCompSlider->addListener (this);

    addAndMakeVisible (noteLabel = new Label ("Note Label",
                                              TRANS("Note\n")));
    noteLabel->setFont (Font (32.50f, Font::plain));
    noteLabel->setJustificationType (Justification::centred);
    noteLabel->setEditable (false, false, false);
    noteLabel->setColour (TextEditor::textColourId, Colours::black);
    noteLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (attackSlider = new Slider ("Attack Slider"));
    attackSlider->setRange (1, 300, 1);
    attackSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    attackSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    attackSlider->setColour (Slider::textBoxTextColourId, Colour (0xff6a6a6a));
    attackSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    attackSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    attackSlider->addListener (this);

    addAndMakeVisible (decaySlider = new Slider ("Decay Slider"));
    decaySlider->setRange (1, 300, 1);
    decaySlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    decaySlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    decaySlider->setColour (Slider::textBoxTextColourId, Colour (0xff6a6a6a));
    decaySlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    decaySlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    decaySlider->addListener (this);

    addAndMakeVisible (sustainSlider = new Slider ("Sustain Slider"));
    sustainSlider->setRange (-60, 0, 1);
    sustainSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    sustainSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    sustainSlider->setColour (Slider::textBoxTextColourId, Colour (0xff6a6a6a));
    sustainSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    sustainSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    sustainSlider->addListener (this);

    addAndMakeVisible (releaseSlider = new Slider ("Release Slider"));
    releaseSlider->setRange (1, 2000, 1);
    releaseSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    releaseSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    releaseSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    releaseSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    releaseSlider->addListener (this);

    addAndMakeVisible (modAttackSlider = new Slider ("Modulator Attack Slider"));
    modAttackSlider->setRange (1, 300, 1);
    modAttackSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    modAttackSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    modAttackSlider->setColour (Slider::textBoxTextColourId, Colour (0xff6a6a6a));
    modAttackSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    modAttackSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    modAttackSlider->addListener (this);

    addAndMakeVisible (modDecaySlider = new Slider ("Modulator Decay Slider"));
    modDecaySlider->setRange (1, 300, 1);
    modDecaySlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    modDecaySlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    modDecaySlider->setColour (Slider::textBoxTextColourId, Colour (0xff6a6a6a));
    modDecaySlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    modDecaySlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    modDecaySlider->addListener (this);

    addAndMakeVisible (modSustainSlider = new Slider ("Modulator Sustain Slider"));
    modSustainSlider->setRange (-60, 0, 1);
    modSustainSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    modSustainSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    modSustainSlider->setColour (Slider::textBoxTextColourId, Colour (0xff6a6a6a));
    modSustainSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    modSustainSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    modSustainSlider->addListener (this);

    addAndMakeVisible (modReleaseSlider = new Slider ("Modulator Release Slider"));
    modReleaseSlider->setRange (1, 2000, 1);
    modReleaseSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    modReleaseSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    modReleaseSlider->setColour (Slider::textBoxTextColourId, Colour (0xff6a6a6a));
    modReleaseSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    modReleaseSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    modReleaseSlider->addListener (this);

    addAndMakeVisible (modLevelSlider = new Slider ("Modulator Level Slider"));
    modLevelSlider->setRange (-60, 60, 1);
    modLevelSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    modLevelSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    modLevelSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    modLevelSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    modLevelSlider->addListener (this);

    addAndMakeVisible (levelSlider = new Slider ("Level Slider"));
    levelSlider->setRange (-60, 0, 1);
    levelSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    levelSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    levelSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    levelSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    levelSlider->addListener (this);

    addAndMakeVisible (discreteFreqButton = new ToggleButton ("Discrete Frequency Button"));
    discreteFreqButton->setButtonText (TRANS("Discrete Frequency"));
    discreteFreqButton->addListener (this);
    discreteFreqButton->setColour (ToggleButton::textColourId, Colour (0xff6a6a6a));

    addAndMakeVisible (breathButton = new ToggleButton ("BreathButton"));
    breathButton->setButtonText (TRANS("breath"));
    breathButton->addListener (this);
    breathButton->setColour (ToggleButton::textColourId, Colour (0xff6a6a6a));

    addAndMakeVisible (octaveSlider = new Slider ("Octave Slider"));
    octaveSlider->setRange (0, 10, 0);
    octaveSlider->setSliderStyle (Slider::IncDecButtons);
    octaveSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    octaveSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    octaveSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    octaveSlider->addListener (this);

    addAndMakeVisible (mainLevelLabel = new Label ("Main Level Label",
                                                   TRANS("label text")));
    mainLevelLabel->setFont (Font (15.00f, Font::plain));
    mainLevelLabel->setJustificationType (Justification::centred);
    mainLevelLabel->setEditable (true, true, false);
    mainLevelLabel->setColour (Label::textColourId, Colour (0xff6a6a6a));
    mainLevelLabel->setColour (TextEditor::textColourId, Colours::black);
    mainLevelLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    mainLevelLabel->addListener (this);

    addAndMakeVisible (modLevelLabel = new Label ("Modulator Level Label",
                                                  TRANS("label text")));
    modLevelLabel->setFont (Font (12.00f, Font::plain));
    modLevelLabel->setJustificationType (Justification::centredLeft);
    modLevelLabel->setEditable (true, true, false);
    modLevelLabel->setColour (Label::textColourId, Colour (0xff6a6a6a));
    modLevelLabel->setColour (TextEditor::textColourId, Colours::black);
    modLevelLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    modLevelLabel->addListener (this);

    addAndMakeVisible (mainDistLabel = new Label ("Main Distortion Label",
                                                  TRANS("label text")));
    mainDistLabel->setFont (Font (15.00f, Font::plain));
    mainDistLabel->setJustificationType (Justification::centred);
    mainDistLabel->setEditable (true, true, false);
    mainDistLabel->setColour (Label::textColourId, Colour (0xff6a6a6a));
    mainDistLabel->setColour (TextEditor::textColourId, Colours::black);
    mainDistLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    mainDistLabel->addListener (this);

    addAndMakeVisible (modDistLabel = new Label ("Modulator Distortion Label",
                                                 TRANS("label text")));
    modDistLabel->setFont (Font (15.00f, Font::plain));
    modDistLabel->setJustificationType (Justification::centred);
    modDistLabel->setEditable (true, true, false);
    modDistLabel->setColour (Label::textColourId, Colour (0xff6a6a6a));
    modDistLabel->setColour (TextEditor::textColourId, Colours::black);
    modDistLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    modDistLabel->addListener (this);

    addAndMakeVisible (coarseToneLabel = new Label ("Coarse Tone Label",
                                                    TRANS("label text")));
    coarseToneLabel->setFont (Font (15.00f, Font::plain));
    coarseToneLabel->setJustificationType (Justification::centred);
    coarseToneLabel->setEditable (true, true, false);
    coarseToneLabel->setColour (Label::textColourId, Colour (0xff6a6a6a));
    coarseToneLabel->setColour (TextEditor::textColourId, Colours::black);
    coarseToneLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    coarseToneLabel->addListener (this);

    addAndMakeVisible (fineToneLabel = new Label ("Fine Tone Label",
                                                  TRANS("label text")));
    fineToneLabel->setFont (Font (15.00f, Font::plain));
    fineToneLabel->setJustificationType (Justification::centred);
    fineToneLabel->setEditable (true, true, false);
    fineToneLabel->setColour (Label::textColourId, Colour (0xff6a6a6a));
    fineToneLabel->setColour (TextEditor::textColourId, Colours::black);
    fineToneLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    fineToneLabel->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

GUIGuide::~GUIGuide()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    fineTuneSlider = nullptr;
    coarseTuneSlider = nullptr;
    modComplSlider = nullptr;
    carCompSlider = nullptr;
    noteLabel = nullptr;
    attackSlider = nullptr;
    decaySlider = nullptr;
    sustainSlider = nullptr;
    releaseSlider = nullptr;
    modAttackSlider = nullptr;
    modDecaySlider = nullptr;
    modSustainSlider = nullptr;
    modReleaseSlider = nullptr;
    modLevelSlider = nullptr;
    levelSlider = nullptr;
    discreteFreqButton = nullptr;
    breathButton = nullptr;
    octaveSlider = nullptr;
    mainLevelLabel = nullptr;
    modLevelLabel = nullptr;
    mainDistLabel = nullptr;
    modDistLabel = nullptr;
    coarseToneLabel = nullptr;
    fineToneLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void GUIGuide::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    g.setColour (Colours::black);
    g.setFont (Font (40.90f, Font::plain));
    g.drawText (TRANS("FM Synth"),
                23, 23, 217, 69,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (16.20f, Font::plain));
    g.drawText (TRANS("JuanSaudio"),
                135, 71, 105, 24,
                Justification::centred, true);

    g.setColour (Colour (0xff2a60a5));
    g.fillRect (16, 312, 569, 72);

    g.setColour (Colour (0xff0061dd));
    g.fillRect (40, 312, 24, 72);

    g.setColour (Colour (0x93aeaeae));
    g.strokePath (internalPath1, PathStrokeType (1.000f, PathStrokeType::curved));

    g.setColour (Colour (0x93aeaeae));
    g.strokePath (internalPath2, PathStrokeType (1.000f, PathStrokeType::curved));

    g.setColour (Colour (0xff6a6a6a));
    g.setFont (Font (10.00f, Font::plain));
    g.drawText (TRANS("ADSR"),
                7, 209, 53, 19,
                Justification::centred, true);

    g.setColour (Colour (0xff6a6a6a));
    g.setFont (Font (10.00f, Font::plain));
    g.drawText (TRANS("mod ADSR"),
                519, 209, 76, 19,
                Justification::centred, true);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void GUIGuide::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    fineTuneSlider->setBounds (408, 40, 150, 32);
    coarseTuneSlider->setBounds (408, 104, 150, 32);
    modComplSlider->setBounds (408, 160, 150, 32);
    carCompSlider->setBounds (32, 160, 150, 32);
    noteLabel->setBounds (32, 112, 144, 40);
    attackSlider->setBounds (32, 232, 40, 40);
    decaySlider->setBounds (80, 232, 40, 40);
    sustainSlider->setBounds (128, 232, 40, 40);
    releaseSlider->setBounds (176, 232, 40, 40);
    modAttackSlider->setBounds (384, 232, 40, 40);
    modDecaySlider->setBounds (432, 232, 40, 40);
    modSustainSlider->setBounds (480, 232, 40, 40);
    modReleaseSlider->setBounds (528, 232, 40, 40);
    modLevelSlider->setBounds (272, 56, 56, 48);
    levelSlider->setBounds (224, 128, 152, 144);
    discreteFreqButton->setBounds (16, 288, 150, 24);
    breathButton->setBounds (520, 288, 64, 24);
    octaveSlider->setBounds (520, 316, 63, 16);
    mainLevelLabel->setBounds (264, 248, 72, 24);
    modLevelLabel->setBounds (272, 96, 56, 24);
    mainDistLabel->setBounds (72, 184, 72, 24);
    modDistLabel->setBounds (448, 184, 72, 24);
    coarseToneLabel->setBounds (448, 128, 72, 24);
    fineToneLabel->setBounds (448, 64, 72, 24);
    internalPath1.clear();
    internalPath1.startNewSubPath (18.0f, 212.0f);
    internalPath1.lineTo (210.0f, 212.0f);
    internalPath1.lineTo (242.0f, 276.0f);
    internalPath1.lineTo (178.0f, 276.0f);

    internalPath2.clear();
    internalPath2.startNewSubPath (580.0f, 212.0f);
    internalPath2.lineTo (391.0f, 212.0f);
    internalPath2.lineTo (362.0f, 272.0f);
    internalPath2.lineTo (426.0f, 272.0f);

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void GUIGuide::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == fineTuneSlider)
    {
        //[UserSliderCode_fineTuneSlider] -- add your slider handling code here..
        //[/UserSliderCode_fineTuneSlider]
    }
    else if (sliderThatWasMoved == coarseTuneSlider)
    {
        //[UserSliderCode_coarseTuneSlider] -- add your slider handling code here..
        //[/UserSliderCode_coarseTuneSlider]
    }
    else if (sliderThatWasMoved == modComplSlider)
    {
        //[UserSliderCode_modComplSlider] -- add your slider handling code here..
        //[/UserSliderCode_modComplSlider]
    }
    else if (sliderThatWasMoved == carCompSlider)
    {
        //[UserSliderCode_carCompSlider] -- add your slider handling code here..
        //[/UserSliderCode_carCompSlider]
    }
    else if (sliderThatWasMoved == attackSlider)
    {
        //[UserSliderCode_attackSlider] -- add your slider handling code here..
        //[/UserSliderCode_attackSlider]
    }
    else if (sliderThatWasMoved == decaySlider)
    {
        //[UserSliderCode_decaySlider] -- add your slider handling code here..
        //[/UserSliderCode_decaySlider]
    }
    else if (sliderThatWasMoved == sustainSlider)
    {
        //[UserSliderCode_sustainSlider] -- add your slider handling code here..
        //[/UserSliderCode_sustainSlider]
    }
    else if (sliderThatWasMoved == releaseSlider)
    {
        //[UserSliderCode_releaseSlider] -- add your slider handling code here..
        //[/UserSliderCode_releaseSlider]
    }
    else if (sliderThatWasMoved == modAttackSlider)
    {
        //[UserSliderCode_modAttackSlider] -- add your slider handling code here..
        //[/UserSliderCode_modAttackSlider]
    }
    else if (sliderThatWasMoved == modDecaySlider)
    {
        //[UserSliderCode_modDecaySlider] -- add your slider handling code here..
        //[/UserSliderCode_modDecaySlider]
    }
    else if (sliderThatWasMoved == modSustainSlider)
    {
        //[UserSliderCode_modSustainSlider] -- add your slider handling code here..
        //[/UserSliderCode_modSustainSlider]
    }
    else if (sliderThatWasMoved == modReleaseSlider)
    {
        //[UserSliderCode_modReleaseSlider] -- add your slider handling code here..
        //[/UserSliderCode_modReleaseSlider]
    }
    else if (sliderThatWasMoved == modLevelSlider)
    {
        //[UserSliderCode_modLevelSlider] -- add your slider handling code here..
        //[/UserSliderCode_modLevelSlider]
    }
    else if (sliderThatWasMoved == levelSlider)
    {
        //[UserSliderCode_levelSlider] -- add your slider handling code here..
        //[/UserSliderCode_levelSlider]
    }
    else if (sliderThatWasMoved == octaveSlider)
    {
        //[UserSliderCode_octaveSlider] -- add your slider handling code here..
        //[/UserSliderCode_octaveSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void GUIGuide::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == discreteFreqButton)
    {
        //[UserButtonCode_discreteFreqButton] -- add your button handler code here..
        //[/UserButtonCode_discreteFreqButton]
    }
    else if (buttonThatWasClicked == breathButton)
    {
        //[UserButtonCode_breathButton] -- add your button handler code here..
        //[/UserButtonCode_breathButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void GUIGuide::labelTextChanged (Label* labelThatHasChanged)
{
    //[UserlabelTextChanged_Pre]
    //[/UserlabelTextChanged_Pre]

    if (labelThatHasChanged == mainLevelLabel)
    {
        //[UserLabelCode_mainLevelLabel] -- add your label text handling code here..
        //[/UserLabelCode_mainLevelLabel]
    }
    else if (labelThatHasChanged == modLevelLabel)
    {
        //[UserLabelCode_modLevelLabel] -- add your label text handling code here..
        //[/UserLabelCode_modLevelLabel]
    }
    else if (labelThatHasChanged == mainDistLabel)
    {
        //[UserLabelCode_mainDistLabel] -- add your label text handling code here..
        //[/UserLabelCode_mainDistLabel]
    }
    else if (labelThatHasChanged == modDistLabel)
    {
        //[UserLabelCode_modDistLabel] -- add your label text handling code here..
        //[/UserLabelCode_modDistLabel]
    }
    else if (labelThatHasChanged == coarseToneLabel)
    {
        //[UserLabelCode_coarseToneLabel] -- add your label text handling code here..
        //[/UserLabelCode_coarseToneLabel]
    }
    else if (labelThatHasChanged == fineToneLabel)
    {
        //[UserLabelCode_fineToneLabel] -- add your label text handling code here..
        //[/UserLabelCode_fineToneLabel]
    }

    //[UserlabelTextChanged_Post]
    //[/UserlabelTextChanged_Post]
}

void GUIGuide::mouseDown (const MouseEvent& e)
{
    //[UserCode_mouseDown] -- Add your code here...
    //[/UserCode_mouseDown]
}

void GUIGuide::mouseDrag (const MouseEvent& e)
{
    //[UserCode_mouseDrag] -- Add your code here...
    //[/UserCode_mouseDrag]
}

void GUIGuide::mouseUp (const MouseEvent& e)
{
    //[UserCode_mouseUp] -- Add your code here...
    //[/UserCode_mouseUp]
}

void GUIGuide::mouseDoubleClick (const MouseEvent& e)
{
    //[UserCode_mouseDoubleClick] -- Add your code here...
    //[/UserCode_mouseDoubleClick]
}

void GUIGuide::mouseWheelMove (const MouseEvent& e, const MouseWheelDetails& wheel)
{
    //[UserCode_mouseWheelMove] -- Add your code here...
    //[/UserCode_mouseWheelMove]
}

bool GUIGuide::keyPressed (const KeyPress& key)
{
    //[UserCode_keyPressed] -- Add your code here...
    return false;  // Return true if your handler uses this key event, or false to allow it to be passed-on.
    //[/UserCode_keyPressed]
}

bool GUIGuide::keyStateChanged (const bool isKeyDown)
{
    //[UserCode_keyStateChanged] -- Add your code here...
    return false;  // Return true if your handler uses this key event, or false to allow it to be passed-on.
    //[/UserCode_keyStateChanged]
}

void GUIGuide::modifierKeysChanged (const ModifierKeys& modifiers)
{
    //[UserCode_modifierKeysChanged] -- Add your code here...
    //[/UserCode_modifierKeysChanged]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="GUIGuide" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="600" initialHeight="400">
  <METHODS>
    <METHOD name="keyPressed (const KeyPress&amp; key)"/>
    <METHOD name="keyStateChanged (const bool isKeyDown)"/>
    <METHOD name="modifierKeysChanged (const ModifierKeys&amp; modifiers)"/>
    <METHOD name="mouseUp (const MouseEvent&amp; e)"/>
    <METHOD name="mouseDrag (const MouseEvent&amp; e)"/>
    <METHOD name="mouseDown (const MouseEvent&amp; e)"/>
    <METHOD name="mouseDoubleClick (const MouseEvent&amp; e)"/>
    <METHOD name="mouseWheelMove (const MouseEvent&amp; e, const MouseWheelDetails&amp; wheel)"/>
  </METHODS>
  <BACKGROUND backgroundColour="ffffffff">
    <TEXT pos="23 23 217 69" fill="solid: ff000000" hasStroke="0" text="FM Synth"
          fontname="Default font" fontsize="40.899999999999998579" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="135 71 105 24" fill="solid: ff000000" hasStroke="0" text="JuanSaudio"
          fontname="Default font" fontsize="16.199999999999999289" bold="0"
          italic="0" justification="36"/>
    <RECT pos="16 312 569 72" fill="solid: ff2a60a5" hasStroke="0"/>
    <RECT pos="40 312 24 72" fill="solid: ff0061dd" hasStroke="0"/>
    <PATH pos="0 0 100 100" fill="solid: 972aa5" hasStroke="1" stroke="1, curved, butt"
          strokeColour="solid: 93aeaeae" nonZeroWinding="1">s 18 212 l 210 212 l 242 276 l 178 276</PATH>
    <PATH pos="0 0 100 100" fill="solid: 972aa5" hasStroke="1" stroke="1, curved, butt"
          strokeColour="solid: 93aeaeae" nonZeroWinding="1">s 580 212 l 391 212 l 362 272 l 426 272</PATH>
    <TEXT pos="7 209 53 19" fill="solid: ff6a6a6a" hasStroke="0" text="ADSR"
          fontname="Default font" fontsize="10" bold="0" italic="0" justification="36"/>
    <TEXT pos="519 209 76 19" fill="solid: ff6a6a6a" hasStroke="0" text="mod ADSR"
          fontname="Default font" fontsize="10" bold="0" italic="0" justification="36"/>
  </BACKGROUND>
  <SLIDER name="Fine Tune Slider" id="92756b3a00882996" memberName="fineTuneSlider"
          virtualName="" explicitFocusOrder="0" pos="408 40 150 32" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="1" int="0" style="LinearHorizontal"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="Coarse Tune Slider" id="fe6135d501747bba" memberName="coarseTuneSlider"
          virtualName="" explicitFocusOrder="0" pos="408 104 150 32" textboxbkgd="ffffff"
          textboxoutline="808080" min="1" max="10" int="1" style="LinearHorizontal"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="Modulator Complexity Slider" id="e5535ccc5938c142" memberName="modComplSlider"
          virtualName="" explicitFocusOrder="0" pos="408 160 150 32" textboxbkgd="ffffff"
          textboxoutline="808080" min="-20" max="20" int="0.10000000000000000555"
          style="LinearHorizontal" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="Carrier Complexity Slider" id="ea729d0d6982aead" memberName="carCompSlider"
          virtualName="" explicitFocusOrder="0" pos="32 160 150 32" textboxbkgd="ffffff"
          textboxoutline="808080" min="-20" max="20" int="0.10000000000000000555"
          style="LinearHorizontal" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <LABEL name="Note Label" id="6c05d3781e86d6af" memberName="noteLabel"
         virtualName="" explicitFocusOrder="0" pos="32 112 144 40" edTextCol="ff000000"
         edBkgCol="0" labelText="Note&#10;" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="32.5"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="Attack Slider" id="e137188742fdd450" memberName="attackSlider"
          virtualName="" explicitFocusOrder="0" pos="32 232 40 40" textboxtext="ff6a6a6a"
          textboxbkgd="ffffff" textboxoutline="808080" min="1" max="300"
          int="1" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="Decay Slider" id="d12c5f6843d85770" memberName="decaySlider"
          virtualName="" explicitFocusOrder="0" pos="80 232 40 40" textboxtext="ff6a6a6a"
          textboxbkgd="ffffff" textboxoutline="808080" min="1" max="300"
          int="1" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="Sustain Slider" id="124caa4c49195cd9" memberName="sustainSlider"
          virtualName="" explicitFocusOrder="0" pos="128 232 40 40" textboxtext="ff6a6a6a"
          textboxbkgd="ffffff" textboxoutline="808080" min="-60" max="0"
          int="1" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="Release Slider" id="77b157bbc735cb14" memberName="releaseSlider"
          virtualName="" explicitFocusOrder="0" pos="176 232 40 40" textboxbkgd="ffffff"
          textboxoutline="808080" min="1" max="2000" int="1" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="Modulator Attack Slider" id="3aa49424bfd5daf5" memberName="modAttackSlider"
          virtualName="" explicitFocusOrder="0" pos="384 232 40 40" textboxtext="ff6a6a6a"
          textboxbkgd="ffffff" textboxoutline="808080" min="1" max="300"
          int="1" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="Modulator Decay Slider" id="bbf4d245d7dbd56a" memberName="modDecaySlider"
          virtualName="" explicitFocusOrder="0" pos="432 232 40 40" textboxtext="ff6a6a6a"
          textboxbkgd="ffffff" textboxoutline="808080" min="1" max="300"
          int="1" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="Modulator Sustain Slider" id="4489be8cbeac19a3" memberName="modSustainSlider"
          virtualName="" explicitFocusOrder="0" pos="480 232 40 40" textboxtext="ff6a6a6a"
          textboxbkgd="ffffff" textboxoutline="808080" min="-60" max="0"
          int="1" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="Modulator Release Slider" id="8623b7bce93fae0d" memberName="modReleaseSlider"
          virtualName="" explicitFocusOrder="0" pos="528 232 40 40" textboxtext="ff6a6a6a"
          textboxbkgd="ffffff" textboxoutline="808080" min="1" max="2000"
          int="1" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="Modulator Level Slider" id="199c1e43dc6824a0" memberName="modLevelSlider"
          virtualName="" explicitFocusOrder="0" pos="272 56 56 48" textboxbkgd="ffffff"
          textboxoutline="808080" min="-60" max="60" int="1" style="RotaryHorizontalVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="Level Slider" id="e52d472add895db2" memberName="levelSlider"
          virtualName="" explicitFocusOrder="0" pos="224 128 152 144" textboxbkgd="ffffff"
          textboxoutline="808080" min="-60" max="0" int="1" style="RotaryHorizontalVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <TOGGLEBUTTON name="Discrete Frequency Button" id="49aa01bebe140909" memberName="discreteFreqButton"
                virtualName="" explicitFocusOrder="0" pos="16 288 150 24" txtcol="ff6a6a6a"
                buttonText="Discrete Frequency" connectedEdges="0" needsCallback="1"
                radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="BreathButton" id="4727cee0d9805170" memberName="breathButton"
                virtualName="" explicitFocusOrder="0" pos="520 288 64 24" txtcol="ff6a6a6a"
                buttonText="breath" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <SLIDER name="Octave Slider" id="7dca53270abdb447" memberName="octaveSlider"
          virtualName="" explicitFocusOrder="0" pos="520 316 63 16" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="10" int="0" style="IncDecButtons"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <LABEL name="Main Level Label" id="103ed08c5f796302" memberName="mainLevelLabel"
         virtualName="" explicitFocusOrder="0" pos="264 248 72 24" textCol="ff6a6a6a"
         edTextCol="ff000000" edBkgCol="0" labelText="label text" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <LABEL name="Modulator Level Label" id="df5c471b96d18c66" memberName="modLevelLabel"
         virtualName="" explicitFocusOrder="0" pos="272 96 56 24" textCol="ff6a6a6a"
         edTextCol="ff000000" edBkgCol="0" labelText="label text" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="0" italic="0" justification="33"/>
  <LABEL name="Main Distortion Label" id="ad2d1eb33a8f9db2" memberName="mainDistLabel"
         virtualName="" explicitFocusOrder="0" pos="72 184 72 24" textCol="ff6a6a6a"
         edTextCol="ff000000" edBkgCol="0" labelText="label text" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <LABEL name="Modulator Distortion Label" id="63d055862b0e1286" memberName="modDistLabel"
         virtualName="" explicitFocusOrder="0" pos="448 184 72 24" textCol="ff6a6a6a"
         edTextCol="ff000000" edBkgCol="0" labelText="label text" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <LABEL name="Coarse Tone Label" id="f0f96a0e192cb13c" memberName="coarseToneLabel"
         virtualName="" explicitFocusOrder="0" pos="448 128 72 24" textCol="ff6a6a6a"
         edTextCol="ff000000" edBkgCol="0" labelText="label text" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <LABEL name="Fine Tone Label" id="493d45c387c93bef" memberName="fineToneLabel"
         virtualName="" explicitFocusOrder="0" pos="448 64 72 24" textCol="ff6a6a6a"
         edTextCol="ff000000" edBkgCol="0" labelText="label text" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
