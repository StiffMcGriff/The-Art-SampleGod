#include "AudioFormatRegistry.h"
namespace SampleGod {
juce::StringArray AudioFormatRegistry::getSupportedExtensions() const { return {"wav","mp3","flac","aiff"}; }
}
