# Sorting Project - Nhóm 4
## I. Setup
### 1. Build
#### 1.1 - CMake
#### 1.2 - GCC
### 2. Run
## II. Command Line Interface
## III. Yêu cầu đóng góp
### 1. Cấu trúc dự án
> [!Quan trọng]<br>
> For the project to be unified, all of the following rules are required.
```asm
project/
├── src/
│   ├── main.cpp  ; Tệp main
│   ├── sort/  ; Thuật toán lưu vào đây
│   │   └── merge_sort.cpp  ; file chứa thuật toán
│   └── utils/
│       ├── result.h  ; kết quả từ thuật toán
│       └── ...
└── ...
```
### 2. Commit and git
#### 1.1 ADD
Nếu bạn thêm nhiều file, hãy commit nó riêng
```
ADD: nội dung thay đổi 
eg: ADD: main.h, main.p
    ADD: thêm thuật toán merge-sort
```

### 3. Pull request
Mọi thay đổi lớn phải được xem xét và chấp thuận qua [`pull request`](https://github.com/fit-k23/sorting_group_project/pulls). Không được thay đổi trực tiếp trên nhánh `main`.<br>
Bao gồm:
- Những thay đổi lên các tệp `main.cpp`, `result.h`, etc. Bổ sung sau
- Những thay đổi lên các thuật toán hoặc thêm thuật toán mới
