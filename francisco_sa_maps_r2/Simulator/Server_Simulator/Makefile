PROGRAM_NAME=exec
CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g  -Wdeprecated-declarations --std=c++17 -I/usr/include -I/usr/local/include
LDFLAGS=-g -L/usr/local/lib -L /usr/lib
LDFLAGS += -pthread -Wl,--no-as-needed
LDLIBS= -lprotobuf -lmosquittopp -lmosquitto

SRCS=$(wildcard *.cpp)
SRCS += $(wildcard ../protobuf_api/out/*.cpp)
OBJS=$(subst .cpp,.o,$(SRCS))

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(OBJS)
	$(CXX) $(LDFLAGS) -o  $(PROGRAM_NAME) $(OBJS) $(LDLIBS)

clean:
	$(RM) *.o ../protobuf_api/out/*.o $(PROGRAM_NAME)

