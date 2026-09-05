#include "Config.h"
namespace SampleGod {
juce::String Config::getScanRoot() const { return scanRoot; }
int Config::getMaxVoices() const { return maxVoices; }
}
