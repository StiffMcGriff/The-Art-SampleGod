#include "Keymap.h"
namespace SampleGod {
KeyZone Keymap::find(int, int) const { KeyZone z; z.lowNote = 24; z.highNote = 108; z.rootNote = 60; return z; }
}
