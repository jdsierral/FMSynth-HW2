/*
 ==============================================================================
 
	MainEditor.cpp
	Created: 9 Oct 2016 8:01:50pm
	Author:  Juan David Sierra
 
 ==============================================================================
 */

#include "MainEditor.h"


MainEditor::MainEditor (MainProcessor* p)
: processor(p)
{
	//Creation of all of the sliders
	
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
	modLevelSlider->setRange (-60, 60, 0);
	modLevelSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
	modLevelSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
	modLevelSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
	modLevelSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
	modLevelSlider->addListener (this);
	
	addAndMakeVisible (levelSlider = new Slider ("Level Slider"));
	levelSlider->setRange (-60, 0, 0);
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
	octaveSlider->setRange (-10, 10, 1);
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
	
	//==========================================================================
	
	//sets general look and feel
	setLookAndFeel(&myLookAndFeel);
	//starts timer for gui operations at 50ms rate
	startTimer(50);
	
	guiFreq.setPole(0.99);
	guiLevel.setPole(0.99);
	//==========================================================================
	
	setSize (600, 400);
	
}

MainEditor::~MainEditor()
{
	
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
	
}

//==============================================================================
void MainEditor::paint (Graphics& g)
{
	//general painting for GUI
	g.fillAll (Colours::white);
	
	g.setColour (Colours::black);
	g.setFont (Font (32.90f, Font::plain));
	g.drawText (TRANS("FM Synth"),
				31, 27, 185, 45,
				Justification::centred, true);
	
	g.setColour (Colours::black);
	g.setFont (Font (16.20f, Font::plain));
	g.drawText (TRANS("JuanSaudio"),
				92, 60, 105, 24,
				Justification::centred, true);
	Colour dark(Colour(0xff2a60a5));
	Colour light(Colour(0xff0061dd));
	
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
	
	
	//color the keyboard down at the gui
	g.setColour (light);
	g.fillRect (playSpaceX, playSpaceY, playSpaceWidth, playSpaceHeight);
	
	g.setColour (Colour (dark));
	for (int i = 0; i <= 12; i++) {
		if (i == 1 || i == 3 || i == 6 || i == 8 || i == 10) {
			g.fillRect (playSpaceX + i * playSpaceWidth/13,
						playSpaceY,
						playSpaceWidth/13,
						playSpaceHeight);
		}
	}
	
	const float centerX = levelSlider->getX() + levelSlider->getWidth()/2.0f;
	const float centerY = - 3 + levelSlider->getY() + levelSlider->getHeight()/2.0f;
	
	
	//Generate signal-like wave starting from center of main gainSlider
	
	g.setColour(Colour (0xFF8C8C8C));
	for (int i = 0; i < 20; i++){
		int p = jmax(counter - guiFreq.tick() * i, 0.0);
		g.setOpacity(guiLevel.tick() * (jmax(1 - p/100.0f, 0.0f)));
		g.drawEllipse(centerX - p/2.0f, centerY - p/2.0f, p, p, 2);
	}
}

void MainEditor::resized()
{
	
	
	fineTuneSlider->setBounds (408, 40, 150, 32);
	coarseTuneSlider->setBounds (408, 104, 150, 32);
	modComplSlider->setBounds (408, 168, 150, 32);
	carCompSlider->setBounds (32, 168, 150, 32);
	noteLabel->setBounds (32, 112, 144, 40);
	attackSlider->setBounds (32, 232, 40, 40);
	decaySlider->setBounds (80, 232, 40, 40);
	sustainSlider->setBounds (128, 232, 40, 40);
	releaseSlider->setBounds (176, 232, 40, 40);
	modAttackSlider->setBounds (384, 232, 40, 40);
	modDecaySlider->setBounds (432, 232, 40, 40);
	modSustainSlider->setBounds (480, 232, 40, 40);
	modReleaseSlider->setBounds (528, 232, 40, 40);
	modLevelSlider->setBounds (272, 56, 56, 64);
	levelSlider->setBounds (225, 128, 152, 168);
	discreteFreqButton->setBounds (16, 288, 150, 24);
	breathButton->setBounds (520, 288, 64, 24);
	octaveSlider->setBounds (520, 316, 63, 16);
	mainLevelLabel->setBounds (264, 248, 72, 24);
	modLevelLabel->setBounds (272, 105, 56, 24);
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
	
}

void MainEditor::sliderValueChanged (Slider* slider)
{
	
	if (slider == fineTuneSlider)
	{
		processor->setModTune(slider->getValue());
	}
	else if (slider == coarseTuneSlider)
	{
		processor->setModTran(slider->getValue());
	}
	else if (slider == modComplSlider)
	{
		processor->modOsc->setComplexity(slider->getValue());
	}
	else if (slider == carCompSlider)
	{
		processor->carOsc->setComplexity(slider->getValue());
	}
	else if (slider == attackSlider)
	{
		processor->genEnv->setAttackTime(slider->getValue()/1000);
	}
	else if (slider == decaySlider)
	{
		processor->genEnv->setDecayTime(slider->getValue()/1000);
	}
	else if (slider == sustainSlider)
	{
		processor->genEnv->setSustainLevel(slider->getValue());
	}
	else if (slider == releaseSlider)
	{
		processor->genEnv->setReleaseTime(slider->getValue()/1000);
	}
	else if (slider == modAttackSlider)
	{
		processor->modEnv->setAttackTime(slider->getValue()/1000);
	}
	else if (slider == modDecaySlider)
	{
		processor->modEnv->setDecayTime(slider->getValue()/1000);
	}
	else if (slider == modSustainSlider)
	{
		processor->modEnv->setSustainLevel(slider->getValue());
	}
	else if (slider == modReleaseSlider)
	{
		processor->modEnv->setReleaseTime(slider->getValue()/1000);
	}
	else if (slider == modLevelSlider)
	{
		processor->setModLevel(slider->getValue());
	}
	else if (slider == levelSlider)
	{
		processor->setLevel(slider->getValue());
	}
	else if (slider == octaveSlider)
	{
		octave = octaveSlider->getValue();
	}
}

void MainEditor::buttonClicked (Button* button)
{
	if (button == discreteFreqButton)
	{
		processor->isFreqDiscrete(button->getToggleState());
	}
	else if (button == breathButton)
	{
		processor->isBreathOn(button->getToggleState());
	}
}

void MainEditor::labelTextChanged (Label* label)
{
	if (label == mainLevelLabel)
	{
		levelSlider->setValue(label->getText().getDoubleValue());
	}
	else if (label == modLevelLabel)
	{
		modLevelSlider->setValue(label->getText().getDoubleValue());
	}
	else if (label == mainDistLabel)
	{
		carCompSlider->setValue(label->getText().getDoubleValue());
	}
	else if (label == modDistLabel)
	{
		modComplSlider->setValue(label->getText().getDoubleValue());
	}
	else if (label == coarseToneLabel)
	{
		coarseTuneSlider->setValue(label->getText().getDoubleValue());
	}
	else if (label == fineToneLabel)
	{
		fineTuneSlider->setValue(label->getText().getDoubleValue());
	}
}

//==============================================================================

void MainEditor::mouseDown (const MouseEvent& e)
{
	//checks for new freq and gain if mouse is inside box
	if (e.position.x >= playSpaceX && e.position.x <= playSpaceX + playSpaceWidth) {
		if (e.position.y >= playSpaceY && e.position.y <= playSpaceY + playSpaceHeight) {
			processor->noteEvent(true);
			mouseDrag(e);
		}
	}
}

void MainEditor::mouseDrag (const MouseEvent& e)
{
	//generates midi note according to position and transforms it to frequencies
	int midiNote = (int)13 * (e.position.x - playSpaceX)/playSpaceWidth + 60 + 12 * octave;
	
	//sets the note being played to be shown on a label
	noteLabel->setText(MidiMessage::getMidiNoteName(midiNote, true, true, 4), dontSendNotification);
	
	processor->setFreq(MidiMessage::getMidiNoteInHertz(midiNote));
	
	//if breath is not activaded the height will determine the gain
	if (!breathButton->getToggleState()) {
		int level = 20 * (float)((e.position.y - playSpaceY)/playSpaceHeight) - 20;
		processor->setGain(level);
	}
}

void MainEditor::mouseUp (const MouseEvent&)
{
	processor->noteEvent(false);
}

void MainEditor::mouseMove (const MouseEvent& e) {
	//if breath is on there is no need to press the mouse to get new freq
	if (breathButton->getToggleState()) {
		if (e.position.y >= playSpaceY && e.position.y <= playSpaceY + playSpaceHeight) {
			
			int midiNote = (int)13 * (e.position.x - playSpaceX)/playSpaceWidth + 60 + 12 * octave;
			
			noteLabel->setText(MidiMessage::getMidiNoteName(midiNote, true, true, 4), dontSendNotification);
			
			processor->setFreq(MidiMessage::getMidiNoteInHertz(midiNote));
		}
	}
}

void MainEditor::timerCallback() {
	
	//timerCallback for general gui stuff
	//it is called at a relative small rate of 20hz
	
	if (!mainLevelLabel->isMouseOver() && !mainLevelLabel->isBeingEdited()) {
		if(levelSlider->isMouseOverOrDragging())
		{
			mainLevelLabel->setText((String)levelSlider->getValue() + " dB", dontSendNotification);
		}   else    {
			mainLevelLabel->setText("Level", dontSendNotification);
		}
	}
	
	if (!modLevelLabel->isMouseOver() && !modLevelLabel->isBeingEdited()) {
		if(modLevelSlider->isMouseOverOrDragging())
		{
			modLevelLabel->setText((String)modLevelSlider->getValue() + " dB", dontSendNotification);
		}   else    {
			modLevelLabel->setText("FM-ize", dontSendNotification);
		}
	}
	
	if (!coarseToneLabel->isMouseOver() && !coarseToneLabel->isBeingEdited()) {
		if(coarseTuneSlider->isMouseOverOrDragging())
		{
			coarseToneLabel->setText((String)coarseTuneSlider->getValue() + " x", dontSendNotification);
		}   else    {
			coarseToneLabel->setText("Broad FM Rate", dontSendNotification);
		}
	}
	
	if (!fineToneLabel->isMouseOver() && !fineToneLabel->isBeingEdited()) {
		if(fineTuneSlider->isMouseOverOrDragging())
		{
			fineToneLabel->setText((String)fineTuneSlider->getValue() + " x", dontSendNotification);
		}   else    {
			fineToneLabel->setText("Fine FM Rate", dontSendNotification);
		}
	}
	
	
	if (!mainDistLabel->isMouseOver() && !mainDistLabel->isBeingEdited()) {
		if(carCompSlider->isMouseOverOrDragging())
		{
			mainDistLabel->setText((String)(int)carCompSlider->getValue(), dontSendNotification);
		}   else    {
			mainDistLabel->setText("Distortion", dontSendNotification);
		}
	}
	
	if (!modDistLabel->isMouseOver() && !modDistLabel->isBeingEdited()) {
		if(modComplSlider->isMouseOverOrDragging())
		{
			modDistLabel->setText((String)(int)modComplSlider->getValue(), dontSendNotification);
		}   else    {
			modDistLabel->setText("FM Distortion", dontSendNotification);
		}
	}

	//counter for dummy signal being drawn in gui
	counter++;
	if (processor->getNoteState()) {
		setGuiFreq(10000/processor->getFreq());
		setGuiLevel(processor->getGain());
	} else {
		counter = 0;
	}
	repaint();
}


	//gets gui level for duumi signal
void MainEditor::setGuiLevel(float newGuiLevel) {
	guiLevel.setValue(newGuiLevel);
	//	std::cout<<guiLevel.get()<<std::endl;
}

void MainEditor::setGuiFreq(float newGuiFreq) {
	guiFreq.setValue(newGuiFreq);
	//	std::cout<<guiFreq.get()<<std::endl;
}
