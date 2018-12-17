PROGRAMS = mexplore.noopt mexplore.opt ubexplore.noopt ubexplore.opt
all: $(PROGRAMS)

ALLPROGRAMS = $(PROGRAMS) add

include ../common/rules.mk

%.o: %.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(O) $(DEPCFLAGS) -o $@ -c $<

%.opt.o: %.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -O3 $(DEPCFLAGS) -o $@ -c $<

%.noopt.o: %.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -O0 $(DEPCFLAGS) -o $@ -c $<

mexplore.noopt ubexplore.noopt: %.noopt: %.noopt.o hexdump.o
	$(CXX) $(CXXFLAGS) -O0 -o $@ $^

mexplore.opt ubexplore.opt: %.opt: %.opt.o hexdump.o
	$(CXX) $(CXXFLAGS) -O3 -o $@ $^

add: add.o addf.o hexdump.o
	$(CXX) $(CXXFLAGS) $(O) -o $@ $^

clean:
	rm -rf $(ALLPROGRAMS) *.o $(DEPSDIR)

.PHONY: all clean
