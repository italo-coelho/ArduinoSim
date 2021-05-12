TARGET=teste
CXX=g++
CXXFLAGS=-std=c++17 -Wall -g

SRCS=$(TARGET).cpp pino.cpp gpio.cpp EEPROM.cpp ui.cpp Uno.cpp String.cpp supply.cpp Timer.cpp
HPP=$(TARGET).hpp gpio.h EEPROM.h UNO.h supply.h pino.h String.h ui.h Timer.h
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