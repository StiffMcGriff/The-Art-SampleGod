#!/bin/bash
# scripts/setup.sh — Linux/macOS env setup
set -euo pipefail

echo "=== The Art-SampleGod Setup (Unix) ==="

[ -f .env ] || cp .env.example .env
echo "Created .env if missing."

mkdir -p build/unix
# JUCE fetch / configure handled by CMake
cmake -B build/unix -S . -DCMAKE_CXX_STANDARD=20 || true

echo "Setup complete. Run: ./scripts/build.sh"
