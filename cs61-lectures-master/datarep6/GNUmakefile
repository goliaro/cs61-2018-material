MEMBENCH_PROGRAMS = mb-malloc
ifneq ($(findstring /,$(shell whereis libjemalloc 2>/dev/null)),)
MEMBENCH_PROGRAMS += mb-jemalloc
endif
ifneq ($(findstring /,$(shell whereis libtcmalloc 2>/dev/null)),)
MEMBENCH_PROGRAMS += mb-tcmalloc
endif
MEMBENCH_PROGRAMS += $(patsubst mb-%.cc,mb-%,$(sort $(wildcard mb-*.cc)))
PROGRAMS = $(MEMBENCH_PROGRAMS)

all: $(PROGRAMS)

ALLPROGRAMS = $(PROGRAMS) membench mb-jemalloc mb-tcmalloc \
	stacksmash stacksmash.unsafe stacksmashf stacksmashf.unsafe \
	heapsmash heapsmash.unsafe heapsmashf heapsmashf.unsafe

include ../common/rules.mk

%.o: %.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(O) $(DEPCFLAGS) -o $@ -c $<

%.opt.o: %.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -O3 $(DEPCFLAGS) -o $@ -c $<

%.noopt.o: %.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -O0 $(DEPCFLAGS) -o $@ -c $<

mb-%: membench.o mb-%.o
	$(CXX) $(CXXFLAGS) $(O) -o $@ $^ -lpthread

mb-tcmalloc: membench.o mb-malloc.o
	$(CXX) $(CXXFLAGS) $(O) -o $@ $^ -lpthread -ltcmalloc

mb-jemalloc: membench.o mb-malloc.o
	$(CXX) $(CXXFLAGS) $(O) -o $@ $^ -lpthread -ljemalloc

ubexplore2: ubexplore2.o
	$(CXX) $(CXXFLAGS) $(O) -o $@ $^

ubexplore2.noopt: ubexplore2.noopt.o
	$(CXX) $(CXXFLAGS) -O0 -o $@ $^


clean:
	rm -f $(ALLPROGRAMS) *.o
	rm -rf $(DEPSDIR) *.dSYM

.PHONY: all clean
