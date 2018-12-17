PROGRAMS = fork3 myecho runmyecho forkmyecho spawnmyecho \
	waitdemo selfpipe childpipe

all: $(PROGRAMS)

ALLPROGRAMS = $(PROGRAMS) filtermultiples primesieve

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
