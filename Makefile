TARGET =main
SOURCES =Point.cc Edge.cc Hitbox.cc Animation.cc ScreenObject.cc Character.cc Screen.cc Game.cc main.cc
OBJECTS =$(SOURCES:.cc=.o)
DEPS =$(SOURCES:.cc=.d)
CFLAGS =-Wall -Wextra -Werror -Wmissing-declarations -O3 -std=c++11
CFLAGS_LAZY =-Wall -Wextra -O3 -std=c++11
LDFLAGS=-lSDL2 -lSDL2_image -lSDL2_ttf
LDFLAGS_MAC=-I/Library/Frameworks/SDL2.framework/Headers -framework SDL2 -framework SDL2_image

all: $(TARGET)

debug: CFLAGS += -g
debug: $(TARGET)

mac: LDFLAGS = $(LDFLAGS_MAC)
mac: $(TARGET)

lazy: CFLAGS = $(CFLAGS_LAZY)
lazy: $(TARGET)

$(TARGET): $(OBJECTS)
	g++ -o $@ $^ $(LDFLAGS)

%.o: cc/%.cc Makefile
	g++ -MMD -c $(CFLAGS) -o $@ $<

.PHONY : clean
clean:
	rm -f $(TARGET) $(OBJECTS) $(DEPS)

-include $(DEPS)




