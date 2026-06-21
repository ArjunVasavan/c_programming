# POSIX Quick Reference — Interview Cheat Sheet

---

## The Golden Rule

```
pthread_ + [object] + [action]
```

> Learn the OBJECTS and ACTIONS — you can guess any function name.

---

## 1. Thread Functions

```
pthread_ + (nothing) + create     → pthread_create()
pthread_ + (nothing) + join       → pthread_join()
pthread_ + (nothing) + exit       → pthread_exit()
pthread_ + (nothing) + self       → pthread_self()
pthread_ + (nothing) + cancel     → pthread_cancel()
pthread_ + (nothing) + detach     → pthread_detach()
pthread_ + (nothing) + equal      → pthread_equal()
```

---

## 2. Mutex Functions

```
pthread_ + mutex + init           → pthread_mutex_init()
pthread_ + mutex + destroy        → pthread_mutex_destroy()
pthread_ + mutex + lock           → pthread_mutex_lock()
pthread_ + mutex + unlock         → pthread_mutex_unlock()
pthread_ + mutex + trylock        → pthread_mutex_trylock()
```

---

## 3. Condition Variable Functions

```
pthread_ + cond + init            → pthread_cond_init()
pthread_ + cond + destroy         → pthread_cond_destroy()
pthread_ + cond + wait            → pthread_cond_wait()
pthread_ + cond + signal          → pthread_cond_signal()
pthread_ + cond + broadcast       → pthread_cond_broadcast()
```

---

## 4. Read-Write Lock Functions

```
pthread_ + rwlock + init          → pthread_rwlock_init()
pthread_ + rwlock + destroy       → pthread_rwlock_destroy()
pthread_ + rwlock + rdlock        → pthread_rwlock_rdlock()
pthread_ + rwlock + wrlock        → pthread_rwlock_wrlock()
pthread_ + rwlock + unlock        → pthread_rwlock_unlock()
```

---

## 5. Semaphore Functions (POSIX)

```
sem_ + init                       → sem_init()
sem_ + destroy                    → sem_destroy()
sem_ + wait                       → sem_wait()       ← decrement (P operation)
sem_ + post                       → sem_post()       ← increment (V operation)
sem_ + trywait                    → sem_trywait()    ← non blocking wait
sem_ + timedwait                  → sem_timedwait()  ← wait with timeout
sem_ + getvalue                   → sem_getvalue()   ← read current value

Named semaphores (across processes):
sem_ + open                       → sem_open()
sem_ + close                      → sem_close()
sem_ + unlink                     → sem_unlink()
```

> Header: `#include <semaphore.h>` | Compile: `gcc file.c -lpthread`

---

## 6. Attributes Functions

```
pthread_ + attr     + init        → pthread_attr_init()
pthread_ + attr     + destroy     → pthread_attr_destroy()
pthread_ + attr     + set___      → pthread_attr_setstacksize()
pthread_ + attr     + get___      → pthread_attr_getstacksize()

pthread_ + mutexattr + init       → pthread_mutexattr_init()
pthread_ + mutexattr + destroy    → pthread_mutexattr_destroy()
pthread_ + mutexattr + settype    → pthread_mutexattr_settype()
```

---

## 7. File Operations

```
open()      → open a file
close()     → close a file
read()      → read from fd
write()     → write to fd
lseek()     → seek position in file
stat()      → get file info (by path)
fstat()     → get file info (by fd)     ← f prefix = fd version
unlink()    → delete a file
rename()    → rename a file
chmod()     → change permissions
truncate()  → truncate file size
```

> Rule: `f` prefix = fd version of same function

---

## 8. Process Operations

```
fork()      → create child process
wait()      → wait for any child
waitpid()   → wait for specific child
exit()      → exit process
getpid()    → get my process ID
getppid()   → get parent process ID    ← pp = parent process
kill()      → send signal to process
```

### exec Family — Must Know

```
execl()     → list of args
execv()     → array (vector) of args
execlp()    → list + PATH search
execvp()    → array + PATH search      ← most commonly used
execle()    → list + environment
execve()    → array + environment      ← most low level

l = list arguments directly
v = vector/array of arguments
p = search PATH automatically
e = custom environment
```

---

## 9. IPC — System V

```
shm + get   → shmget()    create/get shared memory
shm + at    → shmat()     attach to process
shm + dt    → shmdt()     detach from process
shm + ctl   → shmctl()    control/delete

sem + get   → semget()    create/get semaphore
sem + op    → semop()     semaphore operation
sem + ctl   → semctl()    control/delete

msg + get   → msgget()    create/get message queue
msg + snd   → msgsnd()    send message
msg + rcv   → msgrcv()    receive message
msg + ctl   → msgctl()    control/delete
```

> Rule: `get`=create/access | `ctl`=control/delete | `at`=attach | `dt`=detach

---

## 10. Directory Operations

```
mkdir()     → make directory
rmdir()     → remove directory
opendir()   → open directory           ← same verb as open, dir suffix
readdir()   → read directory entries   ← same verb as read, dir suffix
closedir()  → close directory          ← same verb as close, dir suffix
getcwd()    → get current directory
chdir()     → change directory
```

---

## 11. Signal Operations

```
signal()        → set handler (old way)
sigaction()     → set handler (modern)
kill()          → send signal to process
raise()         → send signal to yourself
pause()         → wait for any signal
alarm()         → schedule SIGALRM
sigprocmask()   → block/unblock signals
```

---

## 12. Memory Operations

```
mmap()      → map file/memory into address space
munmap()    → unmap memory
mprotect()  → change memory protection
mlock()     → lock memory (prevent swap)
munlock()   → unlock memory
brk()       → set heap boundary
sbrk()      → grow heap
```

> Rule: `m` prefix = memory operation

---

## 13. Socket Functions

```
socket()    → create socket
bind()      → attach IP + port
listen()    → start listening
accept()    → accept connection
connect()   → connect to server
send()      → send data
recv()      → receive data
sendto()    → send to (UDP)
recvfrom()  → receive from (UDP)
close()     → close socket
shutdown()  → half close socket
```

---

## Master Prefix/Suffix Table

| Prefix/Suffix | Meaning            | Example              |
|---------------|--------------------|----------------------|
| `f___`        | fd version         | fstat, fchmod        |
| `___dir`      | directory version  | opendir, readdir     |
| `get___`      | read a value       | getpid, getuid       |
| `set___`      | write a value      | setuid, setgid       |
| `pp___`       | parent process     | getppid              |
| `e___`        | effective          | geteuid, getegid     |
| `shm___`      | shared memory      | shmget, shmat        |
| `sem___`      | semaphore (Sys V)  | semget, semop        |
| `sem_`        | semaphore (POSIX)  | sem_wait, sem_post   |
| `msg___`      | message queue      | msgget, msgsnd       |
| `m___`        | memory             | mmap, mlock          |
| `___ctl`      | control/config     | shmctl, semctl       |
| `___at`       | attach             | shmat                |
| `___dt`       | detach             | shmdt                |

---

## Master Action Words

| Action    | Meaning              |
|-----------|----------------------|
| `init`    | initialize/create    |
| `destroy` | cleanup/free         |
| `lock`    | acquire lock         |
| `unlock`  | release lock         |
| `trylock` | non-blocking lock    |
| `wait`    | block until ready    |
| `signal`  | wake one waiter      |
| `broadcast`| wake all waiters    |
| `post`    | increment semaphore  |
| `get`     | create or read       |
| `set`     | write/configure      |
| `ctl`     | control/delete       |
| `at`      | attach               |
| `dt`      | detach               |

---

## Objects to Remember

```
pthread world:
thread → mutex → cond → rwlock → attr → mutexattr

IPC world:
shm → sem → msg

POSIX semaphore:
sem_

Memory:
mmap → mlock → mprotect
```

---

## Semaphore vs Mutex — Quick Difference

```
Mutex                           Semaphore
─────                           ─────────
binary (0 or 1)                 any value (0, 1, 2, 3...)
only owner can unlock           anyone can post
thread synchronization          resource counting
pthread_mutex_lock/unlock       sem_wait / sem_post
```

---

## One Line to Remember Everything

> **"POSIX = prefix tells you the object (shm, sem, msg, m, pthread) + action tells you what (init/destroy, lock/unlock, wait/signal/post, get/set/ctl) — f prefix means fd version, dir suffix means directory version."**

---
