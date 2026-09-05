#pragma once
#include <juce_dsp/juce_dsp.h>
#include <vector>
#include "SamplerVoice.h"
#include "Keymap.h"
namespace SampleGod {
class SamplerEngine {
public:
    void renderNextBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages, int startSample, int numSamples);
    void setKeymap(const Keymap& km);
private:
    std::vector<SamplerVoice> voices;
    Keymap keymap;
};
}
