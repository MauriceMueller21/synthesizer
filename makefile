SHELL := /bin/bash
.SILENT:

all: compile run

compile:
	mkdir -p bin/
	libraries="-lX11 -lasound"; \
	flags="-Wall -Wextra -Werror"; \
	filenames="$$(find src -name "*.cpp" | grep -v "tests")"; \
	g++ $$flags $$libraries $$filenames -o bin/synthesizer

run: compile
	bin/synthesizer

clean:
	rm -rf bin

test-graphics-manually: compile
	bin/synthesizer -t

test-graphics-automatically:
	mkdir -p bin/tests/
	echo -e "" > bin/tests/graphics.log
	cmake src/graphics -B bin/tests/graphics >> bin/tests/graphics.log
	cmake --build bin/tests/graphics >> bin/tests/graphics.log
	bin/tests/graphics/test-graphics

