/*
  ==============================================================================

    MainProcessor.cpp
    Created: 9 Oct 2016 8:01:57pm
    Author:  Juan David Sierra

  ==============================================================================
*/

#include "MainProcessor.h"
#include "MainEditor.h"


MainProcessor::MainProcessor()
{
	// Initialize Oscillators and Envelopers
	carOsc = new Oscillator(1.0f, 200.0f);
	modOsc = new Oscillator(1.0f, 200.0f);
	genEnv = new Enveloper(1.0f, 1.0f, 0.0f, 1.0f);
	modEnv = new Enveloper(1.0f, 1.0f, 0.0f, 1.0f);
	
	//Initialize GUI
	editor = new MainEditor(this);
	addAndMakeVisible(editor);
	
	
	//Set Some initial Values
	mainGain.setValue(1);
	mainLevel.setValue(1);
	baseFreq.setValue(200);
	
	breathOn = false;
	modTran = 1;
	modTune = 1;
	
	setSize(600, 400);
	setAudioChannels(2, 2);
}
MainProcessor::~MainProcessor(){
	carOsc = nullptr;
	modOsc = nullptr;
	genEnv = nullptr;
	modEnv = nullptr;
	editor = nullptr;
	shutdownAudio();
}

//==========================================================================
//==========================================================================

void MainProcessor::prepareToPlay (int samplesPerBlockExpected, double sampleRate) {
	
	//Pass sample Rate to objects that need it
	carOsc->setSampleRate(sampleRate);
	modOsc->setSampleRate(sampleRate);
	
	genEnv->setSampleRate(sampleRate);
	modEnv->setSampleRate(sampleRate);
	
	
	//set Consntant poles for smoothers
	mainGain.setPole(0.99);
	mainLevel.setPole(0.99);
	baseFreq.setPole(0.99);
	
	modFreqSmoo.setSmooth(0.99);
	modLevelSmoo.setSmooth(0.99);
	gainLSmoo.setSmooth(0.99);
	gainRSmoo.setSmooth(0.99);
}

void MainProcessor::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) {
	
	
	//If breath option is ON calculate the RMS of the input
	//And smooth its value to set the general gain of the Synht
	
	if (breathOn) {
		float newInEnv = bufferToFill.buffer->getRMSLevel(0, bufferToFill.startSample, bufferToFill.numSamples);
		
		inEnv = (inEnv * 9 + newInEnv)/10;
		
		// if The input value is over some value trigger NoteOn
		// if it returns down from that value trigger noteOff
		if (inEnv > 0.05 && !genEnv->isOn()) noteEvent(true);
		if (inEnv < 0.05 && genEnv->isOn()) noteEvent(false);
		mainGain.setValue(5 * inEnv);
	}
	
	//clear input buffer as it is not used after breath analysis
	bufferToFill.clearActiveBufferRegion();
	
	float* const outL = bufferToFill.buffer->getWritePointer(0, bufferToFill.startSample);
	float* const outR = bufferToFill.buffer->getWritePointer(1, bufferToFill.startSample);
	
	const int bufSize = bufferToFill.numSamples;
	
	for (int i = 0; i < bufSize; i++) {
		
		//setSmoothed Carrier Oscilator Frequency for FM
		//the modFreq is multiplied by the index (modLevel)
		//and by the modEnv
		carOsc->setFreq(baseFreq.tick() +
						modOsc->tick() * modLevel.tick() * modEnv->tick());
		outL[i] = carOsc->tick() *
				  genEnv->tick() *
				  mainGain.tick() *
				  mainLevel.tick();
		outR[i] = outL[i];
	}
}

void MainProcessor::releaseResources() {
}

//==============================================================================
void MainProcessor::paint (Graphics& g) {
}

void MainProcessor::resized() {
	editor->setBounds(0, 0, getWidth(), getHeight());
}

//==============================================================================
//==============================================================================

void MainProcessor::setFreq(float newFreq) {
	baseFreq.setValue(newFreq);
	float carFreq = baseFreq.tick();
	float modFreq = carFreq * modTran * modTune;
	
	carOsc->setFreq(carFreq);
	modOsc->setFreq(modFreq);
}

void MainProcessor::setLevel(float newLevelIndB) {
	mainLevel.setValue(Decibels::decibelsToGain(newLevelIndB, -60.0f));
}

void MainProcessor::setModLevel(float newLevelIndB){
	modLevel.setValue(baseFreq.get() * Decibels::decibelsToGain(newLevelIndB, -60.0f));
}

void MainProcessor::setGain(float newGain) {
	mainGain.setValue(Decibels::decibelsToGain(newGain, -60.0f));
}

void MainProcessor::setModTran(float newTran){
	modTran = newTran;
}
void MainProcessor::setModTune(float newTune){
	modTune = newTune;
}

void MainProcessor::noteEvent(bool isOn) {
	if (isOn) {
		modEnv->start();
		genEnv->start();
	} else {
		modEnv->stop();
		genEnv->stop();
	}
}

void MainProcessor::isFreqDiscrete(bool isOn) {
	baseFreq.setPole((isOn ? 0.3 : 0.99));
}

void MainProcessor::isBreathOn(bool isOn) {
	breathOn = isOn;
	mainGain.setPole((isOn ? 0.99 : 0.1));
}


float MainProcessor::getFreq() {
	return baseFreq.get();
}

float MainProcessor::getGain() {
	return genEnv->get();
}

bool MainProcessor::getNoteState(){
	return genEnv->isPlaying();
}

Component* createMainProcessor()     { return new MainProcessor();}
