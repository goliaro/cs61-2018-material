BASEPROGRAMS = mexplore mexplore-struct ubexplore
PROGRAMS = $(BASEPROGRAMS) $(patsubst %,%.noopt,$(BASEPROGRAMS))
all: $(PROGRAMS)

ALLPROGRAMS = $(PROGRAMS)

include ../common/rules.mk

%.o: %.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(O) $(DEPCFLAGS) -o $@ -c $<

%.opt.o: %.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -O3 $(DEPCFLAGS) -o $@ -c $<

%.noopt.o: %.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -O0 $(DEPCFLAGS) -o $@ -c $<

$(patsubst %,%.noopt,$(BASEPROGRAMS)): %.noopt: %.noopt.o hexdump.o
	$(CXX) $(CXXFLAGS) -O0 -o $@ $^

$(BASEPROGRAMS): %: %.o hexdump.o
	$(CXX) $(CXXFLAGS) -O3 -o $@ $^

clean:
	rm -rf $(ALLPROGRAMS) *.o $(DEPSDIR)

.PHONY: all clean
