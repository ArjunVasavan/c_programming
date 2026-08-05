Great question! `fcntl` locks work similarly to `flock` but with more control. Let me build on the same fork example so you can compare directly.

---

## The Key Difference

| | `flock` | `fcntl` |
|---|---|---|
| Locks | Whole file | **Specific byte ranges** |
| Syntax | Simple | More setup needed |
| NFS | Often broken | Works |

With `fcntl` you fill a `struct flock` to describe **what** to lock, then call `fcntl()`.

---

## The `struct flock`

```c
struct flock {
    short l_type;    // F_RDLCK, F_WRLCK, or F_UNLCK
    short l_whence;  // SEEK_SET, SEEK_CUR, or SEEK_END
    off_t l_start;   // where the lock starts
    off_t l_len;     // how many bytes (0 = till end of file)
    pid_t l_pid;     // filled by OS when checking
};
```

Think of it like highlighting a section of the file to lock, instead of locking the whole thing.

---

## Same Fork Example, Using `fcntl`

```c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void lock_file(int fd) {
    struct flock fl;
    fl.l_type   = F_WRLCK;   // write lock
    fl.l_whence = SEEK_SET;   // from start of file
    fl.l_start  = 0;          // starting at byte 0
    fl.l_len    = 0;          // 0 means "entire file"

    // F_SETLKW = set lock, and WAIT if blocked
    if (fcntl(fd, F_SETLKW, &fl) == -1) {
        perror("fcntl lock");
        exit(1);
    }
}

void unlock_file(int fd) {
    struct flock fl;
    fl.l_type   = F_UNLCK;   // unlock
    fl.l_whence = SEEK_SET;
    fl.l_start  = 0;
    fl.l_len    = 0;

    if (fcntl(fd, F_SETLK, &fl) == -1) {
        perror("fcntl unlock");
        exit(1);
    }
}

int main() {
    int fd = open("shared.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    pid_t pid = fork();

    if (pid == 0) {
        // ---- CHILD PROCESS ----
        printf("Child: waiting for lock...\n");
        lock_file(fd);                      // blocks until parent unlocks

        printf("Child: got the lock! Writing...\n");
        for (int i = 0; i < 5; i++) {
            write(fd, "child line\n", 11);
            sleep(1);
        }

        printf("Child: done, releasing lock.\n");
        unlock_file(fd);

    } else {
        // ---- PARENT PROCESS ----
        printf("Parent: grabbing lock first!\n");
        lock_file(fd);

        printf("Parent: got the lock! Writing...\n");
        for (int i = 0; i < 5; i++) {
            write(fd, "parent line\n", 12);
            sleep(1);
        }

        printf("Parent: done, releasing lock.\n");
        unlock_file(fd);

        wait(NULL);
    }

    close(fd);
    return 0;
}
```

The output and `shared.txt` result is **identical** to the `flock` example — parent writes first, then child.

---

## The Cool Extra: Locking a Byte Range

This is where `fcntl` goes beyond `flock`. You can lock **just part of a file**:

```c
// Lock only bytes 0–99 (first 100 bytes)
struct flock fl;
fl.l_type   = F_WRLCK;
fl.l_whence = SEEK_SET;
fl.l_start  = 0;
fl.l_len    = 100;        // only 100 bytes!
fcntl(fd, F_SETLKW, &fl);

// Lock only bytes 100–199 at the same time in another process
fl.l_start  = 100;
fl.l_len    = 100;
fcntl(fd, F_SETLKW, &fl);  // this does NOT block! Different range.
```

Two processes can write to **different parts of the file simultaneously** without blocking each other.

---

## `F_SETLK` vs `F_SETLKW`

| Command | Behaviour |
|---|---|
| `F_SETLKW` | **W**ait if blocked (like `flock` default) |
| `F_SETLK` | Return immediately with error if blocked (like `LOCK_NB`) |

---

## Quick Mental Map

```
flock(fd, LOCK_EX)     ≈    fcntl(fd, F_SETLKW, &fl)  where l_type = F_WRLCK
flock(fd, LOCK_SH)     ≈    fcntl(fd, F_SETLKW, &fl)  where l_type = F_RDLCK
flock(fd, LOCK_UN)     ≈    fcntl(fd, F_SETLK,  &fl)  where l_type = F_UNLCK
flock(fd, LOCK_EX|LOCK_NB) ≈ fcntl(fd, F_SETLK, &fl)  where l_type = F_WRLCK
```

---

The main takeaway: `fcntl` is just `flock` with more knobs. If you just need to protect a whole file, `flock` is simpler. If you need fine-grained control or NFS support, reach for `fcntl`.

Want me to show the byte-range locking in a full working example?
