# scripts/build.ps1 — Build runner (Windows / MSVC 2022 x64)

$ErrorActionPreference = "Stop"

Write-Host "=== The Art-SampleGod Build ===" -ForegroundColor Cyan

# Configure if needed
if (-not (Test-Path "build/win-x64/CMakeCache.txt")) {
    cmake --preset win-x64
}

# Build VST3 + Standalone Release
cmake --build --preset release --config Release --parallel

Write-Host "Build complete. Artifacts in build/win-x64/Release/" -ForegroundColor Green
