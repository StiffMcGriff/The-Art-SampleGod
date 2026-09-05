# The Art-SampleGod Agent Instructions

## Repository Status

- Treat `README.md` and `ARCHITECTURE.md` as the authoritative project blueprint.
- The current checkout may contain documentation without the planned `Source/`, `CMakeLists.txt`, `scripts/`, `cmake/`, `config/`, `presets/`, `docs/`, or test files. Do not claim that documented commands or modules exist until their paths are present.
- `The Art- Sample God(ini_config).md` is a generic pre-build prompt with placeholders; do not treat it as implementation configuration.

## Technical Stack

- Target C++20 with JUCE 9.0.1 for VST3 and Standalone plugin targets when the implementation is present.
- Use CMake with an MSVC 2022 x64 target. Prefer repository PowerShell wrappers `scripts/setup.ps1` and `scripts/build.ps1` when they exist; otherwise use the documented CMake presets.
- Python 3.x, JavaScript/TypeScript, and PowerShell are supporting automation languages, not reasons to add new runtime dependencies.
- Keep JUCE as the only intended third-party dependency. Prefer the C++20 standard library and JUCE modules before adding packages.

## Architecture And Audio Safety

- Preserve `PluginProcessor` as the host boundary and keep DSP ownership and rendering in `SamplerEngine` and `SamplerVoice`.
- Keep note/velocity mapping in `Keymap`, indexing and persistence in `FileIndexer` and `SampleLibrary`, resident decoded audio in `SampleCache`, and editor concerns in `PluginEditor`, `SampleBrowser`, and `WaveformDisplay`.
- Never perform disk I/O, blocking work, or avoidable allocation on the audio thread. Use resident data and appropriately bounded state exchange between UI/worker threads and audio processing.
- Keep UI/editor code out of DSP modules and preserve public module interfaces unless the task explicitly requires a breaking change.

## Configuration And Repository Hygiene

- Resolve configuration in this order: environment variable > local `.env` > user AppData configuration > hardcoded default.
- Validate user-controlled paths and numeric settings at the configuration boundary.
- Never commit build outputs, local `.env` files, generated/vendor dependencies, user AppData data, or release archives containing local data. Preserve the repository's ignore rules when present.
- Keep configuration names and documented defaults stable unless the task explicitly changes the contract.

## Build, Test, And Formatting

- Before running a documented command, verify its script, preset, or workflow exists in the checkout.
- Expected Windows prerequisites are CMake 3.22+, Git for Windows, and Visual Studio 2022 with Desktop development with C++.
- Run the narrowest available executable validation after a change. If no source, build, or test implementation exists, report that validation is unavailable rather than implying success.
- Use Black/Ruff for Python, Prettier/ESLint for JavaScript/TypeScript, and clang-format for C++ only when the corresponding configuration or hooks exist. Avoid unrelated formatting churn.
- Use explicit error handling in PowerShell and preserve cross-platform-compatible behavior where scripts are intended to be portable.

## Documentation

- Keep architectural and build documentation synchronized when actual architecture or procedures change.
- Prefer links to existing documentation over duplicating its content. The current project references `docs/ARCHITECTURE.md`, `docs/BUILD_GUIDE.md`, and `docs/HANDOFF.md`; create or update those only when the corresponding documentation task is requested and the repository structure supports it.
- Do not document source files, commands, workflows, or behavior that are not present or verified in the checkout.
