SHELL := /bin/bash
CFLAGS := -Wall -Wextra -Werror -O2 -march=native -pipe
.SILENT:

all: compile run

clean:
	rm -rf bin/

compile-tui:
	mkdir -p bin/
	libraries="-lasound -lncurses -lpthread"; \
	filenames="$$(find src/ -name "*.c" | grep -E "src/(core|sound|tui)/" | grep -v -E "src/(core|sound|tui)/test/")"; \
	gcc $(CFLAGS) $$filenames src/main-tui.c -o bin/synthesizer-tui $$libraries

compile-gui:
	mkdir -p bin/
	libraries="-lX11 -lasound"; \
	filenames="$$(find src/ -name "*.cpp" | grep -E "src/(core|sound|gui)/" | grep -v -E "src/(core|sound|gui)/test/")"; \
	g++ $(CFLAGS) $$libraries $$filenames src/main-gui.cpp -o bin/synthesizer-gui

tui: compile-tui
	bin/synthesizer-tui

gui: compile-gui
	bin/synthesizer-gui

test-core:
	bash tools/test-tui-sound-core.sh core

test-sound:
	bash tools/test-tui-sound-core.sh sound

test-tui:
	bash tools/test-tui-sound-core.sh tui

test-gui:
	tools/test-gui.sh
	bin/test/gui/test-gui

lines:
	echo "Code Lines TUI:"
	echo -en ".c   "
	wc -l $$(find src/core/ src/sound/ src/tui/ -name '*.c') "src/main-tui.c" | grep " total" | grep -o [0-9]\*
	echo -en ".h   "
	wc -l $$(find src/core/ src/sound/ src/tui/ -name '*.h') | grep " total" | grep -o [0-9]\*
	echo "Code Lines GUI:"
	echo -en ".cpp "
	wc -l $$(find src/gui/ -name '*.cpp') "src/main-gui.cpp" | grep " total" | grep -o [0-9]\*
	echo -en ".h   "
	wc -l $$(find src/gui/ -name '*.h') | grep " total" | grep -o [0-9]\*
	echo "Total Lines:"
	wc -l $$(find src/ -name '*.h' -o -name '*.c' -o -name '*.cpp') | grep " total" | grep -o [0-9]\*

files:
	echo "Files TUI:"
	echo -en ".c   "
	echo $$(($$(find src/core/ src/sound/ src/tui/ -name '*.c' | wc -l) + 1))
	echo -en ".h   "
	find src/core/ src/sound/ src/tui/ -name '*.h' | wc -l
	echo "Files GUI:"
	echo -en ".cpp "
	echo $$(($$(find src/gui/ -name '*.cpp' | wc -l) + 1))
	echo -en ".h   "
	find src/gui/ -name '*.h' | wc -l
	echo "Total Files:"
	find src/ -name '*.h' -o -name '*.c' -o -name '*.cpp' | wc -l
