
Andrew Stanton
ASU ID: 1207210559
CSE 450
Project: Closest pair of points

The language I am using is C++. The "closestPair.cpp" file includes all of the
other files, which are .h files. It reads in input from a file called "data", runs the two algorithms, and
outputs information relevant to the execution of the algorithms in a file
called "output." The "structures.h" file defines structures
for points and pairs, and declares the global fstream variable. The
"printer.h" file contains functions used for printing information for
debugging. The "closestPairAlgo1.h" file contains a function that implements the O(n^2) algorithm for computing the closest pair
of points. The "closestPairAlgo2.h" file contains a function that implements
the O(nlog(n)) algorithm for computing the closest pair of points. The
"closestPairAlgo2Debug.h" file contains similar functions to the
"closestPairAlgo2.h" file except it prints out extra debugging information
while executing.

The O(n^2) algorithm works by double-looping through the list of points and
comparing the distance between each point and every other point. It keeps
track of the minimum distance found in this way. My implementation uses two
lists, one for the x coordinates and one for the y coordinates, and it returns
a pointer to a structure that represents the closest pair of points and the
distance between the closest pair of points.

The O(nlog(n)) algorithm works by using two functions. The first function
initializes and sorts two lists, which get passed into the second function,
which is a recursive function. The recursive function has two base cases: one which deals
with 3 points in the list and the other which deals with 2 points in the
list. The function always returns the local closest pair of points. When
the original call returns, it returns the global closest pair of points. Each
recursive call splits the input size into about half. Each call finds the
closest pair of points in its section of the input. In recursive calls (i.e.
not base case cals), the closest pairs from each of the halves are compared. The
distance between them is then used to check whether the distance between some
pair of points with one point in the left section and one point in the right
section has distance less than the smallest distance from each half. It then
returns a pointer to a structure that stores pointers to each point in the
pair of points and the distance between them. Each call is passed a pointer to
the x-list, a pointer to the y-list, the leftmost index of the current
section, and the size of the current section. The x-list is used in the base cases. The y-list is used in the recursive
cases to obtain Sy, the list of points sorted by y-coordinate that are
closer to the midpoint than the closer of the distances found from the left
and right sections.

Sources used during this project:

I used www.cplusplus.com reference pages for information on file streams and how to use
them to read in input and write output, how to keep track of time using C++,
how to use the sort function in C++, how to take the floor, ceiling, square and
square root, how to customize output, how to use the rand function, and other
little things.

I used the following link for information on how to write a makefile:
http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ 

The following stackoverflow page that I used seems to have been the most
helpful link I used for information on how to keep track of time in C++ as it
contains code closest to the code in my solution:
http://stackoverflow.com/questions/361363/how-to-measure-time-in-milliseconds-using-ansi-c/36095407#36095407

I used the following other stackoverflow pages for information on how to keep track
of time in C++:
http://stackoverflow.com/questions/15235218/c-timer-milliseconds
http://stackoverflow.com/questions/10382902/how-to-get-system-clock-in-microseconds-in-c
http://stackoverflow.com/questions/21856025/getting-an-accurate-execution-time-in-c-micro-seconds
http://stackoverflow.com/questions/9385604/timing-a-function-in-microseconds
http://stackoverflow.com/questions/17128773/undefined-reference-to-clock-gettime-in-linux-using-icc
http://stackoverflow.com/questions/5833094/get-a-timestamp-in-c-in-microseconds

I used the following pages for information on how to keep track of time in C++:
https://linux.die.net/man/3/clock_gettime
http://en.cppreference.com/w/cpp/chrono/c/clock
http://pubs.opengroup.org/onlinepubs/7908799/xsh/systime.h.html
http://man7.org/linux/man-pages/man2/gettimeofday.2.html

I used the following stackoverflow pages for information on how to use the sort
function in C++:
http://stackoverflow.com/questions/15669900/using-sort-in-stl-to-sort-an-array
http://stackoverflow.com/questions/3203162/what-does-sizeof-do


