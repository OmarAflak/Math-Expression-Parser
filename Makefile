CC = g++
ODIR = obj
PROG = main
CXXFLAGS =-std=c++11

OBJS = $(ODIR)/main.o $(ODIR)/processor.o $(ODIR)/statement.o $(ODIR)/token.o $(ODIR)/utils.o
$(PROG) : $(ODIR) $(OBJS)
	$(CC) -o $@ $(OBJS) $(CXXFLAGS)

$(ODIR)/main.o : ./src/main.cpp ./include/processor.h ./include/statement.h ./include/utils.h ./include/token.h ./include/utils.h ./include/functions.h
	$(CC) -c ./src/main.cpp -o $@ $(CXXFLAGS)

$(ODIR)/processor.o : ./src/processor.cpp ./include/processor.h ./include/statement.h ./include/utils.h ./include/token.h ./include/utils.h ./include/functions.h
	$(CC) -c ./src/processor.cpp -o $@ $(CXXFLAGS)

$(ODIR)/statement.o : ./src/statement.cpp ./include/statement.h ./include/utils.h ./include/token.h ./include/utils.h ./include/functions.h
	$(CC) -c ./src/statement.cpp -o $@ $(CXXFLAGS)

$(ODIR)/token.o : ./src/token.cpp ./include/token.h ./include/utils.h
	$(CC) -c ./src/token.cpp -o $@ $(CXXFLAGS)

$(ODIR)/utils.o : ./src/utils.cpp ./include/utils.h
	$(CC) -c ./src/utils.cpp -o $@ $(CXXFLAGS)

$(ODIR) :
	if [ ! -d $(ODIR) ]; then mkdir $(ODIR); fi

.PHONY : clean
clean :
	if [ -d $(ODIR) ]; then rm $(ODIR) -r; fi
	if [ -f $(PROG) ]; then rm $(PROG); fi
