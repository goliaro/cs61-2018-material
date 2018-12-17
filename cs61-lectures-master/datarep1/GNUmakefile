PROGRAMS = testqs0 testqs1 testqs2 testqs3 testqs4 testqs5 testqs6 add addin
all: $(PROGRAMS)

ALLPROGRAMS = $(PROGRAMS)

include ../common/rules.mk

%.o: %.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(DEPCFLAGS) $(O) -o $@ -c $<

testqs0: testqs0.o qslib.o allowexec.o hexdump.o
	$(CXX) $(CXXFLAGS) $(O) -o $@ $^

testqs1: testqs1.o qslib.o allowexec.o hexdump.o
	$(CXX) $(CXXFLAGS) $(O) -o $@ $^

testqs2: testqs2.o qslib.o allowexec.o hexdump.o
	$(CXX) $(CXXFLAGS) $(O) -o $@ $^

testqs3: testqs3.o qslib.o allowexec.o hexdump.o
	$(CXX) $(CXXFLAGS) $(O) -o $@ $^

testqs4: testqs4.o qslib.o allowexec.o hexdump.o
	$(CXX) $(CXXFLAGS) $(O) -o $@ $^

testqs5: testqs5.o qslib.o allowexec.o hexdump.o
	$(CXX) $(CXXFLAGS) $(O) -o $@ $^

testqs6: testqs6.o qslib.o allowexec.o hexdump.o
	$(CXX) $(CXXFLAGS) $(O) -o $@ $^

add: add.o addf.o hexdump.o
	$(CXX) $(CXXFLAGS) $(O) -o $@ $^

addin: addin.o hexdump.o
	$(CXX) $(CXXFLAGS) $(O) -o $@ $^

addf.o: addf.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(O) $(DEPCFLAGS) -fomit-frame-pointer -o $@ -c $<


clean:
	rm -rf $(ALLPROGRAMS) runevil *.o $(DEPSDIR)

.PHONY: all clean
