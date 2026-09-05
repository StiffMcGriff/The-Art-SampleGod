#pragma once
#include <juce_dsp/juce_dsp.h>
#include <vector>
#include <memory>
#include "SamplerVoice.h"
#include "Keymap.h"
#include "SampleLibrary.h"
namespace SampleGod {
class SamplerEngine {
public:
    void prepare(double sampleRate, int samplesPerBlock);
    void renderNextBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages, int startSample, int numSamples);
    void noteOn(int midiNote, float velocity);
    void noteOff(int midiNote);
    void setKeymap(const Keymap& km);
    void setLibrary(SampleLibrary* lib);
private:
    std::vector<std::unique_ptr<SamplerVoice>> voices;
    static constexpr int maxVoices = 64;
    Keymap keymap;
    SampleLibrary* library = nullptr;
    double sampleRate = 44100.0;
};
}
