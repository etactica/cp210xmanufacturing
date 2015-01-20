###########################################
# Makefile for libcp210xmanufacturing.so
# using libusb-1.0
#
# Silicon Labs
# 10-22-2012
###########################################

OUT      ?= Release/Linux/

all: $(OUT)libcp210xmanufacturing.so.1.0

install: all
	echo "Fake install target to satisfy OpenWrt build system"

CC       ?= gcc
CFLAGS   ?= -Wall -fPIC -g

CXX      ?= g++
CXXFLAGS ?= -Wall -fPIC -g

COBJS     = 
CPPOBJS   = CP210xManufacturing/CP210xDevice.o \
            CP210xManufacturing/CP2101Device.o \
            CP210xManufacturing/CP2102Device.o \
            CP210xManufacturing/CP2103Device.o \
            CP210xManufacturing/CP2104Device.o \
            CP210xManufacturing/CP2105Device.o \
            CP210xManufacturing/CP2108Device.o \
            CP210xManufacturing/CP2109Device.o \
            CP210xManufacturing/CP210xSupportFunctions.o \
	    CP210xManufacturing/CP210xManufacturing.o
OBJS      = $(COBJS) $(CPPOBJS)
LIBS      = `pkg-config libusb-1.0 --libs`
INCLUDES ?= -I./Common -I./CP210xManufacturing `pkg-config libusb-1.0 --cflags`


$(OUT)libcp210xmanufacturing.so.1.0: $(OBJS)
	$(CXX) -shared -Wl,-soname,libcp210xmanufacturing.so.1 -o $(OUT)libcp210xmanufacturing.so.1.0 $^ $(LIBS)
	
$(COBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(CPPOBJS): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $(INCLUDES) $< -o $@

clean:
	rm -f $(OBJS) $(OUT)libcp210xmanufacturing.so.1.0

.PHONY: clean
