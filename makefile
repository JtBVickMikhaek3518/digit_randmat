SAFE = rm -f err.txt

all: comp watch

comp:
	@rm -f debug.exe
	@g++ main.cpp -o debug 2>> err.txt || exit 1
	@$(SAFE)

watch:
	@start tools\\watch.bat 2>> err.txt || exit 1
	@$(SAFE)

build:
	@rm -f release.exe
	@g++ -static -static-libgcc -static-libstdc++ main.cpp -o release 2>> err.txt || exit 1
	@start tools\\run.bat 2>> err.txt || exit 1
	@$(SAFE)

run:
	@start tools\\run.bat 2>> err.txt || exit 1
	@$(SAFE)

clean:
	@rm -f debug.exe release.exe
