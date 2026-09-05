#include "PluginEditor.h"
#include "Core/FileIndexer.h"
#include "Core/SampleLibrary.h"
namespace SampleGod {
PluginEditor::PluginEditor(PluginProcessor& p) : AudioProcessorEditor(&p), processorRef(p) {
    setSize(800, 600); addAndMakeVisible(browser); addAndMakeVisible(waveform);
    FileIndexer idx; auto results = idx.indexDirectory(juce::File("C:\\SampleLibrary"));
    (void)results;
}
PluginEditor::~PluginEditor() {}
void PluginEditor::paint(juce::Graphics& g) { g.fillAll(Theme::background); }
void PluginEditor::resized() { browser.setBounds(10, 10, getWidth()-20, 300); waveform.setBounds(10, 320, getWidth()-20, 260); }
}
