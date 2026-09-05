# The Art-SampleGod — Windows Edition

A **Windows sampler instrument** (**VST3** + **Standalone**) with a built-in
sample library: it indexes a folder of audio files, shows them in a sortable
browser with a waveform preview, maps them to the keyboard, and plays them back
polyphonically with per-voice pitch, looping and ADSR envelopes.

Built with **C++20 + JUCE 9.0.1 + CMake (MSVC 2022)** — JUCE is the *only*
third-party dependency (see `cmake/JUCE.cmake`).

## Quickstart (PowerShell)

```powershell
Copy-Item .env.example .env            # optional: set SAMPLEGOD_SCAN_ROOTS

.\scripts\setup.ps1                    # vendors JUCE 9.0.1, seeds INI, configures CMake
.\scripts\build.ps1                    # builds VST3 + Standalone (Release)
```

Or with CMake presets (VS2022 x64):

```powershell
cmake --preset win-x64
cmake --build --preset release
```

> **Prerequisites (one-time):** CMake ≥ 3.22, Git for Windows, and **Visual
> Studio 2022** with the *"Desktop development with C++"* workload.

> **Licensing:** JUCE is AGPLv3 / commercially licensed. Shipping a binary
> without a commercial JUCE licence requires AGPLv3 compliance.

## Automated Windows build (CI)

`.github/workflows/windows-build.yml` builds VST3 + Standalone with real MSVC on
GitHub's Windows runner on every push/PR and uploads the binaries as artifacts.
This is the authoritative Windows build check — push the repo to GitHub to run it.

## Outputs

`scripts\setup.ps1`/`build.ps1` configure into `build\` (VS2022 x64). If you use
the CMake presets instead, the same files land under `build\win-x64\`.

| Format | Location after build |
| --- | --- |
| VST3 | `build\TheArtSampleGod_artefacts\Release\VST3\The Art-SampleGod.vst3` (auto-copied to `C:\Program Files\Common Files\VST3\`) |
| Standalone | `build\TheArtSampleGod_artefacts\Release\Standalone\The Art-SampleGod.exe` |

## Configuration

Copy `.env.example` → `.env` (or set the variables directly). Precedence:
**environment variable > `.env` > `config/samplegod.conf` (app data dir) > default**.

| Variable | Default | Purpose |
| --- | --- | --- |
| `SAMPLEGOD_DATA_DIR` | `%APPDATA%\StiffMcGriff\The Art-SampleGod` | library index, log, user INI |
| `SAMPLEGOD_LIBRARY_FILE` | `<data>\library.json` | index path |
| `SAMPLEGOD_SCAN_ROOTS` | *(empty)* | folders scanned on first launch (`;`-separated) |
| `SAMPLEGOD_POLYPHONY` | `64` | voice count (1–512) |
| `SAMPLEGOD_DEFAULT_GAIN_DB` | `0.0` | initial master gain |
| `SAMPLEGOD_LOG_LEVEL` | `info` | `trace|debug|info|warn|error` |
| `JUCE_VERSION` | `9.0.1` | pinned JUCE tag (build scripts) |

## First run

1. Set `SAMPLEGOD_SCAN_ROOTS` (e.g. `C:\Users\You\Samples;D:\Loops`) — or edit
   `%APPDATA%\StiffMcGriff\The Art-SampleGod\samplegod.conf` after setup.
2. Launch the Standalone `.exe` (or load the VST3 in Reaper / Ableton / FL / Bitwig).
3. Press **Rescan Library**; double-click a row to preview; play MIDI.

## Docs

- `docs/ARCHITECTURE.md` — blueprint, data flow, module interfaces.
- `docs/BUILD_GUIDE.md` — full step-by-step Windows procedure + troubleshooting.
- `docs/HANDOFF.md` — handoff blueprint for the next owner.

## Layout

See `docs/ARCHITECTURE.md` for the full tree and module graph.
