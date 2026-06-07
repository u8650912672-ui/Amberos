#include <unistd.h>
#include <sys/mount.h>
int main(void) {
    mount("proc", "/proc", "proc", 0, NULL);
    mount("sysfs", "/sys", "sysfs", 0, NULL);
    mount("devtmpfs", "/dev", "devtmpfs", 0, NULL);
    char *argv[] = { "/bin/sh", NULL };
    char *envp[] = { "PATH=/bin:/sbin", NULL };
    execve("/bin/sh", argv, envp);   
    while(1);
    return 0;
}
