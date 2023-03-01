# get_next_line
open(), read() and close(), just learn those things.

|Function name | get_next_line |
|Prototype | char *get_next_line(int fd); |
|Turn in files | get_next_line.c, get_next_line_utils.c, get_next_line.h |
|Parameters | File descriptor to read from |
|Return value | Read line: correct behavior<br>NULL: nothing else to read or an error occurred |
|External functs. | read, malloc, free |
## Description
Write a function that reads a line from a file descriptor and returns it. The function should behave correctly when reading from a file or from the standard input.

Calling __get_next_line__ in a loop will allow you to read the text available on the file descriptor one line at a time until the end of it.

Your function should return the line that has just been read. If there is nothing else to read or if an error has occurred it should return NULL.

You must add a get_next_line_utils.c file which will contain the functions that are needed for your __get_next_line__ to work.

Your program must compile with the flag -D BUFFER_SIZE=xx, which will be used as the buffer size for the read calls in your __get_next_line__. This value will be modified by your evaluators and by the moulinette.

Your read must use the BUFFER_SIZE defined during compilation to read from a file or from stdin. This value will be modified during the evaluation for testing purposes.

In the header file __get_next_line__.h, you must have at least the prototype of the function __get_next_line__.

lseek is not an allowed function. File reading must be done only once.

We consider that __get_next_line__ has undefined behavior if, between two calls, the same file descriptor switches to a different file before reading everything from the first fd.

Finally, we consider that __get_next_line__ has undefined behavior when reading from a binary file. However, if you wish, you can make this behavior coherent.

## Bonus Part
To succeed __get_next_line__ with a single static variable.
To be able to manage multiple file descriptors with your __get_next_line__. For example, if the file descriptors 3, 4 and 5 are accessible for reading, then you can call __get_next_line__ once on 3, once on 4, once again on 3 then once on 5 etc. without losing the reading thread on each of the descriptors.