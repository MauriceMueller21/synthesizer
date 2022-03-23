# Linux Synthesizer

> A Linux Synthesizer using Alsa and Xlib

|              |                                |
| ------------ | ------------------------------ |
| Developers   | Lukas Niegsch, Maurice Mueller |
| Languages    | C, C++, Assembly               |
| License      | GPLv3                          |
| Start        | 2022-03-20                     |
| Depencendies | Alsa, Xlib                     |

## Website

User Guide: https://mauricemueller21.github.io/synthesizer/guide/index.html

Code Documentation: https://mauricemueller21.github.io/synthesizer/documentation/index.html

## .gitignore

The `.gitignore` should contain:
```
.gitignore
.gitconfig
bin/
```

## Project structure

```
synthesizer/            Repository root
├── bin/                Compiled and linked files
│   ├── objects/        Compiled object files
│   │   ├── core/       Core object files
│   │   ├── graphics/   Graphics object files
│   │   ├── sound/      Sound object files
│   │   └── test/       Test object files
│   └── synthesizer     Executable program
├── docs/               The website
│   ├── guide/          User manual (Markdown and HTML)
│   ├── images/         Images for the user manual
│   └── documentation/  Source code documentation
├── src/                Source code
│   ├── core/           Core source code
│   ├── graphics/       Graphics source code
│   ├── sound/          Sound source code
│   ├── test/           Test source code
│   ├── main.cpp        The main.cpp file
│   └── main.h          The main.h file
├── tools/              Tools for the project
│   └── sh/             Bash scripts
├── README.md           General project information
└── makefile            The main makefile
```
