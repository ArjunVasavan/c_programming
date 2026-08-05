# `flock` in C

`flock` is a system call for advisory file locking in Unix/Linux. It allows multiple processes to coordinate access to shared files.

## Header & Signature

```c
#include <sys/file.h>

int flock(int fd, int operation);
```

## Operations

| Flag | Meaning |
|------|---------|
| `LOCK_SH` | Shared lock (multiple readers allowed) |
| `LOCK_EX` | Exclusive lock (only one writer) |
| `LOCK_UN` | Unlock |
| `LOCK_NB` | Non-blocking (combine with `|`) |

---

## Basic Usage

### Exclusive Lock (Writer)
```c
#include <stdio.h>
#include <sys/file.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("data.txt", O_WRONLY | O_CREAT, 0644);
    if (fd == -1) { perror("open"); return 1; }

    // Acquire exclusive lock — blocks if another process holds it
    if (flock(fd, LOCK_EX) == -1) {
        perror("flock");
        close(fd);
        return 1;
    }

    // --- Critical section ---
    write(fd, "hello\n", 6);
    // ------------------------

    flock(fd, LOCK_UN);  // Release lock
    close(fd);           // Also releases lock implicitly
    return 0;
}
```

### Shared Lock (Reader)
```c
flock(fd, LOCK_SH);   // Multiple readers can hold this simultaneously
// ... read from file ...
flock(fd, LOCK_UN);
```

### Non-blocking Lock
```c
if (flock(fd, LOCK_EX | LOCK_NB) == -1) {
    if (errno == EWOULDBLOCK) {
        printf("File is already locked, try later\n");
    } else {
        perror("flock");
    }
}
```

---

## Lock Compatibility Matrix

| | Shared held | Exclusive held |
|---|---|---|
| **Request Shared** | ✅ Granted | ⏳ Blocks |
| **Request Exclusive** | ⏳ Blocks | ⏳ Blocks |

---

## Key Behaviors to Know

**1. Locks are per open-file-description, not per fd**
```c
int fd1 = open("file", O_RDWR);
int fd2 = dup(fd1);          // fd1 and fd2 share the same lock!
flock(fd1, LOCK_EX);
flock(fd2, LOCK_UN);         // This ALSO unlocks fd1's lock
```

**2. `close()` releases the lock**
```c
flock(fd, LOCK_EX);
close(fd);  // Lock is gone — be careful in libraries/wrappers
```

**3. Locks don't stack** — calling `flock` twice doesn't require two unlocks:
```c
flock(fd, LOCK_EX);
flock(fd, LOCK_EX);  // No-op, already locked
flock(fd, LOCK_UN);  // Fully unlocked now
```

**4. `flock` is advisory** — processes that don't call `flock` can still read/write freely. All cooperating processes must use `flock` for it to be meaningful.

---

## `flock` vs `fcntl` locks

| | `flock` | `fcntl` (POSIX locks) |
|---|---|---|
| Granularity | Whole file | Byte ranges |
| NFS support | Often no | Yes |
| Fork behavior | Child inherits lock | Child gets independent lock |
| Simplicity | ✅ Simple | More complex |

---

## Common Pattern: Lock File (PID file)

A classic use case — ensuring only one instance of a program runs:

```c
#include <stdio.h>
#include <sys/file.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int acquire_singleton_lock(const char *lockfile) {
    int fd = open(lockfile, O_CREAT | O_RDWR, 0644);
    if (fd == -1) return -1;

    if (flock(fd, LOCK_EX | LOCK_NB) == -1) {
        if (errno == EWOULDBLOCK) {
            fprintf(stderr, "Another instance is already running.\n");
        }
        close(fd);
        return -1;
    }

    // Write our PID into the lock file
    char pid_str[32];
    snprintf(pid_str, sizeof(pid_str), "%d\n", getpid());
    write(fd, pid_str, strlen(pid_str));

    return fd;  // Keep fd open to hold the lock
}
```
