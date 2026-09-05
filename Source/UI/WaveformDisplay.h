#pragma once
#include <juce_gui_extra/juce_gui_extra.h>
namespace SampleGod {
class WaveformDisplay : public juce::Component {
public:
    void paint(juce::Graphics& g) override;
};
}
