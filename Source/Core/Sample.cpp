#include "Sample.h"
#include <juce_audio_formats/juce_audio_formats.h>

namespace SampleGod {
bool Sample::load(const juce::File& file) {
    juce::AudioFormatManager formatManager;
    formatManager.registerBasicFormats();
    std::unique_ptr<juce::AudioFormatReader> reader(formatManager.createReaderFor(file));
    if (!reader) return false;
    int samples = static_cast<int>(reader->lengthInSamples);
    int channels = reader->numChannels;
    buffer.setSize(channels, samples);
    reader->read(&buffer, 0, samples, 0, true, true);
    return true;
}
double Sample::getDuration() const {
    return buffer.getNumSamples() / 44100.0;
}
}
