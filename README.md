# 42 GetNextLine
<p float='left' align='center'>
<img src="https://user-images.githubusercontent.com/47778244/231216804-a80ff118-3e1e-4af2-8962-b60f378cd9cd.png" width='20%'>
<img src="https://user-images.githubusercontent.com/47778244/231217008-e0235f9b-7b7a-43e1-9415-852fa6bebaab.png" width='20%'>
</p>

## Table of Contents

<!-- TODO Del table of content -->
- [42 GetNextLine](#42-getnextline)
	- [Table of Contents](#table-of-contents)
	- [About ](#about-)
	- [Getting Started ](#getting-started-)
	- [Usage ](#usage-)

## About <a name = "about"></a>

The goal of this project is to create a function to obtain the next line (until the next **\n**) of the current file descriptor *fd*.

If an __*error*__ occurs or if the file is empty the function will returns **NULL**.

## Getting Started <a name = "getting_started"></a>

``` bash
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=2 get_next_line.c get_next_line_utils.c
```
You can set the BUFFER_SIZE by using the -D flag *(default is 42)*:
``` bash
-D BUFFER_SIZE=1
```

## Usage <a name = "usage"></a>

Call get_next_line in the loop until it returns NULL, each line returned by get_next_line must be free:

``` c
#include <stdio.h>

int main(void)
{
	int  fd;
	char *str;
 
	fd = open("/path_to_file/texte.txt", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s\n", str);
		free(str);
	}
	return (0);
}
```
