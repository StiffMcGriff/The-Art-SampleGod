#pragma once
#include <juce_core/juce_core.h>

namespace SampleGod {
class Config {
public:
    juce::String getScanRoot() const;
    int getMaxVoices() const;
private:
    juce::String scanRoot = "C:\\SampleLibrary";
    int maxVoices = 64;
};
}
