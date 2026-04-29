*This project has been created as part of the 42 curriculum by `brportos.`*
# get_next_line
## Description
The `get_next_line` project involves programming a function that reads and returns a line from a given file descriptor. This task aims to strengthen key skills in C programming, particularly in understanding how to manage memory and work with file descriptors. One of the core concepts explored in this project is the use of `static variables`, which are crucial for maintaining state across multiple function calls. This project will help refine programming abilities and improve code cleanliness by adhering to the 42 school norms. The functions implemented must be robust, avoiding issues like segmentation faults, bus errors, and double frees, with the exception of undefined behavior. Proper memory management is essential: all heap-allocated memory must be freed when no longer needed, as memory leaks are strictly prohibited.
## Instructions
### Compilation
To test get_next_line, create a main.c file and include the header at the top of your file:
```c
#include "get_next_line.h"
#include <fcntl.h>
#include "ft_printf.h"

int	main()
{
	int	fd = open("fd's name", O_RDONLY);
	char	*buf = get_next_line(fd);

	if (fd < 0)
		return (-1);
	while (buf != NULL)
	{
		ft_printf("%s\n", buf);
		free(buf);
		buf = NULL;
		buf = get_next_line(fd);
	}
	close(fd);
}
```
Then compile the project using one of the following commands:

With a specific BUFFER_SIZE:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *c
```
Or without defining BUFFER_SIZE (if it is already defined in the header file):
```bash
cc *c
```
### Execution
After successful compilation, run the program with:
```bash
./a.out
```
## Resources
man

Google

Peer-to-peer discussions

Youtube

https://youtu.be/kR4FyNzVDBE?si=O-1bYKHFcS_glIJm

https://youtu.be/8E9siq7apUU?si=toqnUt9HK-gI_p5A

https://youtu.be/jT9N8gY36Os

https://youtu.be/XgjJKeL77Ls

AI

AI Usage: AI tools were used only for explanations of concepts and function specifications. No code was copied directly from AI-generated output.
## A detailed explanation and justification algorithm and data structure
The get_next_line function is designed to read a file descriptor line by line, returning one complete line per function call.

### Algorithm Overview

Reading from the File Descriptor The read() system call is used to reading from the file descriptor in chunks of size BUFFER_SIZE. Each call to read() stores the characters in a buffer.

Accumulating the Read Data The newly read buffer is concatenated to a temporary string using a ft_strjoin(). This temporary string stores all accumulated characters that have not yet been returned as a complete line.

Detecting a Newline The function continues reading and concatenating until a newline character ('\n') is found or the end of file is reached. Once a newline is detected, the accumulated string contains at least one complete line.

Updating the Line The function apdate the line up to and including the newline character. This updated portion is returned to the caller.

Preserving the Remaining Data (Static Variable) Any remaining characters after the newline are stored in a static variable. The use of a static variable is essential because it preserves leftover data between function calls. This allows the function to continue reading the file from where it previously stopped without losing information.

Memory Management All dynamically allocated memory is carefully managed:

Temporary buffers are freed when no longer needed.

Only the necessary memory is retained in the static variable.

Memory leaks are avoided by freeing unused allocations.

### Data Structure Justification

The primary data structure used in this implementation is a dynamically allocated string combined with a static variable.

A dynamic string is necessary because the length of each line is unknown in advance.

The static variable allows persistent storage across multiple function calls without using global variables.

This approach ensures efficiency, modularity, and compliance with the project constraints.