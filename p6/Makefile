calendar.out : appt.o calendar.o day.o DayOfWeek.o main.o time.o weeklyappt.o
	g++ -ansi -Wall -o calendar.out appt.o calendar.o day.o DayOfWeek.o main.o time.o weeklyappt.o -g

main.o : main.cpp calendar.h appt.h 
	g++ -ansi -Wall -c main.cpp -g

calendar.o : calendar.cpp calendar.h day.h vector.cpp vector.h DayOfWeek.o
	g++ -ansi -Wall -c calendar.cpp -g

day.o : day.cpp day.h appt.h DayOfWeek.h linkedlist.cpp linkedlist.h
	g++ -ansi -Wall -c day.cpp -g

appt.o : appt.cpp appt.h time.h 
	g++ -ansi -Wall -c appt.cpp -g

weeklyappt.o : weeklyappt.cpp weeklyappt.h
	g++ -ansi -Wall -c weeklyappt.cpp -g

DayOfWeek.o : DayOfWeek.cpp DayOfWeek.h 
	g++ -ansi -Wall -c DayOfWeek.cpp -g

time.o : time.cpp time.h 
	g++ -ansi -Wall -c time.cpp -g

clean : 
	rm -f calendar.out appt.o  calendar.o  day.o  DayOfWeek.o  main.o  time.o  weeklyappt.o
