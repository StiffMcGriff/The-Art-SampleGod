#pragma once
#include <juce_core/juce_core.h>
#include "Types.h"
#include <vector>
namespace SampleGod {
class FileIndexer {
public:
    std::vector<SampleMetadata> indexDirectory(const juce::File& dir);
};
}
