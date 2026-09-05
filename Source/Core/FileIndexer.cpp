#include "FileIndexer.h"
namespace SampleGod {
std::vector<SampleMetadata> FileIndexer::indexDirectory(const juce::File& dir) {
    std::vector<SampleMetadata> result;
    for (auto f : juce::RangedDirectoryIterator(dir, false, "*.wav;*.mp3;*.flac")) {
        SampleMetadata m; m.filePath = f.getFile().getFullPathName(); m.sampleName = f.getFile().getFileNameWithoutExtension(); result.push_back(m);
    }
    return result;
}
}
