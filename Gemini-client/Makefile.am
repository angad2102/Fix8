bin_PROGRAMS = GeminiFix8 
lib_LTLIBRARIES = libGeminiFix8.la
ACLOCAL_AMFLAGS = -I m4
GeminiFix8_SOURCES = GeminiFix8.cpp GeminiFix8.hpp
libGeminiFix8_la_SOURCES = gemini_classes.cpp gemini_types.hpp gemini_types.cpp gemini_traits.cpp \
                      gemini_router.hpp gemini_classes.hpp
GeminiFix8_LDADD = libGeminiFix8.la
BUILT_SOURCES = $(libGeminiFix8_la_SOURCES) 
CLEANFILES = $(libGeminiFix8_la_SOURCES)
libGeminiFix8_la_CXXFLAGS = -I$(top_srcdir)/include
AM_CXXFLAGS = -I$(top_srcdir)/include

XML_SCHEMA = $(top_srcdir)/schema/FIX44.xml
.NOTPARALLEL: $(XML_SCHEMA) 

LIBGEMINIFIX8 = --verbose --retain

if F8TESTSTATIC
LIBGEMINIFIX8 += --noshared
endif

$(libGeminiFix8_la_SOURCES): $(XML_SCHEMA)
	$(top_srcdir)/compiler/f8c $(LIBGEMINIFIX8) --prefix gemini --namespace GEMINI $(XML_SCHEMA)

POCO_LIBS = -lPocoFoundation -lPocoNet -lPocoUtil -lPocoXML
GEN_LIBS = -lfix8 -lpthread
if LINK_RT
GEN_LIBS += -lrt
endif
if BDBSUPPORT
GEN_LIBS += -ldb_cxx
endif
if TBBSUPPORT
GEN_LIBS += -ltbb
endif
if LIBMEMCACHEDSUPPORT
GEN_LIBS += -lmemcached
endif
if LIBHIREDISSUPPORT
GEN_LIBS += -lhiredis
endif

ALL_LIBS = $(GEN_LIBS) $(POCO_LIBS) -L$(top_srcdir)/runtime
if !USEOSX
ALL_LIBS += -rdynamic
endif

if TOGGLETRACKINGASSIGNMENTS
libGeminiFix8_la_CXXFLAGS += -fno-var-tracking -fno-var-tracking-assignments
endif
GeminiFix8_LDFLAGS = $(ALL_LIBS) -lmyfix
if USECOMPRESSION
GeminiFix8_LDFLAGS += -lz
endif
if USESSL
GeminiFix8_LDFLAGS += -lPocoNetSSL -lPocoCrypto
endif
