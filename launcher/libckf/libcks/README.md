# CKS - a fast & binary safe string library

I am developping this library for my personnal needs while learning all the
things at [school 42](http://www.42.fr/). I'm releasing it under the terms of
the [MIT license](http://conradk.mit-license.org/license.html).

Quick feature list:
* UNIX compatible
* standalone
* fast
* binary safe
* overflow mitigation
* simple to use

If you use it, please let me know what you think of it.

## Compiling

The library has no dependencies. Just `git clone` this repository, go to its
folder and type `make`. This will create the library's binary in
`bin/libcks.a`.

```shell
git clone https://github.com/conradkleinespel/libcks.git
cd libcks
# without debug flags
make all
# or with debug flags
make all_debug
```

Then, to use it with a C file of yours, you could do something like:
```shell
gcc main.c -Ilibcks -Llibcks/bin -lcks
```

## Tests

You can run the unit tests like so - this:
```shell
git clone https://github.com/conradkleinespel/libcks.git
cd libcks
# without debug flags
make test
# or with debug flags
make test_debug
./bin/test
```
