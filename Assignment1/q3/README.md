# Concurrent Command Execution

This program executes multiple shell commands concurrently using fork() and exec(). (https://github.com/mohsink20)

## Compiling

To compile, run:

```
make
```

This will produce an executable called `myshell`.

## Running 

To run the program:

```
./myshell <command1> <command2> ...
```

For example:

```
./myshell /bin/ls /bin/uname /bin/who /bin/ps
```

This will execute `ls`, `uname`, etc concurrently.

The program will print output showing the execution and the status of each command.

## Testing

Some ways I tested the program:

- Run with valid commands - check all complete successfully 

```
./myshell /bin/ls /bin/pwd /bin/date
```

- Run with an invalid command - should see failed execution

```
./myshell /bin/ls /bin/abcd /bin/date
```

- Check exit codes - valid commands should exit 0, invalid should be non-zero

```
./myshell /bin/true /bin/false /bin/ls
```

- Give invalid arguments - check for clean usage error message

```
./myshell
```

- Run simultaneously in multiple terminals - check for conflicts


## Platform Support

This program uses UNIX process and threading functions like `fork()`, `exec()`, `wait()` etc. It is designed for Linux and macOS - it will not work on Windows without modifications.
