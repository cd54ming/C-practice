# C-practice
## Learning C Practice

This repository contains my practice exercises for learning the C programming language. The goal is to improve my understanding and proficiency in C by working on various coding challenges and projects.

## Categories

### Atomic Operations
練習使用 Atomic Operations：`__sync_fetch_and_add()`、`__sync_fetch_and_sub()` 實現同步機制，避免 Race Condition。

### Semaphore
練習使用 Semaphore 來保護共享資源，避免 Race Condition。

### Mutex
練習使用 Mutex 來保護共享資源，避免 Race Condition。

### Multithreading
練習建立執行緒。

### Create a Process
練習建立子程序。

### String Copy
練習操作陣列與指標類型的字串。

### Static Variable and Function
理解 Static Variable 與 Static Function 的概念：
Static Variable 會被分配在 C 語言記憶體空間中的 BSS 或 Data 區域，而不是函數的 Stack 區域，所以函數結束時還會存活。
Static Function 無法被其他檔案存取，其他檔案中可以宣告同樣名稱的函數，可以用來防止命名衝突。

### Intersection of Two Arrays
練習使用 `realloc` 函數來動態配置記憶體大小。

### Argc and Argv
練習 `main()` 函數參數 `argc` 和 `argv` 的使用方式。

### Function Pointer
練習 Function Pointer 的用法，理解函數指標在 C 語言中的應用。

### GCD
練習 GCD 演算法，撰寫 while loop 與 recursive 兩種方式。

### Type Size
查看 64-bit 系統中各個型別大小，了解不同型別的記憶體佔用。

### Call by Reference
習慣 C 語言中的引用調用方式，與 JavaScript 設計哲學不同，JavaScript 偏向不可變性，透過副本操作提升程式的可讀性和安全性。
C 語言為了追求高效和低資源使用，常常直接使用參數值。

### Little Endian & Big Endian
幫助理解 Little Endian 與 Big Endian 的概念，及如何判斷系統是哪一種。

### Calculate Binary
練習十進制轉二進制。

### Marco
增加 `#define` 與 inline function 的理解。

### ENUM
熟悉 ENUM 與 bit operation 使用。

#### Binary Search Tree
實現 BST，包括 Insert, Delete, Search, Traversal 等操作。

#### Count Node Children
實作 Stack 資料結構，計算 Binary Tree 表示法（e.g. `"C(G, H(L, M(N)), I), D(J)))", 'C'`）中子節點數量，並練習 `assert()` 的使用。
