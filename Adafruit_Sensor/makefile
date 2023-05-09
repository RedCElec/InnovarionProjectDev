CXX = g++
CXXFLAGS = -Wall -I/home/Adafruit_Sensor -I/home/Adafruit_MMA8451
LDFLAGS = -L/usr/local/lib
LIBS = -lwiringPi /home/Adafruit_Sensor/libAdafruit_Sensor.a /home/Adafruit_Sensor/libAdafruit_MMA8451.a

SRCS = main.cpp Accelerometer.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(OBJS)
	$(CXX) $(LDFLAGS) -o fall_detection $(OBJS) $(LIBS)

main.o: main.cpp Accelerometer.h
	$(CXX) $(CXXFLAGS) -I/home/Adafruit_Sensor -c main.cpp

Accelerometer.o: Accelerometer.cpp Accelerometer.h
	$(CXX) $(CXXFLAGS) -I/home/Adafruit_Sensor -c Accelerometer.cpp

clean:
	rm -f fall_detection $(OBJS)
