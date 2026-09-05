# JUCE 9.0.1 dependency lock
# If vendored at deps/JUCE, use add_subdirectory; otherwise fall back to FetchContent
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/deps/JUCE/CMakeLists.txt")
    add_subdirectory(deps/JUCE EXCLUDE_FROM_ALL)
else()
    include(FetchContent)
    FetchContent_Declare(
        JUCE
        GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
        GIT_TAG 9.0.1
        GIT_SHALLOW TRUE
    )
    FetchContent_MakeAvailable(JUCE)
endif()
