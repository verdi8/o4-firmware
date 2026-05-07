# O4 Firmware

## Introduction

This project contains the firmware for the **O4 Robot**, a tiny 4-legged robot.

### About the O4 Robot

The **O4 Robot** is a tiny 4-legged robot. It is open-source hardware and software.

The O4 Robot is forked from the [OTTO Quad robot](https://github.com/jarsoftelectrical/OTTOquad).

### About `b-code`
`b-code` is a proposal of protocol to control tiny robots like the O4 robot. It is text-based and intended to be the equivalent of G-code for 3D printers and CNC machines.

It is actually not only a protocol, but a set of related projects:
- [b-code](https://github.com/verdi8/b-code/) : the specification of the protocol itself
- [b-code-desc](https://github.com/verdi8/b-code-desc/) : a JSON description format of the capabilities of a robot (possible actions, sensor list, id card) to make it easier to be controlled by generic and reusable remote controls, or even LLMs
- [b-code-remote-control](https://github.com/verdi8/b-code-remote-control/) : a web-based remote control for robots supporting b-code and having a b-code description file
- [b-code-arduino-interpreter](b-code-arduino-interpreter) : an Arduino library to interpret and execute b-code commands

These `b-code` projects are intended to make software developped for the O4 Robot easily reusable for other robots.

> [!NOTE]
> These projects are still in early development, and the specification is not yet stable.

## Installation
This firmware is developed with PlatformIO. The recommanded way to build and install it is to use [Visual Studio Code with the PlatformIO extension](https://docs.platformio.org/en/latest/integration/ide/vscode.html).

### Prerequisites
- [Visual Studio Code](https://code.visualstudio.com/)
- [PlatformIO extension for Visual Studio Code](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide)

### Steps
1. Clone this repository
2. Open the folder in Visual Studio Code
3. Connect your O4 Robot to your computer with a USB cable
4. In Visual Studio Code, open the PlatformIO extension (icon on the left sidebar)
5. Click on "Build" to compile the firmware
6. Click on "Upload" to install the firmware on the O4 Robot

## Usage

## Customization

### Hardware configuration
The hardware configuration of the O4 Robot can be customized in the `src/Config.h` file. You can change the pin assignments according to your hardware setup.

### Software guide

```mermaid
block
columns 4
    behaviour_title["<b>Behaviour</b>\nDefines robot behaviors"]
    block:behaviour_block:3
        ab["<b>AutomaticBehaviour</b>\nHandles autonomous operations"]
    end
    actions_title["<b>Actions</b>\nSets of complex actions"] 
    block:actions_block:3
        da["<b>DisplayActions</b>\nA set of animations and still images that are applied to the DisplayController"]
        sa["<b>SoundActions</b>\nSongs and jingles sent to the SoundController"]
    end
    controllers_title["<b>Controllers</b>\nExposes simple methods to control the underlying hardware components"]
    block:controllers_block:3
        columns 3
        kc["<b>BodyController</b>\nAn overlay to the 8 ServoControllers of the robot"]
        tc["<b>ServoController (x8)</b>\nMakes a servo oscilliate or move to a position"]
        sc["<b>SoundController</b>\nControls sound output"]
        dc["<b>DisplayController</b>\n"]
    end

    hal_title["<b>HAL</b>\nan Hardware Abstraction Layer over the Arduino platform, mainly for unit testing purposes"]
    block:hal_block:3
        hs["<b>HALServo</b>\nAbstraction for servo motors"] 
        ht["<b>HALTone</b>\nAbstraction for tone generation"]
        hl["<b>HALLedControl</b>\nAbstraction over the LedControl library"]
        hp["<b>HALProgramSpaceHelper</b>\nHelper for program space memory access"]
        hy["<b>HALTypes</b>\nRedefinitions of Arduino specific types"]
    end

    arduino_title["<b>Arduino</b>\nArduino-related components"]
    block:arduino_block:3
        ar["<b>Arduino libraries</b>\nCore Arduino libraries"]
        lc["<b>LedControl library</b>\nLibrary for LED control"]
    end

    classDef layer fill:white,stroke:#333,stroke-width:2px,stroke-dasharray: 5 5;
    class actions_block layer
    class controllers_block layer   
    class hal_block layer   
    class behaviour_block layer   
    class arduino_block layer

   
    classDef title fill:white,stroke:none;
    class controllers_title title
    class hal_title title
    class actions_title title
    class behaviour_title title
    class arduino_title title

    classDef external fill:#EEEEEE,stroke:none;
    class ar external
    class lc external
```

### Unit testing
To run the unit tests locally, use the following command in the PlatformIO terminal:
```
pio test
```

A GCC toolchain must be available in your system PATH for the unit tests to run.

By the way, unit tests are also automatically run on GitHub Actions for each pull request.

## Contributing
Contributions are welcome! Please read the [CONTRIBUTING.md](CONTRIBUTING.md) file for more information.