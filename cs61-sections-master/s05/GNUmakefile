PROGRAMS = exit2
all: $(PROGRAMS)

include ../common/rules.mk

%.o: %.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(DEPCFLAGS) $(O) -o $@ -c $<

$(PROGRAMS): %: %.o
	$(CXX) $(CXXFLAGS) $(O) -o $@ $^ $(LIBS)

clean:
	$(call run,rm -f $(PROGRAMS) *.o *.dSYM *.core,CLEAN)

.PHONY: all clean
