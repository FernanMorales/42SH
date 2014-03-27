# CKL - a fast linked list library

I am developping this library for my personnal needs while learning all the
things at [school 42](http://www.42.fr/). I'm releasing it under the terms of
the [MIT license](http://conradk.mit-license.org/license.html).

Quick feature list:
* UNIX compatible
* standalone
* fast
* simple to use

If you use it, please let me know what you think of it.

## Compiling

The library has no dependencies. Just `git clone` this repository, go to its
folder and type `make`. This will create the library's binary in
`bin/libckl.a`.

```shell
git clone https://github.com/conradkleinespel/libckl.git
cd libckl
# without debug flags
make all
# or with debug flags
make all_debug
```

Then, to use it with a C file of yours, you could do something like:
```shell
gcc main.c -Ilibckl -Llibckl/bin -lcks
```

## Tests

You can run the unit tests like so - this:
```shell
git clone https://github.com/conradkleinespel/libckl.git
cd libckl
# without debug flags
make test
# or with debug flags
make test_debug
./bin/test
```
