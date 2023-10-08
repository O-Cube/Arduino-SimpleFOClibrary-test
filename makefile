# @author Obed Oyandut
# source files
SRC = ./testmain.cpp\
      ./Arduino-FOC/src/BLDCMotor.cpp\
      ./UnitTest/BLDCMotorTest/mock_functions.cpp\
      ./UnitTest/BLDCMotorTest/BLDCMotorTest.cpp

# include directories
IFLAGS = -I./\
         -I./arduino_include\
         -I./Arduino-FOC/src\
         -I./Arduino-FOC/src/common\
         -I./Arduino-FOC/src/common/base_classes/\
         -I./Arduino-FOC/src/communication\
         -I./Arduino-FOC/src/current_sense\
         -I./Arduino-FOC/src/current_sense/hardware_specific\
         -I./Arduino-FOC/src/current_sense/hardware_specific/esp32\
         -I./Arduino-FOC/src/current_sense/hardware_specific/rp2040\
         -I./Arduino-FOC/src/current_sense/hardware_specific/samd\
         -I./Arduino-FOC/src/current_sense/hardware_specific/stm32\
         -I./Arduino-FOC/src/drivers\
         -I./Arduino-FOC/src/drivers/hardware_specific\
         -I./Arduino-FOC/src/drivers/hardware_specific/atmega\
         -I./Arduino-FOC/src/drivers/hardware_specific/esp32\
         -I./Arduino-FOC/src/drivers/hardware_specific/renesas\
         -I./Arduino-FOC/src/drivers/hardware_specific/rp2040\
         -I./Arduino-FOC/src/drivers/hardware_specific/samd\
         -I./Arduino-FOC/src/drivers/hardware_specific/stm32\
         -I./Arduino-FOC/src/drivers/hardware_specific/teensy\
         -I./Arduino-FOC/src/sensors\
         -I./UnitTest/BLDCMotorTest\

# executable file produced
EXECUTABLE = test.out
# delete rule
RM = rm
# delete flags
RM_FLAGS = -rf ./*.gcda ./*.gcno ./*.out output/lcov.info
# compiler
CPP = g++
# compiler flags
CFLAGS = -fpermissive -std=c++14 -fprofile-arcs -ftest-coverage -g -O0 
# objects
OBJS = $(SRC:.cpp=.o)
# clean .gcno 
RMGCNO = $(SRC:.cpp=.gcno)
# clean .gcda
RMGCDA = $(SRC:.cpp=.gcda)
# clear objects
OBJSCLEAN := $(filter-out %.cpp, $(OBJS))
# define macros
DFLAGS = -D__COMPILING_AVR_LIBC__

all: create_folder $(EXECUTABLE) coverage

# create output folder
create_folder: 
	mkdir -p output
# create executable
$(EXECUTABLE): $(OBJS)
	@echo "[compile] -> $@"
	$(CPP) $(OBJS) $(CFLAGS) $(IFLAGS) $(DFLAGS) -lgtest -lgmock -lpthread -o$@
# compile code and generate object as .o
%.o: %.cpp
	$(CPP) $(CFLAGS) $(IFLAGS) $(DFLAGS) -c $< -o$@
# generating coverage
coverage:
	./$(EXECUTABLE); lcov --capture --directory . --output-file ./output/lcov.info;\
	lcov -r output/lcov.info '/usr/include/*' \
	'_deps/*' '*gtest*' --output-file output/lcov.info;genhtml output/lcov.info --output-directory /mnt/c/Tests
# clean 
clean:
	$(RM) $(OBJSCLEAN) $(RM_FLAGS) $(RMGCNO) $(RMGCDA)

