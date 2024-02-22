# Simple Shell

## Overview
This is a simple Unix shell written in C Programming Language. It supports basic Unix commands with arguments and flags. The goal of this project is to replicate the functionality of a basic Unix shell like the one found in Ubuntu 20.04.

## Features
- Executes basic commands such as `ls`, `cd`, etc.
- Handles command line arguments and flags.
- Supports input/output redirection (e.g., `>`, `>>`, `<`).
- Supports piping of commands (e.g., `command1 | command2`).
- Interactive and batch mode support.

## Usage
1. Clone the repository:
   ```
   git clone <repository_url>
   ```
2. Compile the code:
   ```
   <compile_command>
   ```
3. Run the shell:
   ```
   ./simple_shell
   ```
4. Use the shell as you would a regular Unix shell:
   ```
   $ ls -l
   $ cd <directory>
   $ <command> <arguments>
   ```

## Implementation Details
- The shell is implemented using C Programming Language.
- Command parsing is done using string manipulation and tokenization techniques.
- Execution of commands is handled through system calls and library functions.

## Future Improvements
- Adding support for more advanced features such as command history, tab completion, and job control.
- Improving error handling and input validation.
- Enhancing performance through optimizations.

## Contributors
- [Manuel Rombe Fungate Jr.](https://github.com/manuelfungas) and [Joseph](https://github.com/Degreatjoe)

## License


## Acknowledgments
- Inspired by the [GNU Bash](https://www.gnu.org/software/bash/) shell.
- Special thanks to ALX for guidance and support.

