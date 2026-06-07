#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <sys/types.h>

void die(const char *msg) {
    perror(msg);
    while(1) sleep(1);
}

int main(void) {
    if (mount("proc", "/proc", "proc", 0, NULL) < 0) die("mount /proc");
    if (mount("sysfs", "/sys", "sysfs", 0, NULL) < 0) die("mount /sys");
    if (mount("devtmpfs", "/dev", "devtmpfs", 0, NULL) < 0) die("mount /dev");

    execl("/bin/busybox", "init", NULL);
    die("exec busybox init");
    return 1;
}
