#pragma once
#include <juce_audio_processors/juce_audio_processors.h>
#include "PluginProcessor.h"
#include "UI/SampleBrowser.h"
#include "UI/WaveformDisplay.h"

namespace SampleGod {
class PluginEditor : public juce::AudioProcessorEditor {
public:
    explicit PluginEditor(PluginProcessor&);
    ~PluginEditor() override;
    void paint(juce::Graphics&) override;
    void resized() override;
private:
    PluginProcessor& processorRef;
    SampleBrowser browser;
    WaveformDisplay waveform;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginEditor)
};
}
