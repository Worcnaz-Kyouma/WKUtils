# Params
TARGET = wkutils.a
SOURCE = $(patsubst app/src/%.cpp, app/build/%.o, $(wildcard app/src/*.cpp))
GNUPARAMS= -I/app/include

app/build/%.o: app/src/%.cpp
	mkdir -p build
	gcc $(GNUPARAMS) -o $@ -c $<


$(TARGET): $(SOURCE)
	mkdir -p bin
	ar rcs app/bin/$(TARGET) $(SOURCE)

.PHONY: build clean
build: $(TARGET)
clean:
	rm -rf build bin iso