Key Prompt Terms & Definitions
Deterministic Integration Selection: Forces the model to evaluate available APIs/libraries and pick the single most direct, zero-friction option rather than inventing custom abstractions or throwing multiple frameworks at a problem.

Optimal Primitive Mapping: Instructs the model to map each feature directly to its canonical, lowest-overhead code primitive or built-in library (e.g., using native Python pathlib or asyncio instead of adding unnecessary third-party dependencies).

Minimal Viable Dependency (MVD): Constrains the model to choose integrations that require the fewest external packages, locking down compatibility and avoiding version conflicts.

Canonical Function Binding: Directs the model to implement standard, industry-accepted functions and design patterns for the chosen language rather than crafting experimental or non-standard custom wrappers.


[ROLE & CONTEXT]
You are a Lead Software Architect and Systems Engineer. Your objective is to build a complete, deterministic pre-build blueprint for a production-ready application called [APP_NAME]. 

[PROJECT SPECIFICATION]
- Primary Functionality: [DESCRIBE THE CORE FUNCTION IN 1-2 SENTENCES]
- Target Stack: [e.g., Python 3.11, PyQt5 / Node.js, React, Tailwind / C++ JUCE]
- Primary OS Target: [e.g., Windows 11 / macOS / Cross-platform]

[NON-NEGOTIABLE CONSTRAINTS]
1. ZERO OVER-ENGINEERING: Do not add extra microservices, complex state layers, or unrequested features. Build only the straightest line to a working app.
2. NO PLACEHOLDERS: Do not leave `// TODO: Implement later` or truncated logic blocks. All pre-build scripts and configuration files must be 100% complete and valid.
3. ISOLATED RUNTIME: All dependencies must be explicitly locked via single setup scripts (`venv`, `requirements.txt`, or `package.json`).

[REQUIRED DELIVERABLES]
Deliver the full pre-build blueprint in sequence:

1. ARCHITECTURE BLUEPRINT
   - Clean, flat directory structure layout using standard tree text format.
   - Concise summary of how data flows from user interaction to execution.

2. ENVIRONMENT SETUP RUNNER
   - Provide a complete, runnable setup script (e.g., `setup.ps1` for PowerShell or `setup.sh` for Bash) that automatically creates virtual environments, installs pinned dependencies, and verifies runtime paths.

3. DEPENDENCY SPECIFICATION
   - Full configuration files with exact version numbers (`requirements.txt`, `package.json`, or build scripts).

4. CORE MODULE INTERFACES & ENTRY POINT
   - Complete, executable entry point script (`main.py`, `index.ts`, or core file) containing the base bootstrap logic.
   - Strict data schemas/types for API or internal module boundaries.

5. EXECUTION CHECKLIST
   - Step-by-step commands to run, test, and package the application without hitting dependency or path errors.

Proceed step-by-step through deliverables 1 through 5.




