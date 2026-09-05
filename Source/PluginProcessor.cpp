#include "PluginProcessor.h"
#include "PluginEditor.h"
namespace SampleGod {
PluginProcessor::PluginProcessor() : AudioProcessor(BusesProperties()
    .withInput("Input", juce::AudioChannelSet::stereo(), true)
    .withOutput("Output", juce::AudioChannelSet::stereo(), true)) {}
PluginProcessor::~PluginProcessor() {}
void PluginProcessor::prepareToPlay(double sr, int bs) { engine.prepare(sr, bs); }
void PluginProcessor::releaseResources() {}
void PluginProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midi) {
    engine.renderNextBlock(buffer, midi, 0, buffer.getNumSamples());
}
juce::AudioProcessorEditor* PluginProcessor::createEditor() { return new PluginEditor(*this); }
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter() { return new SampleGod::PluginProcessor(); }
