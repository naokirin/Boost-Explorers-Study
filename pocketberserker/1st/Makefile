MSYS_DIR = /c/install/MinGW/msys/1.0/bin

GTEST_DIR = /c/install/gtest-1.6.0

USER_DIR = ./

CPPFLAGS += -I$(GTEST_DIR)/include

CXXFLAGS += -g -Wall -Wextra

TESTS = mystack_unittest

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

all : clean $(TESTS) test

clean :
	$(MSYS_DIR)/rm -f $(TESTS) gtest.a gtest_main.a *.o

test :
	$(USER_DIR)/mystack_unittest.exe

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

mystack_unittest.o : $(USER_DIR)/mystack.hpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/mystack_unittest.cpp

mystack_unittest : mystack_unittest.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@
