TARGET=cpu-test
SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:%.cpp=%.o)

CPPFLAGS+=-g -I.. -I../../../src
CPPFLAGS+=-O2 # for release
CPPFLAGS+=-Wall -Wextra

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LINK.cpp) $^ $(LOADLIBES) $(LDLIBS) -o $@

clean:
	rm -f $(TARGET) $(OBJS)
