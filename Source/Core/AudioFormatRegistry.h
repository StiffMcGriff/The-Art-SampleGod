#pragma once
#include <juce_audio_formats/juce_audio_formats.h>
namespace SampleGod {
class AudioFormatRegistry {
public:
    juce::StringArray getSupportedExtensions() const;
};
}
