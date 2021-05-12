TARGET=ArduinoSim
CXX=g++
# CXXFLAGS=-std=c++17 -Wall -Wextra -g
CXXFLAGS = -g -I include -std=c++17 -Wall -Wextra -Wshadow -Wconversion -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Wno-unused

SRCS=$(TARGET).cpp pino.cpp gpio.cpp EEPROM.cpp ui.cpp Uno.cpp String.cpp Sensor.cpp Timer.cpp
HPP=$(TARGET).hpp gpio.h EEPROM.h UNO.h supply.h pino.h String.h ui.h Sensor.h Timer.h
OBJS=$(subst %.cpp, %.o,$(SRCS))

all:$(TARGET)
	./$(TARGET)
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp  $(HPP)
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o 

$(TARGET).o: $(SRCS) $(HPP)
	$(CXX) $(CXXFLAGS) $(SRCS) -c

clean:
	rm -rf *.o *~$(TARGET)