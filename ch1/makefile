CXXFLAGS += -std=gnu++11 -Wall

#如果没有这条，会提示no rule to make Sales_item.h
#应该是被规则main.o : main.cpp Sales_item.h依赖
VPATH += ../include 

TARGET = bookstore

LOCAL_INCLUDE = -I../include

$(TARGET) : main.o
	@echo TARGET:$@ 
	@echo OBJECTS:$^
	g++ -o bookstore main.o $(CXXFLAGS)

main.o : main.cpp Sales_item.h
	@echo TARGET:$@
	@echo OBJECTS:$^
	g++ -c main.cpp $(LOCAL_INCLUDE) $(CXXFLAGS)

clean:
	rm main.o bookstore
