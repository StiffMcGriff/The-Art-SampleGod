# scripts/setup.ps1 — Env setup runner (Windows / PowerShell)
# Vendors JUCE 9.0.1, seeds INI, configures CMake

$ErrorActionPreference = "Stop"

Write-Host "=== The Art-SampleGod Setup ===" -ForegroundColor Cyan

# 1. Copy .env.example -> .env if missing
if (-not (Test-Path ".env")) {
    Copy-Item ".env.example" ".env" -Force
    Write-Host "Created .env from .env.example" -ForegroundColor Green
}

# 2. Ensure JUCE vendored / fetched
if (-not (Test-Path "deps/JUCE")) {
    Write-Host "Fetching JUCE 9.0.1 via CMake..." -ForegroundColor Yellow
    cmake --preset win-x64
}

# 3. Seed INI config to APPDATA (if not exists)
$appDataDir = "$env:APPDATA\StiffMcGriff\The Art-SampleGod"
if (-not (Test-Path $appDataDir)) {
    New-Item -ItemType Directory -Path $appDataDir -Force | Out-Null
}
if (-not (Test-Path "$appDataDir\samplegod.conf")) {
    Copy-Item "config/samplegod.conf" "$appDataDir\samplegod.conf" -Force
    Write-Host "Seeded $appDataDir\samplegod.conf" -ForegroundColor Green
}

Write-Host "Setup complete. Run: .\scripts\build.ps1" -ForegroundColor Cyan
