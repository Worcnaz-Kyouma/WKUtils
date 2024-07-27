# Params
TARGETNAME = wkutils
TARGET = app/bin/lib$(TARGETNAME).a
SOURCE = $(patsubst app/src/%.cpp, app/build/%.o, $(wildcard app/src/*.cpp))
GNUPARAMS= -Iapp/include

TEST = app/test/test
TESTPARAMS = 

app/build/%.o: app/src/%.cpp
	mkdir -p app/build
	gcc $(GNUPARAMS) -o $@ -c $<

app/test/%.o: app/test/%.cpp
	gcc $(GNUPARAMS) -o $@ -c $<


$(TARGET): $(SOURCE)
	mkdir -p app/bin
	ar rcs $(TARGET) $(SOURCE)

$(TEST).exe: $(TEST).o $(TARGET)
	gcc $< -o $@ -Lapp/bin -l$(TARGETNAME)

.PHONY: build clean
build: $(TARGET)
test: $(TEST).exe
	$<

clean:
	rm -rf app/build app/bin app/test/*.o