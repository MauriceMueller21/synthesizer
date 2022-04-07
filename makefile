SHELL := /bin/bash
.SILENT:

all: compile run

clean:
	rm -rf bin/

compile:
	mkdir -p bin/
	libraries="-lX11 -lasound"; \
	flags="-Wall -Wextra -Werror"; \
	filenames="$$(find src/ -name "*.cpp" | grep -v "tests")"; \
	g++ $$flags $$libraries $$filenames -o bin/synthesizer

compile-tui:
	mkdir -p bin/
	libraries="-lasound"; \
	flags="-Wall -Wextra -Werror"; \
	filenames="$$(find src/ -name "*.c" | grep -E "src/(core|sound|tui)/" | grep -v -E "src/(core|sound|tui)/test/")"; \
	gcc $$flags $$libraries $$filenames src/main-tui.c -o bin/synthesizer-tui

tui: compile-tui
	bin/synthesizer-tui

run: compile
	bin/synthesizer

test-core:
	bash scripts/test-tui-sound-core.sh core

test-sound:
	bash scripts/test-tui-sound-core.sh sound

test-tui:
	bash scripts/test-tui-sound-core.sh tui

test-graphics-manually: compile
	bin/synthesizer -t

test-graphics-automatically:
	mkdir -p bin/tests/
	echo -e "" > bin/tests/graphics.log
	cmake src/graphics -B bin/tests/graphics >> bin/tests/graphics.log
	cmake --build bin/tests/graphics >> bin/tests/graphics.log
	bin/tests/graphics/test-graphics

lines:
	echo -en ".cpp "
	wc -l $$(find src/ -name *.cpp) | grep " total" | grep -o [0-9]\*
	echo -en ".c   "
	wc -l $$(find src/ -name *.c) | grep " total" | grep -o [0-9]\*
	echo -en ".h   "
	wc -l $$(find src/ -name *.h) | grep " total" | grep -o [0-9]\*
