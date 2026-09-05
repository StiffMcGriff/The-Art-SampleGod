#pragma once
#include <juce_core/juce_core.h>
#include "Types.h"
namespace SampleGod {
class Keymap {
public:
    KeyZone find(int note, int velocity) const;
};
}
