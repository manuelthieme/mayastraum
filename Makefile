BUILD = build
ifneq ($(notdir $(CURDIR)),$(BUILD))

.SUFFIXES:
OBJDIR := $(CURDIR)/build
DEPDIR := $(CURDIR)/.d
INCDIR := $(CURDIR)/inc
SRCDIR := $(CURDIR)/src
LIBDIR := $(CURDIR)/lib

RM     := rm -rf
MKDIR  := mkdir -p
TARGET       := main

SRCSALL      := $(shell find $(CURDIR) -name "*.cc" -o -name "*.h")
SRCSCCABS    := $(filter %.cc, $(SRCSALL))
SRCSCC       := $(patsubst $(SRCDIR)/%,%,$(SRCSCCABS))

# create directories
$(foreach dirname,$(dir $(SRCSCC)),$(shell $(MKDIR) $(DEPDIR)/$(dirname)))
$(foreach dirname,$(dir $(SRCSCC)),$(shell $(MKDIR) $(OBJDIR)/$(dirname)))

.PHONY: $(all)
all: lib
	+@$(MAKE) --no-print-directory -C $(OBJDIR) -f $(CURDIR)/Makefile \
	 SRCDIR=$(SRCDIR) INCDIR=$(INCDIR) DEPDIR=$(DEPDIR) ROOTDIR=$(CURDIR) \
	 LIBDIR=$(LIBDIR) TARGET=$(TARGET) \
	 $(MAKECMDGOALS)

.PHONY: lib
lib:
	$(MAKE) -C $(LIBDIR)/SDL_GUI lib

.PHONY: run
run: all
	$(OBJDIR)/$(TARGET)

Makefile : ;

% :: all ;

.PHONY: clean
clean:
	$(RM) $(OBJDIR)
	$(RM) $(DEPDIR)

.PHONY: superclean
superclean: clean
	$(MAKE) -C $(LIBDIR)/SDL_GUI clean

.PHONY: sure
sure: clean
	@$(MAKE) --no-print-directory

.PHONY: supersure
supersure: superclean sure

else

SRCSALL      := $(shell find $(ROOTDIR) -path $(LIBDIR) -prune -o -path $(ROOTDIR)/_old -prune -o -name "*.cc" -o -name "*.h")
SRCSCCABS    := $(filter %.cc, $(SRCSALL))
SRCSCC       := $(patsubst $(SRCDIR)/%,%,$(SRCSCCABS))
SRCHABS      := $(filter %.h, $(SRCSALL))
SRCSH        := $(patsubst $(INCDIR)/%,%,$(SRCSHABS))
OBJS         := $(SRCSCC:.cc=.o)
DEPS         := $(addprefix $(patsubst $(ROOTDIR)/%,%,$(DEPDIR))/,$(SRCSCC:.cc=.d))

CXXFLAGS     := -std=c++2a -Wall -Wextra -Wpedantic -ggdb -O0 `sdl2-config --cflags`
CXXFLAGS     += -I$(INCDIR) -I$(LIBDIR)

CXXFLAGSTAGS := -I/home/morion/.vim/tags

LIBS         := -lSDL2 -lSDL2_gfx -lSDL2_ttf -lSDL2_image

vpath %.h $(dir $(SRCSHABS))
vpath %.cc $(dir $(SRCSCCABS))
vpath %.d $(dir $(addprefix $(DEPDIR)/, $(DEPS)))

.PHONY: all
all: $(TARGET)

.PHONY: run
run: all


.PHONY: tags
tags: $(ROOTDIR)/tags

.PHONY: sanitized
sanitized: CXXFLAGS += -fsanitize=address
sanitized: LIBS += -fsanitize=address
sanitized: all

.PHONY: effective
effective: CXXFLAGS += -Weffc++
effective: all

.PHONY: makefile-debug
makefile-debug:
	@echo $(SRCSALL)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LIBDIR)/SDL_GUI/build/SDL_GUI.a $(LIBS)

$(DEPDIR)/%.d: %.cc
	$(CXX) $(CXXFLAGS) -MM -o $@ $<

$(ROOTDIR)/tags: $(SRCSCC)
	$(CXX) $(CXXFLAGSTAGS) $(CXXFLAGS) -M $(SRCSCCABS) | sed -e 's/[\\ ]/\n/g' | \
	sed -e '/^$$/d' -e '/\.o:[ \t]*$$/d' | \
	ctags -L - --c++-kinds=+p --fields=+iaS --extra=+q -o "$(ROOTDIR)/tags" --language-force=C++

-include $(DEPS)

endif
