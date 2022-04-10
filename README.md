# Linux Synthesizer

> A Linux Synthesizer using Alsa and Xlib

| Detail       | Description                    |
| ------------ | ------------------------------ |
| Developers   | Lukas Niegsch, Maurice Mueller |
| Languages    | C, C++, Assembly               |
| License      | GPLv3                          |
| Start        | 2022-03-20                     |
| Depencendies | Alsa, Xlib                     |

## Website

User Guide:

https://mauricemueller21.github.io/synthesizer/guide/index.html

Code Documentation:

https://mauricemueller21.github.io/synthesizer/documentation/index.html

## Project structure

```
synthesizer/            Repository root
├── bin/                Compiled and linked files
│   ├── objects/        Compiled object files
│   │   ├── core/       Core object files
│   │   ├── gui/        Graphics object files
│   │   ├── sound/      Sound object files
│   │   └── tui/        Text based object files
│   ├── test/           Test object files
│   ├── synthesizer-gui Executable program (graphical)
│   └── synthesizer-tui Executable program (text based)
├── docs/               The website
│   ├── guide/          User manual (Markdown and HTML)
│   ├── images/         Images for the user manual
│   └── documentation/  Source code documentation
├── src/                Source code
│   ├── core/           Core source code
│   ├── gui/            Graphics source code
│   ├── sound/          Sound source code
│   ├── tui/            Text based source code
│   ├── main-gui.cpp    The main code file of the graphical software
│   └── main-tui.c      The main code file of the text based software
├── tools/              Tools for the project
├── README.md           General project information
└── makefile            The main makefile
```
