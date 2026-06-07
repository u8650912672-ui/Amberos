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
    if (mount("/dev/sda", "/mnt", "ext4", 0, NULL) < 0) die("mount /dev/sda");

    mount("/proc", "/mnt/proc", NULL, MS_BIND, NULL);
    mount("/sys",  "/mnt/sys",  NULL, MS_BIND, NULL);
    mount("/dev",  "/mnt/dev",  NULL, MS_BIND, NULL);

    chdir("/mnt");
    execl("/sbin/switch_root", "switch_root", "/mnt", "/bin/busybox", "init", NULL);
    die("exec switch_root");
    return 1;
}
