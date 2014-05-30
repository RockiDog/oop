sample:sample.cpp Connection.o Query.o Insert.o Delete.o Update.o Select.o
	g++ -o sample sample.cpp Connection.o Query.o Insert.o Delete.o Update.o Select.o \
	-lmysqlpp -lmysqlclient
Connection.o:Connection.cpp Connection.h
	g++ -c Connection.cpp
Query.o:Query.cpp Query.h
	g++ -c Query.cpp
Insert.o:Insert.cpp Insert.h
	g++ -c Insert.cpp
Delete.o:Delete.cpp Delete.h
	g++ -c Delete.cpp
Update.o:Update.cpp Update.h
	g++ -c Update.cpp
Select.o:Select.cpp Select.h
	g++ -c Select.cpp
clean:
	rm Connection.o Query.o Insert.o Delete.o Update.o Select.o
truncate:
	rm Connection.o Query.o Insert.o Delete.o Update.o Select.o sample
