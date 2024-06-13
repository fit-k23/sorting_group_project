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
#### 1.1 Sorts folders
All sorting algorithms must be in a separated file in sort folder, they must be following this prototype
```c++
/// Working in Process
```
#### 1.2 Utils folder
All utility-functions should be put in the utils folder, this should only have function that frequently used
#### 
### 2. Commit and git
#### 1.1 ADD
If you add new files, commit it with the following struct.
```
ADD: Description 
eg: ADD: main.h, main.p
    ADD: new merge-sort algo
```
#### 1.2 CHANGE
If you change a file, commit it with the following struct.
```
CHANGE: Description
eg: CHANGE: update main() function in main.php
    CHANGE: remove function test1()
```
#### 1.3 TYPO
If there was any grammar issues, commit it with the fixed line with the following struct.
```
TYPO: Description
eg: fix typo `helIo` -> `hello`
```
#### 1.4 GIT
To commit a change, you do these following commands
```asm
git add FILE_NAME ; add changes
git add *         ; add all changes
git commit -m COMMIT_MESSAGE ; commit messages are those above instructions
eg: git commit -m "ADD: main.cpp"
git push REMOTE BRANCH_NAME ; push the commits to branch on local/remote/origin
eg: git push origin test1
    git push 
```

### 3. Pull request
All major changes should be reviewed and approved by [pull request](https://github.com/fit-k23/sorting_group_project/pulls), DO NOT directly changing the `main` branch.<br>
This include:
- Changes to the `main.cpp`, `result.h`, etc. WIP
- Changes to old algo or new sorting algo implemented.
#### 3.1 How to create a branch?
- Step 1: Create a fork on your own github or your orgs; or clone the repo into local
- Step 2: If you create a fork on your own github, clone them down into your local. If not, skip this step
- Step 3: Create a new branch. Execute this following command:
```asm
git checkout -b NEW_BRANCH_NAME
eg: git checkout -b test1  ; to switch between branch do:
git checkout BRANCH_NAME   ; without the tag -b (tag -b create a new branch if not existed!)
```