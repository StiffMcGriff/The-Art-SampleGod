# =============================================================================
# The Art-SampleGod — Architecture Blueprint
# =============================================================================

## 1. Directory layout

```
The-Art-SampleGod/
├── .env.example                  # documented environment overrides
├── .gitignore
├── CMakeLists.txt                # top-level build (single target, 3 formats)
├── CMakePresets.json             # configure/build presets (native / MSVC / Xcode)
├── cmake/
│   └── JUCE.cmake                # dependency lock: pinned JUCE (FetchContent/vendored)
├── config/
│   └── samplegod.conf            # runtime INI template (copied to data dir on setup)
├── presets/
│   └── DefaultPreset.samplegod   # example preset (JSON)
├── scripts/
│   ├── setup.sh                  # env setup runner — Linux/macOS
│   ├── build.sh                  # build runner — Linux/macOS
│   ├── setup.ps1                 # env setup runner — Windows
│   └── build.ps1                 # build runner — Windows
├── docs/
│   └── ARCHITECTURE.md           # this file
├── Source/
│   ├── AppConfig.h               # compile-time identity & defaults
│   ├── PluginProcessor.{h,cpp}   # host boundary: owns modules, params, state
│   ├── PluginEditor.{h,cpp}      # GUI
│   ├── Core/
│   │   ├── Types.h               # data schemas (SampleMetadata, KeyZone, ...)
│   │   ├── Config.{h,cpp}        # env > INI > default resolution
│   │   ├── Logger.{h,cpp}        # file + debug log
│   │   ├── AudioFormatRegistry.{h,cpp}  # format manager: inspect/decode
│   │   ├── FileIndexer.{h,cpp}   # directory walk -> metadata
│   │   ├── SampleLibrary.{h,cpp} # index + JSON persistence + search
│   │   ├── Sample.{h,cpp}        # decoded Sample + LRU SampleCache
│   │   ├── Keymap.{h,cpp}        # note/velocity -> zone lookup
│   │   ├── SamplerVoice.{h,cpp}  # one voice: playback, loop, envelope
│   │   └── SamplerEngine.{h,cpp} # polyphony, MIDI routing, master gain
│   └── UI/
│       ├── Theme.h               # palette constants
│       ├── SampleBrowser.{h,cpp} # sortable library table
│       └── WaveformDisplay.{h,cpp} # waveform thumbnail
└── deps/
    └── JUCE/                     # vendored by scripts/setup.* (gitignored)
```

No `main()`: `juce_add_plugin` generates the entry points for VST3/AU/Standalone;
our code only defines `createPluginFilter()` in `PluginProcessor.cpp`.

## 2. Data flow (user interaction -> execution)

```
DAW / keyboard MIDI ──▶ AudioPluginProcessor::processBlock()
                          │  MIDI events routed into the engine (audio thread)
                          ▼
                     SamplerEngine::render()
                          │  noteOn → Keymap::find(note, velocity) → zone
                          ▼
                     SampleCache::find(zone.sampleId)   ← warm cache, no disk I/O
                          │
                          ▼
                     SamplerVoice (x N)  — interpolated playback + ADSR
                          │
                          ▼
                     master gain → output AudioBuffer<float> → host

UI (editor):  Rescan → FileIndexer (ThreadPool) → SampleLibrary → save JSON
              Browse → SampleLibrary::search → table → WaveformDisplay
              Double-click → previewSample() → cache getOrLoad → engine noteOn
              Assign sample → mapSampleToZone() → Keymap → engine.setKeymap()
```

Threading: audio thread only touches `SampleCache::find` and the engine's
locked setters; all disk I/O happens on the message thread (UI) or the scan
`ThreadPool` job; the keymap/params are swapped into the engine under a lock.

## 3. Module interfaces (summary)

| Module | Responsibility | Key types / functions |
| --- | --- | --- |
| `Types.h` | Data schemas | `SampleId`, `SampleMetadata`, `KeyZone`, `ScanProgress`, `SampleBuffer` |
| `Config` | Runtime config | `dataDir()`, `libraryFile()`, `scanRoots()`, `polyphony()` |
| `Logger` | Diagnostics | `init()`, `log(LogLevel, String)` |
| `AudioFormatRegistry` | Decode + inspect | `inspect(File)`, `decodeToMono(File)`, `scanExtensions()` |
| `FileIndexer` | Indexing | `scan(roots, onProgress) -> vector<SampleMetadata>` |
| `SampleLibrary` | Index + persistence | `addEntries`, `search`, `findById`, `load`, `save` |
| `SampleCache` | Resident audio | `getOrLoad(meta)`, `find(id)`, `clear()` |
| `Keymap` | Note mapping | `find(note, vel)`, `addSampleZone`, `toVar/fromVar` |
| `SamplerVoice` | Single voice | `prime`, `noteOn/Off`, `render` |
| `SamplerEngine` | Polyphony | `prepare`, `render`, `noteOn/Off`, `setKeymap`, `setSampleCache` |
| `AudioPluginProcessor` | Host boundary | `processBlock`, `get/setStateInformation`, `startLibraryScan` |

## 4. Dependency lock

| Dependency | Version | How it's pinned |
| --- | --- | --- |
| JUCE | **9.0.1** | `cmake/JUCE.cmake` (`GIT_TAG` / vendored `deps/JUCE`) |
| C++ standard | C++20 | `CMAKE_CXX_STANDARD 20` in `CMakeLists.txt` |
| CMake | ≥ 3.22 | `cmake_minimum_required` + JUCE requirement |
| VST3 SDK | bundled with JUCE (3.8.0) | ships inside JUCE |
| Everything else | stdlib / JUCE modules | zero additional third-party deps |

Format targets: `AU VST3 Standalone` (set `SAMPLEGOD_FORMATS` to change).

## 5. Licensing (important)

JUCE is dual-licensed. Building and distributing this plugin without a paid
JUCE licence makes it subject to the **GPLv3**; with a commercial licence the
GPL terms do not apply. Choose accordingly before shipping.

**Zero-cost note:** this project is for personal use only, not commercial
distribution — GPLv3 applies and costs nothing. A paid JUCE licence is only
required if this plugin is ever sold or distributed closed-source without
releasing the source under GPL. As long as it stays personal-use, no JUCE
licence fee is needed.
