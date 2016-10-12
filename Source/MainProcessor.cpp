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
	
	carOsc = new Oscillator(1.0f, 200.0f);
	modOsc = new Oscillator(1.0f, 200.0f);
	genEnv = new Enveloper(1.0f, 1.0f, 0.0f, 1.0f);
	modEnv = new Enveloper(1.0f, 1.0f, 0.0f, 1.0f);
	
	editor = new MainEditor(this);
	addAndMakeVisible(editor);
	
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
	carOsc->setSampleRate(sampleRate);
	modOsc->setSampleRate(sampleRate);
	
	genEnv->setSampleRate(sampleRate);
	modEnv->setSampleRate(sampleRate);
	
	mainGain.setPole(0.99);
	mainLevel.setPole(0.99);
	baseFreq.setPole(0.99);
	
	modFreqSmoo.setSmooth(0.99);
	modLevelSmoo.setSmooth(0.99);
	gainLSmoo.setSmooth(0.99);
	gainRSmoo.setSmooth(0.99);
}

void MainProcessor::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) {
	
	if (breathOn) {
		float newInEnv = bufferToFill.buffer->getRMSLevel(0, bufferToFill.startSample, bufferToFill.numSamples);
		
		inEnv = (inEnv * 9 + newInEnv)/10;
		if (inEnv > 0.05 && !genEnv->isOn()) noteEvent(true);
		if (inEnv < 0.05 && genEnv->isOn()) noteEvent(false);
		
		
		mainGain.setValue(5 * inEnv);
		
//		mainGain.setValue(bufferToFill.buffer->getRMSLevel(0, bufferToFill.startSample, bufferToFill.numSamples));
		
		
	}
	
	bufferToFill.clearActiveBufferRegion();
	
	float* const outL = bufferToFill.buffer->getWritePointer(0, bufferToFill.startSample);
	float* const outR = bufferToFill.buffer->getWritePointer(1, bufferToFill.startSample);
	
	const int bufSize = bufferToFill.numSamples;
	
	for (int i = 0; i < bufSize; i++) {
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
	
	//reCheck if transposition and tunning should be done in semitones and cents or in regular multiplication form
	modTran = newTran;
}
void MainProcessor::setModTune(float newTune){
	modTune = newTune;
}

void MainProcessor::noteEvent(bool isOn) {
	if (isOn) {
		modEnv->start();
		genEnv->start();
		std::cout<<"noteOn"<<std::endl;
	} else {
		modEnv->stop();
		genEnv->stop();
		std::cout<<"noteOff"<<std::endl;
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
