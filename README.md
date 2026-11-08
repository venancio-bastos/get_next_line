# get_next_line

A function that reads a file descriptor and returns one line at a time, including the terminating `\n` when present.
Part of the 42 Porto curriculum.

## Files

- `get_next_line.c`, `get_next_line.h`, `get_next_line_utils.c`: mandatory part, one stash for a single file descriptor.
- `get_next_line_bonus.c`, `get_next_line_bonus.h`, `get_next_line_utils_bonus.c`: bonus part, one stash per file descriptor.

## Usage

`BUFFER_SIZE` is set at compile time and defaults to 42 in the mandatory part and 1024 in the bonus.

```c
#include "get_next_line.h"

int main(void)
{
	int		fd = open("file.txt", O_RDONLY);
	char	*line;

	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
```

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o program
```

`get_next_line` returns `NULL` at end of file, on a read error, or for an invalid descriptor or `BUFFER_SIZE`. The caller frees each returned line.

## Testing

Checked with AddressSanitizer and UndefinedBehaviorSanitizer on:

- `BUFFER_SIZE=1` and `BUFFER_SIZE=42` on a file with empty lines and a last line without `\n`.
- An empty file.
- Bonus: two descriptors read in alternation, each keeping its own stash.

No memory errors or leaks were reported for these cases.

## Known issues

- **Bonus, descriptors 4096 and above:** the bonus stash is a static array of 4096 pointers, indexed by `fd`. `get_next_line` only checks `fd < 0`. For `fd = 5000`, AddressSanitizer reports a segmentation fault. The check must reject `fd >= 4096` before indexing.
- **No Makefile:** the project has no Makefile yet, so it must be compiled by hand.
- **Unused declaration:** `found_newline` is declared in both headers but not defined or used.

## Status

The mandatory part passes the cases above. The bonus has the descriptor bound issue listed above, which is not fixed yet.
