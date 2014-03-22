# 42SH

42SH is a shell.

Features:
* commands: `ls -e -a`
* pipes: `ls | cat | wc -c`
* logic operators: `&&`, `||`
* semicolons: `ls; ps -e`
* single and double quotes: `echo 'that file'"is cool"`
* backslashes: `ls file\ with\ space`

Upcoming features:
* command history
* builtins: `cd`, `exit`, `setenv`, `unsetenv`, `env`

Here's how to get it to run:
```sh
git clone --recursive git@github.com:Atelier-Morales/42SH.git
cd 42SH/launcher
make re
./42sh
# now the shell is running, have fun with it !
```
