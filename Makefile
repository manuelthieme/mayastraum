BUILD  := build
SRCDIR := src
INCDIR := inc
LIBDIR := lib
DEPDIR := .d

RM     := rm -rf
MKDIR  := mkdir -p
TARGET := $(BUILD)/main
SRCSALL      := $(patsubst ./%, %, $(shell find -path ./$(LIBDIR) -prune -o -path ./_old -prune -o -name "*.cc" -o -name "*.h"))
SRCSCC       := $(filter %.cc, $(SRCSALL))
SRCH         := $(filter %.h, $(SRCSALL))
OBJS         := $(patsubst $(SRCDIR)/%.cc, $(BUILD)/%.o, $(SRCSCC))
DEPS         := $(patsubst $(SRCDIR)/%.cc, $(DEPDIR)/%.d, $(SRCSCC))


CXXFLAGS     := -std=c++2a -Wall -Wextra -Wpedantic -ggdb -O0 `sdl2-config --cflags`
CXXFLAGS     += -I$(INCDIR) -I$(LIBDIR)

CXXFLAGSTAGS := -I/home/morion/.vim/tags

LIBS         := -lSDL2 -lSDL2_gfx -lSDL2_ttf -lSDL2_image
LIBRARIES    := $(LIBDIR)/SDL_GUI.a

# create directories
$(foreach dirname,$(dir $(OBJS)) $(dir $(DEPS)),$(shell $(MKDIR) $(dirname)))

.PHONY: all
all: CXXFLAGS += -fsanitize=address
all: LIBS += -fsanitize=address
all: $(TARGET)

.PHONY: run
run: all
	$(TARGET)

.PHONY: clean
clean:
	$(RM) $(BUILD)
	$(RM) $(DEPDIR)

.PHONY: sure
sure: clean
	@$(MAKE) --no-print-directory

.PHONY: debug
debug:
	@echo $(OBJS)

tags: $(SRCSCC)
	$(CXX) $(CXXFLAGSTAGS) $(CXXFLAGS) -M $(SRCSCC) | sed -e 's/[\\ ]/\n/g' | \
	sed -e '/^$$/d' -e '/\.o:[ \t]*$$/d' | \
	ctags -L - --c++-kinds=+p --fields=+iaS --extra=+q -o "tags" --language-force=C++

$(OBJS): $(BUILD)/%.o: $(DEPDIR)/%.d
$(OBJS): $(BUILD)/%.o: $(SRCDIR)/%.cc
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(DEPS): $(DEPDIR)/%.d: $(SRCDIR)/%.cc
	$(CXX) $(CXXFLAGS) -MM -o $@ $<

$(TARGET): $(OBJS) $(LIBRARIES)
	$(CXX) -o $@ $^ $(LIBS)

$(LIBRARIES): $(LIBDIR)/%.a: $(LIBDIR)/%/
	$(MAKE) -C $(LIBDIR)/$* lib
	ln -fs $(CURDIR)/$(LIBDIR)/$*/build/$*.a $(LIBDIR)/$*.a

-include $(DEPS)
