# Sorting Project - Group 4
## I. Setup
### 1. Build
#### 1.1 - CMake
You could open this project in any IDE that support CMake like CLion (Prefered) or Visual Studio. 

Otherwise, run this following command:
```asm
cmake -build .
```
#### 1.2 - GCC
```asm
gcc -std=c++17 -O2 -o sgp.exe src/main.cpp
```
or simply just run the `build.cmd`
### 2. Run
Most of the time, the output executable is at the project source code. You can run it as a command in terminal.<br>
Rarely, sometime the executable file won't be at the root of the project source code.
## II. Command Line Interface
### 1. Sort
### 2. Compare
### 3. Help
## III. Contribution Requirements
### 1. Project structure
> [!IMPORTANT]<br>
> For the project to be unified, all of the following rules are required.
```asm
project/
├── src/
│   ├── main.cpp  ; Main file
│   ├── sort/  ; Sort algo go in here
│   │   └── merge_sort.cpp  ; merge sort algo file
│   └── utils/
│       ├── result.h  ; result return from algo
│       └── ...
└── ...
```
#### 1.1 Sort algorithms
All sorting algorithms must be in a separated file in sort folder, they must be following this prototype
```c++
/// Working in Process
```
#### 
### 2. Commit and git
#### 1.1 ADD
If you add new files, add them separately as a commit.
```
ADD: Description 
eg: ADD: main.h, main.p
    ADD: new merge-sort algo
```

### 3. Pull request
All major changes should be reviewed and approved by [pull request](https://github.com/fit-k23/sorting_group_project/pulls), DO NOT directly changing the `main` branch.<br>
This include:
- Changes to the `main.cpp`, `result.h`, etc. WIP
- Changes to old algo or new sorting algo implemented.
