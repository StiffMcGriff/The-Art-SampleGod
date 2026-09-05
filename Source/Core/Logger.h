#pragma once
#include <juce_core/juce_core.h>
namespace SampleGod {
class Logger {
public:
    static void info(const juce::String& msg);
    static void warn(const juce::String& msg);
};
}
