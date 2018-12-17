PROGRAMS = pipesizer filtermultiples primesieve \
	timedwait-poll timedwait-alarm timedwait-block timedwait-blockvar \
	timedwait-selfpipe timedwait-signalfd

all: $(PROGRAMS)

ALLPROGRAMS = $(PROGRAMS) timedwait-sigchld

O = 2
include ../common/rules.mk
LDFLAGS := $(filter-out -no-pie,$(LDFLAGS))

%.o: %.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(DEPCFLAGS) $(O) -o $@ -c $<

$(PROGRAMS): %: %.o
	$(CXX) $(CXXFLAGS) $(O) -o $@ $^ $(LDFLAGS) $(LIBS)


clean:
	rm -f $(ALLPROGRAMS) *.o data
	rm -rf $(DEPSDIR) *.dSYM

.PHONY: all clean
