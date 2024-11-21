#include <stdio.h>
#include <assert.h>

typedef enum Mode Mode;

// enum 內部是以 int 儲存
enum Mode {
    MODE_READ = 1 << 0, // 1
    MODE_WRITE = 1 << 1, // 2
    MODE_EXEC = 1 << 2, // 4
};

int main(void) {
    // enum 裡的數值可直接在全域讀取
    printf("Write mode is: %d\n", MODE_WRITE);

    // enum type 變數宣告
    Mode read_mode = MODE_READ;
    printf("Read mode is: %d\n", read_mode);

    Mode admin_mode = MODE_READ;
    admin_mode |= MODE_WRITE;
    printf("Admin permission is: %d\n", admin_mode);

    admin_mode &= ~(MODE_WRITE);
    printf("Admin permission is: %d\n", admin_mode);

    admin_mode ^= MODE_EXEC;
    printf("Admin permission is: %d\n", admin_mode);

    int admin_write_permission = (admin_mode >> 1) & 1;
    printf("Admin write permission is: %d\n", admin_write_permission);

    return 0;
}