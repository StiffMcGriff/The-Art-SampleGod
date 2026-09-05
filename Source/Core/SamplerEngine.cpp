#include "SamplerEngine.h"
#include <algorithm>
namespace SampleGod {
void SamplerEngine::prepare(double sr, int) { sampleRate = sr; voices.clear(); for (int i = 0; i < maxVoices; ++i) voices.push_back(std::make_unique<SamplerVoice>()); }
void SamplerEngine::setKeymap(const Keymap& km) { keymap = km; }
void SamplerEngine::setLibrary(SampleLibrary* lib) { library = lib; }
void SamplerEngine::noteOn(int midiNote, float velocity) {
    KeyZone zone = keymap.find(midiNote, 64);
    for (auto& v : voices) {
        if (!v->isActive()) {
            // In full implementation load sample from library by zone.sampleId
            v->noteOn(nullptr, midiNote, velocity); // stub: full load from library
            break;
        }
    }
}
void SamplerEngine::noteOff(int midiNote) {
    for (auto& v : voices) {
        if (v->isActive()) v->noteOff();
    }
}
void SamplerEngine::renderNextBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midi, int startSample, int numSamples) {
    buffer.clear();
    for (auto it = midi.begin(); it != midi.end(); ++it) {
        auto msg = it->getMessage();
        if (msg.isNoteOn()) noteOn(msg.getNoteNumber(), msg.getVelocity() / 127.0f);
        else if (msg.isNoteOff()) noteOff(msg.getNoteNumber());
    }
    for (auto& v : voices) {
        if (v->isActive()) v->renderNextBlock(buffer, startSample, numSamples);
    }
}
}
