#include "Logger.h"
#include <iostream>
namespace SampleGod {
void Logger::info(const juce::String& msg) { std::cout << "[INFO] " << msg.toStdString() << std::endl; }
void Logger::warn(const juce::String& msg) { std::cout << "[WARN] " << msg.toStdString() << std::endl; }
}
