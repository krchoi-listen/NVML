CC = gcc
CPP = g++

CFLAGS  := -I. -I/usr/local/cuda-10.0/include
LDFLAGS := -lnvidia-ml -L/usr/local/cuda-10.0/lib64/stubs

OBJECTS = TestMain.o GpuQuery.o
TARGET = smi

%.o: %.cpp
	$(CPP) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJECTS)
	$(CPP) -o $@ $^ $(CFLAGS) $(LDFLAGS)
	-rm *.o

.PHONY: clean
clean:
	-rm $(TARGET)

