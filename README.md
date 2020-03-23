# FlightSim

FlightSim is a light flight simulator using quaternions and conformal geometric algebra. It is designed to avoid gimbal lock that may be encountered with other types of implementation.

## Prerequisites

- `CMake 2.8` for compilation, you can download and install it [here](https://cmake.org/download/)
- `Garamon` for geometric algebra, this one is a bit more tricky : clone it from [this repo](https://github.com/vincentnozick/garamon). Install it and use it with `c3ga.conf` configuration.
- `OpenGL` for rendering, you can grab it [here](https://www.opengl.org/). 

*Note : You may need a Nvidia GPU to use `OpenGL`.*

## Installation and execution instruction

Run the following commands :
```shell script
git clone https://github.com/Odomar/FlightSim
mkdir build
cd build
cmake ../FlightSim
make -j
```

Then execute the project in the build directory with `./Main/FlightSim`.

## Commands

The only commands are the rotations : 

- `Z`/`S` to rotate up / down (`pitch`),
- `Q`/`D` to rotate left / right (`yaw`), and
- `A`/`E` to roll left / right (`roll`).