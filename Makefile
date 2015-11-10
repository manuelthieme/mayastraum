TARGET =main
SOURCES =Game.cc Screen.cc ScreenObject.cc Character.cc Animation.cc Hitbox.cc Edge.cc Point.cc main.cc
OBJECTS =$(SOURCES:.cc=.o)
DEPS =$(SOURCES:.cc=.d)
CFLAGS =-Wall -Wextra -Werror -Wmissing-declarations -O3 -std=c++11
CFLAGS_LAZY =-Wall -Wextra -O3 -std=c++11
LDFLAGS=-lSDL2 -lSDL2_image
LDFLAGS_MAC=-I/Library/Frameworks/SDL2.framework/Headers -framework SDL2 -framework SDL2_image

all: $(TARGET)

debug: CFLAGS += -g
debug: $(TARGET)

mac: LDFLAGS = $(LDFLAGS_MAC)
mac: $(TARGET)

lazy: CFLAGS = $(CFLAGS_LAZY)
lazy: $(TARGET)

$(TARGET): $(OBJECTS)
	g++ $(LDFLAGS) -o $@ $^

%.o: cc/%.cc Makefile
	g++ -MMD -c $(CFLAGS) -o $@ $<

.PHONY : clean
clean:
	rm -f $(TARGET) $(OBJECTS) $(DEPS)

-include $(DEPS)




