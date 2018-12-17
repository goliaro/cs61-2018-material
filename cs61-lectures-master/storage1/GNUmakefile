PROGRAMS = attackme attackme.unsafe \
	$(sort $(patsubst %.cc,%,$(wildcard [rw][0-9]*.cc))) \
	base-matrixmultiply matrixmultiply

-include conf.mk
ifndef DATAFILE
DATAFILE = data
endif

all: $(PROGRAMS) $(DATAFILE)

ALLPROGRAMS = $(PROGRAMS)

O = 2
include ../common/rules.mk
ifneq ($(DATAFILE),data)
CPPFLAGS += -DDATAFILE='"$(DATAFILE)"'
endif

UNSAFEFLAGS := -U_FORTIFY_SOURCE -fno-stack-protector $(if $(ISLINUX),-no-pie,)

%.o: %.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(DEPCFLAGS) $(O) -o $@ -c $<

attackme.o: attackme.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(DEPCFLAGS) -O1 -o $@ -c $<

%.unsafe.o: %.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(UNSAFEFLAGS) $(CXXFLAGS) -O1 $(DEPCFLAGS) -o $@ -c $<

%.unsafe.s: %.cc GNUmakefile
	@ARGS=$$(grep '^//!' $< | sed 's/.*! *//'); \
	  CXXFLAGS="`echo "$(UNSAFEFLAGS) $(CXXFLAGS) -O1" | sed 's/ *-g */ /'`"; \
	  if test -z "$$ARGS"; then ARGS="$(DEFAULT_ASM_CXXFLAGS)"; fi; \
	  $(call xrun,$(CXX) $$CXXFLAGS $$ARGS -o $@ -S $<,COMPILE -S $$ARGS $<) && { $(call cleanasm,$@); }


attackme: attackme.o
	@$(call xrun,$(CXX) $(CXXFLAGS) $(O) $(LDFLAGS) -o $@ $^ $(LIBS),LINK $@)

attackme.unsafe: attackme.unsafe.o
	@$(call xrun,$(CXX) $(CXXFLAGS) $(UNSAFEFLAGS) $(O) $(LDFLAGS) -o $@ $^ $(LIBS),LINK $@)


base-matrixmultiply matrixmultiply: %: %.o
	@$(call xrun,$(CXX) $(CXXFLAGS) $(O) $(LDFLAGS) -o $@ $^ $(LIBS),LINK $@)


r%: r%.o
	$(CXX) $(CXXFLAGS) $(O) -o $@ $(LDFLAGS) $(LIBS) $^

w%: w%.o
	$(CXX) $(CXXFLAGS) $(O) -o $@ $(LDFLAGS) $(LIBS) $^

DATASIZE := $(shell wc -c $(DATAFILE) 2>/dev/null | awk '{ print $$1 }')
DATADEP := $(shell if test "$(DATASIZE)" -lt 51200000; then echo always; fi)

$(DATAFILE): $(DATADEP)
	yes 77777777777777777777777777777777777777777 | tr -d '\n' | head -c 51200000 > $@

ifneq ($(DATAFILE),data)
data: $(DATAFILE)
.PHONY: data
endif


clean:
	rm -f $(ALLPROGRAMS) *.o data
	rm -rf $(DEPSDIR) *.dSYM
	for i in r[0-9][0-9]* w[0-9][0-9]*; do if file $$i | grep executable >/dev/null 2>&1; then rm -f $$i; fi; done

.PHONY: all clean
