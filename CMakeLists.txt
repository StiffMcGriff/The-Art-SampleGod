cmake_minimum_required(VERSION 3.22)
project(TheArtSampleGod VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# JUCE dependency lock (pinned 9.0.1)
include(cmake/JUCE.cmake)

juce_add_plugin(TheArtSampleGod
    PLUGIN_MANUFACTURER_CODE Juce
    PLUGIN_CODE Sam1
    FORMATS VST3 Standalone
    PRODUCT_NAME "The Art-SampleGod"
    VERSION ${PROJECT_VERSION}
    COMPANY_NAME "StiffMcGriff"
    WEBSITE_URL "https://github.com/StiffMcGriff/The-Art-SampleGod"
    IS_SYNTH TRUE
    NEEDS_MIDI_INPUT TRUE
    NEEDS_MIDI_OUTPUT FALSE
    COPY_PLUGIN_AFTER_BUILD TRUE
    VST3_CAN_RESIZE TRUE
)

target_sources(TheArtSampleGod PRIVATE
    Source/PluginProcessor.cpp
    Source/PluginEditor.cpp
    Source/Core/Config.cpp
    Source/Core/Logger.cpp
    Source/Core/FileIndexer.cpp
    Source/Core/SampleLibrary.cpp
    Source/Core/Sample.cpp
    Source/Core/Keymap.cpp
    Source/Core/SamplerVoice.cpp
    Source/Core/SamplerEngine.cpp
    Source/Core/AudioFormatRegistry.cpp
    Source/UI/SampleBrowser.cpp
    Source/UI/WaveformDisplay.cpp
)

target_include_directories(TheArtSampleGod PRIVATE Source/)

target_link_libraries(TheArtSampleGod
    PRIVATE
        juce::juce_audio_utils
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags)

# Windows-specific settings
if(MSVC)
    target_compile_options(TheArtSampleGod PRIVATE /W4 /permissive-)
endif()
