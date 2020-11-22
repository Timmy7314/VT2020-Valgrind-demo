# VT2020: Demo to test Valgrind

## Requirements

Install valgrind :

```bash
$ sudo apt-get install valgrind
```

## Compile the project

:warning: Before each time you want compile the project **you have to clean it**:

```bash
$ make clean
``` 

After that you have to run the following command:
```bash
$ make DEBUG=1 PROG=... 
```
The parameter `PROG` can take several values:
* `1` To get an error free and memory leak free version of the code: `$ make DEBUG=1 PROG=1`
* `2` To get an error-free version of the code but with memory leaks: `$ make DEBUG=1 PROG=2`
* `3` To get memory leak free version of the code but with an error: `$ make DEBUG=1 PROG=3`
* `4` To get version of the code with error and memory leaks: `$ make DEBUG=1 PROG=4`