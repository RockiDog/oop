sample:sample.cpp Connection.o Query.o Insert.o Delete.o Update.o Select.o
	g++ -o sample sample.cpp Connection.o Query.o Insert.o Delete.o Update.o Select.o \
	    -lmysqlclient -lmysqlpp 
Connection.o:Connection.cpp Connection.h
	g++ -c -fPIC Connection.cpp
Query.o:Query.cpp Query.h
	g++ -c -fPIC Query.cpp
Insert.o:Insert.cpp Insert.h
	g++ -c -fPIC Insert.cpp
Delete.o:Delete.cpp Delete.h
	g++ -c -fPIC Delete.cpp
Update.o:Update.cpp Update.h
	g++ -c -fPIC Update.cpp
Select.o:Select.cpp Select.h
	g++ -c -fPIC Select.cpp
clean:
	rm Connection.o Query.o Insert.o Delete.o Update.o Select.o
truncate:
	rm Connection.o Query.o Insert.o Delete.o Update.o Select.o sample
