PROGRAMS = bbuffer-basic bbuffer-mutex bbuffer-scoped bbuffer-cond

all: $(PROGRAMS)

ALLPROGRAMS = $(PROGRAMS) bbuffer-guard

O = 2
include ../common/rules.mk
LDFLAGS := $(filter-out -no-pie,$(LDFLAGS))
LIBS := -lpthread

%.o: %.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(DEPCFLAGS) $(O) -o $@ -c $<

%.noopt.o: %.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(DEPCFLAGS) -O0 -o $@ -c $<

%: %.o
	$(CXX) $(CXXFLAGS) $(O) -o $@ $^ $(LDFLAGS) $(LIBS)

%.noopt: %.noopt.o
	$(CXX) $(CXXFLAGS) -O0 -o $@ $^ $(LDFLAGS) $(LIBS)


clean:
	rm -f $(ALLPROGRAMS) *.o *.core data
	rm -rf $(DEPSDIR) *.dSYM

.PRECIOUS: %.noopt.o
.PHONY: all clean
