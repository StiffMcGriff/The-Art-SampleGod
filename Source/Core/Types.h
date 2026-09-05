#pragma once
#include <juce_audio_processors/juce_audio_processors.h>

namespace SampleGod {
struct SampleMetadata {
    juce::String filePath;
    juce::String sampleName;
    double durationSeconds = 0.0;
    int rootNote = 60;
};

struct KeyZone {
    int lowNote = 24;
    int highNote = 108;
    int rootNote = 60;
    juce::String sampleId;
};
}
