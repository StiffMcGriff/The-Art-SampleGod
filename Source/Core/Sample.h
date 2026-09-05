#pragma once
#include <juce_core/juce_core.h>
#include "Types.h"
namespace SampleGod {
class Sample {
public:
    bool load(const juce::File& file);
    double getDuration() const;
    juce::AudioBuffer<float> buffer;
};
}
