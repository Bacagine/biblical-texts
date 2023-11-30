# biblical-texts

biblical-texts print a biblical message in the terminal.

To better understand my codes, read the README.md at [this link](https://github.com/Bacagine/Bacagine)

OBS: This software is still in the development phase and is not ready for use.

# How to use?

## Dependecies

You need two libraries to compile and use biblical-texts:

1) libtrace [https://github.com/Bacagine/trace/](https://github.com/Bacagine/trace/)
2) libcutils [https://github.com/Bacagine/cutils/](https://github.com/Bacagine/cutils/)

Compile the libraries above and follow the steps bellow:

1) Put the .so file in the lib file of this repository
2) Copy the include/trace directory to the include directory of this repository
3) Copy the include/cutils directory to the include directory of this repository

## Compilation

```bash
$ ./mk
```

## Instalation
```
# ./mkinstall
```

## Configuring biblical-texts

In your bashrc type the following line in the end of file:

```bash
clear && biblical-texts
```

## Uninstalling
```bash
$ ./mkuninstall
```

After run the script above, remove the line "clear && biblical" texts of your bashrc.

