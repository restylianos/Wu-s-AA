# Implementation of Wu's antialiasing algorithm
Minimal implementation of Wu's antialiasing algorithm with a linear line as an example. OpenGL
library is utilised as the graphics framework.

## Install OpenGl
**Linux** -- Debian-like
```
$ sudo apt-get update
$ sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev
```
**Other**
```
Don't use other OS's :)
```


## Compile and Run
**Compile**
``
gcc ./main.c -lglut -lGLU -lGL -o <name_that_you_prefer>
``
**Run**
``
./<name_that_you_prefer>
``

### Resources  
* [`GeeksForGeeks`](https://www.geeksforgeeks.org/anti-aliased-line-xiaolin-wus-algorithm/)
* [`UnionAssets`](https://unionassets.com/blog/algorithm-brezenhema-and-wu-s-line-299)

