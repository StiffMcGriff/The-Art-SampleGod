#include "Keymap.h"
namespace SampleGod {
KeyZone Keymap::find(int note, int velocity) const {
    KeyZone z;
    z.lowNote = 24; z.highNote = 108; z.rootNote = 60; z.sampleId = "default";
    (void)note; (void)velocity;
    return z;
}
}
