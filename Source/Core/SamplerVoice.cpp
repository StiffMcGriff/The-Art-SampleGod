#include "SamplerVoice.h"
namespace SampleGod {
void SamplerVoice::noteOn(const Sample* s, int note, float vel) {
    sample = s; midiNote = note; velocity = vel; active = true; position = 0;
    juce::ADSR::Parameters p; p.attack = 0.01f; p.decay = 0.1f; p.sustain = 0.7f; p.release = 0.25f;
    adsr.setParameters(p); adsr.noteOn();
}
void SamplerVoice::noteOff() { adsr.noteOff(); }
void SamplerVoice::renderNextBlock(juce::AudioBuffer<float>& buffer, int startSample, int numSamples) {
    if (!active || !sample) return;
    for (int ch = 0; ch < buffer.getNumChannels(); ++ch) {
        float* data = buffer.getWritePointer(ch, startSample);
        for (int i = 0; i < numSamples; ++i) {
            if (position >= sample->buffer.getNumSamples()) { active = false; break; }
            float env = adsr.getNextSample();
            float s = sample->buffer.getSample(ch % sample->buffer.getNumChannels(), position) * env * velocity;
            data[i] += s;
            ++position;
        }
    }
    if (!adsr.isActive() && position > 0) active = false;
}
}
