MEMBENCH_PROGRAMS = membench $(patsubst mb-%.cc,membench-%,$(wildcard mb-*.cc))
ifneq ($(wildcard /usr/lib/libjemalloc* /usr/lib/i386-linux-gnu/libjemalloc*),)
MEMBENCH_PROGRAMS += membench-jemalloc
endif
ifneq ($(wildcard /usr/lib/libtcmalloc_minimal*),)
MEMBENCH_PROGRAMS += membench-tcmalloc
endif

PROGRAMS = $(MEMBENCH_PROGRAMS) ubexplore2 ubexplore2.noopt \
	ubexplore2u ubexplore2u.noopt ubexplore2l ubexplore2l.noopt

all: $(PROGRAMS)

ALLPROGRAMS = $(PROGRAMS) membench-jemalloc membench-tcmalloc \
	stacksmash stacksmash.unsafe stacksmashf stacksmashf.unsafe \
	heapsmash heapsmash.unsafe heapsmashf heapsmashf.unsafe

include ../common/rules.mk

%.o: %.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(O) $(DEPCFLAGS) -o $@ -c $<

%.opt.o: %.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -O3 $(DEPCFLAGS) -o $@ -c $<

%.noopt.o: %.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -O0 $(DEPCFLAGS) -o $@ -c $<

membench: membench.o mb-malloc.o
	$(CXX) $(CXXFLAGS) $(O) -o $@ $^ -lpthread

membench-%: membench.o mb-%.o
	$(CXX) $(CXXFLAGS) $(O) -o $@ $^ -lpthread

membench-tcmalloc: membench.o mb-malloc.o
	$(CXX) $(CXXFLAGS) $(O) -o $@ $^ -lpthread -ltcmalloc_minimal

membench-jemalloc: membench.o mb-malloc.o
	$(CXX) $(CXXFLAGS) $(O) -o $@ $^ -lpthread -ljemalloc

ubexplore2 ubexplore2u ubexplore2l: %: %.o
	$(CXX) $(CXXFLAGS) $(O) -o $@ $^

ubexplore2.noopt ubexplore2u.noopt ubexplore2l.noopt: %: %.o
	$(CXX) $(CXXFLAGS) -O0 -o $@ $^


clean:
	rm -f $(ALLPROGRAMS) *.o

.PHONY: all clean
