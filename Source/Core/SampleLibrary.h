#pragma once
#include <juce_core/juce_core.h>
#include "Types.h"
#include <map>
namespace SampleGod {
class SampleLibrary {
public:
    void loadFromDirectory(const juce::File& dir);
    std::vector<SampleMetadata> search(const juce::String& query) const;
private:
    std::map<juce::String, SampleMetadata> library;
};
}
