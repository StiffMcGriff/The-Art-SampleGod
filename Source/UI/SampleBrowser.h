#pragma once
#include <juce_gui_extra/juce_gui_extra.h>
#include "SampleLibrary.h"
namespace SampleGod {
class SampleBrowser : public juce::Component, public juce::TableListBoxModel {
public:
    void resized() override;
    int getNumRows() override { return 0; }
    void paintRowBackground(juce::Graphics&, int, int, int, bool) override {}
    void paintCell(juce::Graphics&, int, int, int, int, bool) override {}
private:
    juce::TableListBox table;
    SampleLibrary library;
};
}
