#pragma once
#include <juce_dsp/juce_dsp.h>
#include "Sample.h"
namespace SampleGod {
class SamplerVoice {
public:
    void noteOn(int midiNote, float velocity);
    void renderNextBlock(juce::AudioBuffer<float>& buffer, int startSample, int numSamples);
private:
    Sample sample;
    juce::ADSR adsr;
};
}
