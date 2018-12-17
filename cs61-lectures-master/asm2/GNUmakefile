ASMS := $(patsubst %.cc,%.s,$(sort $(wildcard f[0-9][0-9].cc)))
ASM_OBJECTS := $(patsubst %.s,%.o,$(ASMS))
ASM_PROGRAMS := $(shell grep -l main $(wildcard f[0-9][0-9].s f[0-9][0-9].cc) | sed 's/\.[cs]*//' | sort -u)
DEFAULT_ASM_CXXFLAGS = -O1
DEFAULT_ASM_CXXFLAGS_DEBUG = -g $(DEFAULT_ASM_CXXFLAGS)

PROGRAMS = $(ASM_PROGRAMS)

all: $(ASMS) $(PROGRAMS)

asm: cleanasm $(ASMS) $(PROGRAMS)

ALLPROGRAMS = $(PROGRAMS)

O = 1
include ../common/rules.mk

UNSAFEFLAGS := -U_FORTIFY_SOURCE -fno-stack-protector $(if $(ISLINUX),-no-pie,)

%.o: %.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(DEPCFLAGS) $(O) -o $@ -c $<

%.noopt.o: %.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(DEPCFLAGS) -O0 -o $@ -c $<

%.unsafe.o: %.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(UNSAFEFLAGS) $(CXXFLAGS) $(DEPCFLAGS) $(O) -o $@ -c $<

%.unsafenoopt.o: %.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(UNSAFEFLAGS) $(CXXFLAGS) $(DEPCFLAGS) -O0 -o $@ -c $<


$(ASM_OBJECTS): %.o: %.s $(BUILDSTAMP)
	$(call run,$(CXX) -o $@ -c,ASSEMBLE,$<)

%.s: %.cc GNUmakefile
	@ARGS=$$(grep '^//!' $< | sed 's/.*! *//'); \
	  CXXFLAGS="`echo "$(CXXFLAGS)" | sed 's/ *-g */ /'`"; \
	  if test -z "$$ARGS"; then ARGS="$(DEFAULT_ASM_CXXFLAGS)"; fi; \
	  $(call xrun,$(CXX) $$CXXFLAGS $$ARGS -o $@ -S $<,COMPILE -S $$ARGS $<) && { $(call cleanasm,$@); }

%.unsafe.s: %.cc GNUmakefile
	@ARGS=$$(grep '^//!' $< | sed 's/.*! *//'); \
	  CXXFLAGS="`echo "$(UNSAFEFLAGS) $(CXXFLAGS)" | sed 's/ *-g */ /'`"; \
	  if test -z "$$ARGS"; then ARGS="$(DEFAULT_ASM_CXXFLAGS)"; fi; \
	  $(call xrun,$(CXX) $$CXXFLAGS $$ARGS -o $@ -S $<,COMPILE -S $$ARGS $<) && { $(call cleanasm,$@); }

$(ASM_PROGRAMS): %: %.s
	@ARGS=$$(grep '^//!' $< | sed 's/.*! *//'); \
	  CXXFLAGS="`echo "$(CXXFLAGS)" | sed 's/ *-g */ /;s/ *-std=[^ ]* */ /'`"; \
	  if test -z "$$ARGS"; then ARGS="$(DEFAULT_ASM_CXXFLAGS)"; fi; \
	  $(call xrun,$(CXX) $$CXXFLAGS $$ARGS -o $@ $<,ASSEMBLE $@)


allfc.txt: $(wildcard f*.cc) always
	for i in f*.cc; do echo $$i; echo ========; cat $$i; echo; echo; done > allfc.txt

allfs.txt: $(patsubst %.cc,%.s,$(wildcard f*.cc)) always
	for i in f*.s; do echo $$i; echo ========; cat $$i; echo; echo; done > allfs.txt


clean:
	rm -f $(ALLPROGRAMS) *.o

cleanasm: clean
	rm -f $(patsubst %.cc,%.s,$(wildcard f*.cc))

.PHONY: all clean cleanasm asm
