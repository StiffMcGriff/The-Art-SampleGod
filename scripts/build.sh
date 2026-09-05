#!/bin/bash
# scripts/build.sh — Linux/macOS build runner
set -euo pipefail

echo "=== The Art-SampleGod Build (Unix) ==="

cmake --build build/unix --config Release --parallel

echo "Build complete."
