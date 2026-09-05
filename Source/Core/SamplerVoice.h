#pragma once
#include <juce_dsp/juce_dsp.h>
#include "Sample.h"
namespace SampleGod {
class SamplerVoice {
public:
    bool isActive() const { return active; }
    void noteOn(const Sample* s, int midiNote, float velocity);
    void noteOff();
    void renderNextBlock(juce::AudioBuffer<float>& buffer, int startSample, int numSamples);
private:
    const Sample* sample = nullptr;
    bool active = false;
    int midiNote = 0;
    float velocity = 0.f;
    juce::ADSR adsr;
    int position = 0;
};
}
