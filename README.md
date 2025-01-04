# C-practice
## Learning C Practice   

This repository contains my practice exercises for learning the C programming language. The goal is to improve my understanding and proficiency in C by working on various coding challenges and projects.

## Categories
### Producer-Consumer Problem using Semaphores
練習使用 Semaphore 解決 Producer-Consumer 問題，並複習 Static Variable、Struct 與 Pointer 的使用。
- Semaphore 的計數機制可以控制多執行緒或多程序操作有限資源。當資源數量變動時，Semaphore 對計數進行加減來同步執行緒。

### Producer-Consumer Problem using Condition Variables
練習使用 Condition Variables 解決 Producer-Consumer 問題。
- `pthread_cond_signal()` 喚醒等待中的執行緒，但該執行緒不一定會立刻獲取鎖，而是與其他執行緒公平競爭。
- 上述帶來的結果可能是同時有多個執行緒卡在 wait，需使用 `pthread_cond_broadcast()` 喚醒所有等待中的執行緒，避免程式無法結束的情況。
- Mutex 搭配 Condition Variable 再結合一個 Counter 可以模擬出類似 Semaphore 的效果。

### Dining Philosophers Problem (Pseudocode)
學習並理解 Synchronization 經典問題中的 Dining Philosophers Problem 限制同時拿筷子的人數的解法。

### First Reader-Writer Problem (Pseudocode)
學習並理解 Synchronization 經典問題中的 Reader-Writer Problem（Reader Priority）解法。

### Fibonacci Search
實作費氏搜尋演算法，利用 Fibonacci 數列縮小搜尋範圍。
費氏搜尋演算法理論上適用於優化資料存取次數，因為資料普遍具有 Locality of Reference 特性。

### Atomic Operations
練習使用 Atomic Operations：`__sync_fetch_and_add()`、`__sync_fetch_and_sub()` 實現同步機制，避免 Race Condition。

### Semaphore
練習使用 Semaphore 來保護共享資源，避免 Race Condition。
- Semaphore 是計數機制，用來控制多執值緒或多程序操作有限數量的資源。
- Binary Semaphore 可模擬 Mutex & Condition Variables，但最大的不同是觸發條件可以由其他執行緒控制。

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
- Static Variable 會被分配在 C 語言記憶體區域中的 BSS 區域（未初始化）或 Data 區域（已初始化），而不是函數的 Stack 區域，因此即使函數結束後變數仍然存活。
- Static Function 僅限於當前檔案使用，無法被其他檔案存取，可用於避免命名衝突。

### Intersection of Two Arrays
使用 realloc 動態調整記憶體大小，實作兩個陣列的交集運算。

### Argc and Argv
練習 `main()` 函數參數 `argc` 和 `argv` 的使用方式，了解如何處理命令列參數。

### Function Pointer
練習 Function Pointer 的用法，理解函數指標在 C 語言中的應用。

### GCD
練習 GCD 演算法，包含 while loop 與 recursive 兩種方式。

### Type Size
查看 64-bit 系統中不同型別的記憶體占用大小。

### Call by Address
熟悉 C 語言中的 Call by Address。

對比 JavaScript 的不可變性設計哲學：
- JavaScript 偏向於透過副本操作來提升程式的可讀性與安全性。
- C 語言 偏向於直接改變參數值，以達到更高的效能與資源效率。

### Little Endian & Big Endian
學習如何判斷系統是 Little-Endian 還是 Big-Endian，並理解其概念。

### Calculate Binary
練習將十進制數字轉換為二進制表示。

### Marco
理解 `#define` 的用法，以及 Inline Function 的應用場景。

### ENUM
熟悉 ENUM 的使用方式，並學習結合 bit operation 進行應用。

### Binary Search Tree
實現 BST，包括 Insert, Delete, Search, Traversal 等操作。
- 部分方法撰寫 Loop 與 Recursive 兩個版本，熟悉不同實作技巧。
- 練習使用動態記憶體管理（`malloc()`/`free()`）處理樹節點。
- 撰寫測試，驗證程式正確性與穩定性。

### Count Node Children
利用堆疊資料結構（Stack）計算以字串形式表示的二元樹（e.g. `"C(G, H(L, M(N)), I), D(J)))", 'C'`）的子節點數量，並練習 `assert()` 的使用。