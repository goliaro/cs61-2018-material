# build all programs with names like `membug[0-9]`
MEMBUG_PROGRAMS = $(patsubst %.cc,%,$(sort $(wildcard membug[0-9].cc)))
all: $(MEMBUG_PROGRAMS) greet inv

ALLPROGRAMS = $(MEMBUG_PROGRAMS) greet inv

# Default optimization level
O ?= -O0

LIBS = -lm

include ../common/rules.mk

%.o: %.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(DEPCFLAGS) $(O) -o $@ -c $<

membug%: membug%.o
	$(CXX) $(CXXFLAGS) $(O) -o $@ $^ $(LIBS)

greet: greet.o
	$(CXX) $(CXXFLAGS) $(O) -o $@ $^ $(LIBS)

inv: inv.o
	$(CXX) $(CXXFLAGS) $(O) -o $@ $^ $(LIBS)

clean: clean-main
clean-main:
	$(call run,rm -f $(ALLPROGRAMS) *.o core *.core,CLEAN)
	$(call run,rm -rf out $(DEPSDIR) *.dSYM)

.PHONY: all clean clean-main
