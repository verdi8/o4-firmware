# AGENTS.md

## Purpose

This repository contains the firmware for the O4 Robot, built with PlatformIO for Arduino targets.

## Project Layout

- `src/` contains the production firmware.
- `src/Controllers/` contains hardware-oriented controllers.
- `src/Actions/` contains higher-level action sets built on controllers.
- `src/Hardware/HAL/` contains platform abstractions and Arduino implementations.
- `src/BCode/` contains integration with the `b-code` interpreter.
- `test/test_native/` contains native unit tests.
- `.pio/libdeps/` contains external dependencies managed by PlatformIO and should not be edited directly.

## Layered Architecture

- `Hardware Abstraction Layer`: wraps Arduino-specific services behind interfaces such as servo, tone, LED control, and program-space helpers so the rest of the firmware can stay portable and testable.
- `Controllers`: provide focused control over individual hardware capabilities such as body movement, sound, display, or communication, and expose simple operations to upper layers.
- `Actions`: compose one or more controllers into reusable robot features such as gestures, melodies, or display sequences.
- `Behaviour`: coordinates actions and higher-level decision making to define how the robot reacts over time in autonomous or guided scenarios.

## Main code entrypoints
- `src/main.cpp` initializes the robot and starts the main loop.
- `src/Config.h` contains hardware config like pin mappings
- `src/Hardware/HAL/HAL.h`, `src/Hardware/HAL/Arduino/ArduinoHAL.h` gives access to all hardware components
- `lib/Logger/logger.h` provides logging macros for debug output.

## Working Rules

- Prefer minimal, local changes that preserve the existing architecture.
- Keep hardware-independent logic testable and place Arduino-specific behavior behind HAL or communication abstractions.
- Reuse existing project types such as `PinNumber` instead of raw Arduino-specific types when possible.
- Do not edit generated or vendored dependency files under `.pio/`.
- Preserve the current include style and naming conventions used in nearby files.

## Build And Test

- Main embedded target: `arduino` in `platformio.ini`.
- Native tests live under `test/test_native/`.
- Preferred commands when available:
  - `pio run -e arduino`
  - `pio test -e native`

## Code Change Guidance

- When adding a new controller, place headers and sources under the matching folder in `src/Controllers/`.
- If a new class depends on external libraries, keep the public interface small and avoid leaking platform details into unrelated code.
- Update documentation only when the change affects usage, architecture, or setup.

## Current Constraints

- This project targets constrained microcontroller hardware, so avoid unnecessary dynamic allocation, large buffers, and heavy abstractions unless they are already established in the codebase.
- Serial and `b-code` related features should remain compatible with the existing `bcode::*` interfaces used by the firmware.