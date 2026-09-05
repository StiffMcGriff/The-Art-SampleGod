# JUCE 9.0.1 dependency lock — vendored or FetchContent
# Only third-party dependency allowed per .clinerules

include(FetchContent)

FetchContent_Declare(
    JUCE
    GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
    GIT_TAG v9.0.1
    GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(JUCE)

# Add JUCE module paths
list(APPEND CMAKE_MODULE_PATH ${juce_SOURCE_DIR}/extras/Build/CMake)
