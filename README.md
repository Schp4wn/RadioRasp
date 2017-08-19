# RadioRasp

A little tool written in C++ to send a radio code to chacon module with Raspberry Pi.

## Requirement

First, you need a amazing Rasperry Pi 1, 2 or 3. You also need a radio emitter for ability to send radio code in the air.

## Usage

You can clone the repo with git.

```
git clone https://github.com/MatthieuMota/RadioRasp.git
```

Compile the tool

```
aclocal
autoconf
automake --add-missing
./configure
make
```

Install the tool

```
make install
```

For the moment, decimal signal is simply converted to binary signal encoded in 32bits with state on/off and module.
First argument is GPIO PIN on your Raspberry, you can follow [this](http://wiringpi.com/pins/)
Second argument is the code you want to send.
Third argument is the code to identify the module.
Last argument is the state you want to send, on (1) or off (0).

```
radiorasp 0 123456 0 1
```

## TODO

Just begin this repository. You can contribute.
