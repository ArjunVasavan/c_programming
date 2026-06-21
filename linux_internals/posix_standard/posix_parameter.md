# POSIX Functions — Parameters Cheat Sheet
# Interview Ready Reference

---

## HOW TO READ THIS FILE

```
function(param1, param2, param3)
           |       |       |
           |       |       what it is
           |       what it is
           what it is

Returns: what it returns
```

---

## ═══════════════════════════════════
## SECTION 1 — THREAD FUNCTIONS
## ═══════════════════════════════════

### pthread_create()
```
pthread_create(&tid,      attr,        function,      arg)
                |           |              |            |
                |           |              |            └── void* argument to pass to function
                |           |              └── function thread will run → void* func(void*)
                |           └── NULL = default attributes
                └── pthread_t* → stores thread ID here

Returns: 0 = success | error code = failure (NOT -1, does NOT use errno)
Header : #include <pthread.h>
Compile: gcc file.c -lpthread
```

---

### pthread_join()
```
pthread_join(tid,        &retval)
              |              |
              |              └── void** → stores thread return value (NULL = dont care)
              └── pthread_t → thread ID to wait for

Returns: 0 = success | error code = failure
Blocks : YES — waits until thread finishes
```

---

### pthread_exit()
```
pthread_exit(retval)
               |
               └── void* → value to return to pthread_join() caller

Returns: never returns — exits the thread
Note   : use this inside thread function to exit early
```

---

### pthread_self()
```
pthread_self()   ← no parameters

Returns: pthread_t → ID of calling thread
Like   : getpid() but for threads
```

---

### pthread_detach()
```
pthread_detach(tid)
                |
                └── pthread_t → thread to detach

Returns: 0 = success | error code = failure
Effect : thread cleans itself up when done, cannot be joined after this
```

---

### pthread_cancel()
```
pthread_cancel(tid)
                |
                └── pthread_t → thread to cancel

Returns: 0 = success | error code = failure
Note   : thread may not stop immediately — only at cancellation points
```

---

### pthread_equal()
```
pthread_equal(tid1,    tid2)
               |         |
               |         └── pthread_t → second thread ID
               └── pthread_t → first thread ID

Returns: non-zero = same thread | 0 = different threads
Note   : dont use == to compare thread IDs, use this function
```

---

## ═══════════════════════════════════
## SECTION 2 — MUTEX FUNCTIONS
## ═══════════════════════════════════

### pthread_mutex_init()
```
pthread_mutex_init(&mutex,       attr)
                    |              |
                    |              └── NULL = default | pthread_mutexattr_t* for custom
                    └── pthread_mutex_t* → mutex to initialize

Returns: 0 = success | error code = failure
Shortcut: pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER; ← no init needed
```

---

### pthread_mutex_destroy()
```
pthread_mutex_destroy(&mutex)
                       |
                       └── pthread_mutex_t* → mutex to destroy

Returns: 0 = success | error code = failure
Note   : must be unlocked before destroying
```

---

### pthread_mutex_lock()
```
pthread_mutex_lock(&mutex)
                    |
                    └── pthread_mutex_t* → mutex to lock

Returns: 0 = success | error code = failure
Blocks : YES — waits until mutex is available
```

---

### pthread_mutex_unlock()
```
pthread_mutex_unlock(&mutex)
                      |
                      └── pthread_mutex_t* → mutex to unlock

Returns: 0 = success | error code = failure
Blocks : NO — returns immediately
```

---

### pthread_mutex_trylock()
```
pthread_mutex_trylock(&mutex)
                       |
                       └── pthread_mutex_t* → mutex to try locking

Returns: 0 = locked successfully | EBUSY = already locked
Blocks : NO — returns immediately either way
```

---

## ═══════════════════════════════════
## SECTION 3 — CONDITION VARIABLES
## ═══════════════════════════════════

### pthread_cond_init()
```
pthread_cond_init(&cond,        attr)
                   |              |
                   |              └── NULL = default | pthread_condattr_t* for custom
                   └── pthread_cond_t* → condition variable to initialize

Returns  : 0 = success | error code = failure
Shortcut : pthread_cond_t c = PTHREAD_COND_INITIALIZER;
```

---

### pthread_cond_wait()
```
pthread_cond_wait(&cond,       &mutex)
                   |              |
                   |              └── pthread_mutex_t* → associated mutex (must be locked)
                   └── pthread_cond_t* → condition to wait on

Returns: 0 = success | error code = failure
Blocks : YES
Does   : 1. unlocks mutex  2. sleeps  3. wakes up  4. relocks mutex
IMPORTANT: always use inside while() loop not if()
```

---

### pthread_cond_signal()
```
pthread_cond_signal(&cond)
                     |
                     └── pthread_cond_t* → condition to signal

Returns: 0 = success | error code = failure
Wakes  : ONE waiting thread
```

---

### pthread_cond_broadcast()
```
pthread_cond_broadcast(&cond)
                        |
                        └── pthread_cond_t* → condition to broadcast

Returns: 0 = success | error code = failure
Wakes  : ALL waiting threads
```

---

### pthread_cond_destroy()
```
pthread_cond_destroy(&cond)
                      |
                      └── pthread_cond_t* → condition variable to destroy

Returns: 0 = success | error code = failure
```

---

## ═══════════════════════════════════
## SECTION 4 — SEMAPHORES (POSIX)
## ═══════════════════════════════════

### sem_init()
```
sem_init(&sem,       pshared,     value)
          |             |           |
          |             |           └── int → initial value of semaphore
          |             └── 0 = same process threads | 1 = across processes
          └── sem_t* → semaphore to initialize

Returns: 0 = success | -1 = failure
Header : #include <semaphore.h>
```

---

### sem_wait()
```
sem_wait(&sem)
          |
          └── sem_t* → semaphore to decrement

Returns: 0 = success | -1 = failure
Blocks : YES — if value is 0, waits until > 0
Effect : decrements semaphore value by 1 (P operation)
```

---

### sem_post()
```
sem_post(&sem)
          |
          └── sem_t* → semaphore to increment

Returns: 0 = success | -1 = failure
Blocks : NO — always returns immediately
Effect : increments semaphore value by 1 (V operation)
         wakes one waiting thread if any
```

---

### sem_trywait()
```
sem_trywait(&sem)
             |
             └── sem_t* → semaphore to try decrementing

Returns: 0 = success | -1 = failure (EAGAIN if value is 0)
Blocks : NO — returns immediately
```

---

### sem_timedwait()
```
sem_timedwait(&sem,        &timespec)
               |               |
               |               └── struct timespec* → absolute timeout time
               └── sem_t* → semaphore to wait on

Returns: 0 = success | -1 = failure (ETIMEDOUT if time expires)
Blocks : YES — but only until timeout
```

---

### sem_getvalue()
```
sem_getvalue(&sem,        &value)
              |               |
              |               └── int* → stores current semaphore value here
              └── sem_t* → semaphore to read

Returns: 0 = success | -1 = failure
```

---

### sem_destroy()
```
sem_destroy(&sem)
             |
             └── sem_t* → semaphore to destroy

Returns: 0 = success | -1 = failure
```

---

### Named Semaphores (across processes)
```
sem_open(name,        oflag,       mode,        value)
          |              |           |             |
          |              |           |             └── initial value (if creating)
          |              |           └── permissions e.g. 0644 (if creating)
          |              └── O_CREAT, O_EXCL etc
          └── "/name" → semaphore name (must start with /)

Returns: sem_t* = success | SEM_FAILED = failure

sem_close(&sem)   → close named semaphore (like fclose)
sem_unlink(name)  → delete named semaphore (like unlink)
```

---

## ═══════════════════════════════════
## SECTION 5 — FILE OPERATIONS
## ═══════════════════════════════════

### open()
```
open(path,          flags,         mode)
      |               |              |
      |               |              └── permissions e.g. 0666 (only for O_CREAT)
      |               └── O_RDONLY | O_WRONLY | O_RDWR | O_CREAT | O_TRUNC | O_APPEND
      └── const char* → file path

Returns: fd (int) = success | -1 = failure
Header : #include <fcntl.h>
```

---

### read()
```
read(fd,          buf,         count)
      |             |             |
      |             |             └── size_t → max bytes to read
      |             └── void* → buffer to store data
      └── int → file descriptor

Returns: bytes read = success | 0 = EOF | -1 = failure
Blocks : YES — waits for data if none available
```

---

### write()
```
write(fd,         buf,         count)
       |            |             |
       |            |             └── size_t → number of bytes to write
       |            └── const void* → data to write
       └── int → file descriptor

Returns: bytes written = success | -1 = failure
```

---

### lseek()
```
lseek(fd,         offset,       whence)
       |             |              |
       |             |              └── SEEK_SET=from start | SEEK_CUR=from current | SEEK_END=from end
       |             └── off_t → byte offset
       └── int → file descriptor

Returns: new offset from start = success | -1 = failure
```

---

### stat() / fstat()
```
stat(path,         &statbuf)
      |               |
      |               └── struct stat* → filled with file info
      └── const char* → file path

fstat(fd,          &statbuf)
       |               |
       |               └── struct stat* → filled with file info
       └── int → file descriptor

Returns: 0 = success | -1 = failure
Info   : statbuf.st_size = size | st_mode = permissions | st_mtime = modified time
```

---

### dup2()
```
dup2(oldfd,        newfd)
      |               |
      |               └── int → target fd number (closed first if open)
      └── int → source fd to duplicate

Returns: newfd = success | -1 = failure
Use    : redirect stdin/stdout/stderr
Example: dup2(file_fd, 1) → stdout now goes to file
```

---

## ═══════════════════════════════════
## SECTION 6 — PROCESS FUNCTIONS
## ═══════════════════════════════════

### fork()
```
fork()   ← no parameters

Returns: child PID → in parent process
         0          → in child process
        -1          → error
```

---

### wait()
```
wait(&status)
      |
      └── int* → stores exit status here (NULL = dont care)

Returns: PID of child that exited | -1 = error
Blocks : YES — waits for ANY child
Macros : WIFEXITED(status) | WEXITSTATUS(status)
```

---

### waitpid()
```
waitpid(pid,        &status,      options)
         |             |             |
         |             |             └── 0=block | WNOHANG=non blocking | WUNTRACED
         |             └── int* → exit status (NULL = dont care)
         └── pid_t → child PID (-1 = any child)

Returns: PID of child | 0 (WNOHANG, none done) | -1 = error
```

---

### execvp()
```
execvp(file,         argv[])
        |               |
        |               └── char*[] → argument array (argv[0]=program, last=NULL)
        └── const char* → program name (searches PATH)

Returns: never returns on success | -1 = failure
Note   : always add error handling after execvp — only reached if it fails
```

---

### kill()
```
kill(pid,          signal)
      |               |
      |               └── int → signal number (SIGTERM, SIGKILL, SIGUSR1 etc)
      └── pid_t → target process ID

Returns: 0 = success | -1 = failure
Note   : pid=0 means all processes in group | pid=-1 means all processes
```

---

## ═══════════════════════════════════
## SECTION 7 — SOCKET FUNCTIONS
## ═══════════════════════════════════

### socket()
```
socket(domain,        type,           protocol)
        |               |                |
        |               |                └── 0 = auto (almost always)
        |               └── SOCK_STREAM=TCP | SOCK_DGRAM=UDP | SOCK_RAW
        └── AF_INET=IPv4 | AF_INET6=IPv6 | AF_UNIX=local

Returns: fd (int) = success | -1 = failure
```

---

### bind()
```
bind(sockfd,       addr,              addrlen)
      |              |                    |
      |              |                    └── socklen_t → sizeof(addr)
      |              └── struct sockaddr* → IP + port to bind to
      └── int → socket fd

Returns: 0 = success | -1 = failure
```

---

### listen()
```
listen(sockfd,      backlog)
        |              |
        |              └── int → max clients in complete queue
        └── int → socket fd

Returns: 0 = success | -1 = failure
```

---

### accept()
```
accept(sockfd,       &client_addr,      &addrlen)
        |                |                  |
        |                |                  └── socklen_t* → size (pointer! kernel writes back)
        |                └── struct sockaddr* → kernel fills client IP+port here
        └── int → listening socket fd

Returns: NEW fd (int) = success | -1 = failure
Blocks : YES — waits until client connects
```

---

### connect()
```
connect(sockfd,       &server_addr,      addrlen)
         |                |                  |
         |                |                  └── socklen_t → sizeof(addr)
         |                └── struct sockaddr* → server IP + port
         └── int → socket fd

Returns: 0 = success | -1 = failure
Blocks : YES — waits for 3-way handshake to complete
```

---

### send()
```
send(sockfd,       buf,         len,        flags)
      |              |            |             |
      |              |            |             └── 0 = normal | MSG_DONTWAIT | MSG_NOSIGNAL
      |              |            └── size_t → bytes to send
      |              └── const void* → data to send
      └── int → connected socket fd

Returns: bytes sent = success | -1 = failure
Note   : may do partial send — always check return value
```

---

### recv()
```
recv(sockfd,       buf,         len,        flags)
      |              |            |             |
      |              |            |             └── 0 = normal | MSG_WAITALL | MSG_PEEK | MSG_DONTWAIT
      |              |            └── size_t → max bytes to receive
      |              └── void* → buffer to store data
      └── int → connected socket fd

Returns: bytes received = success | 0 = disconnected | -1 = failure
Blocks : YES — waits until data arrives
```

---

### sendto()
```
sendto(sockfd,    buf,    len,   flags,   dest_addr,      addrlen)
        |          |       |       |          |               |
        |          |       |       |          |               └── socklen_t → sizeof(addr) VALUE
        |          |       |       |          └── struct sockaddr* → who to send to
        |          |       |       └── 0 = normal
        |          |       └── size_t → bytes to send
        |          └── const void* → data
        └── int → socket fd

Returns: bytes sent = success | -1 = failure
Use    : UDP — specify destination every call
```

---

### recvfrom()
```
recvfrom(sockfd,  buf,   len,  flags,  src_addr,      &addrlen)
          |        |      |      |         |               |
          |        |      |      |         |               └── socklen_t* → POINTER (kernel writes back)
          |        |      |      |         └── struct sockaddr* → kernel fills sender info here
          |        |      |      └── 0 = normal
          |        |      └── size_t → max bytes to receive
          |        └── void* → buffer
          └── int → socket fd

Returns: bytes received = success | -1 = failure
Note   : addrlen is POINTER in recvfrom but VALUE in sendto ← common mistake
```

---

### setsockopt()
```
setsockopt(sockfd,    level,       optname,        &optval,    optlen)
            |           |             |               |            |
            |           |             |               |            └── socklen_t → sizeof(optval)
            |           |             |               └── void* → option value
            |           |             └── SO_REUSEADDR | SO_RCVTIMEO | SO_SNDBUF etc
            |           └── SOL_SOCKET = socket level | IPPROTO_TCP = TCP level
            └── int → socket fd

Returns: 0 = success | -1 = failure
Common : setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))
```

---

## ═══════════════════════════════════
## SECTION 8 — IPC FUNCTIONS
## ═══════════════════════════════════

### pipe()
```
pipe(fds[2])
      |
      └── int[2] → fds[0]=read end | fds[1]=write end

Returns: 0 = success | -1 = failure
Use    : one-way communication between parent and child
```

---

### shmget()
```
shmget(key,          size,         flags)
        |              |              |
        |              |              └── IPC_CREAT | 0666 permissions
        |              └── size_t → bytes of shared memory
        └── key_t → IPC_PRIVATE or ftok() generated key

Returns: shmid (int) = success | -1 = failure
```

---

### shmat()
```
shmat(shmid,        shmaddr,       flags)
       |               |              |
       |               |              └── 0 = read/write | SHM_RDONLY = read only
       |               └── NULL = let OS choose address
       └── int → shared memory ID from shmget()

Returns: void* pointer to shared memory | (void*)-1 = failure
```

---

### shmdt()
```
shmdt(shmaddr)
       |
       └── void* → pointer returned by shmat()

Returns: 0 = success | -1 = failure
```

---

### shmctl()
```
shmctl(shmid,       cmd,          &buf)
        |             |              |
        |             |              └── struct shmid_ds* → info (NULL for IPC_RMID)
        |             └── IPC_RMID=delete | IPC_STAT=get info | IPC_SET=set info
        └── int → shared memory ID

Returns: 0 = success | -1 = failure
Delete : shmctl(shmid, IPC_RMID, NULL)
```

---

### sem_init() vs semget() — Side by Side
```
POSIX semaphore:                    System V semaphore:
sem_init(&sem, 0, 1)                semget(key, nsems, flags)
sem_wait(&sem)                      semop(semid, &sops, 1)
sem_post(&sem)                      semctl(semid, 0, IPC_RMID)
sem_destroy(&sem)

POSIX  → simpler, use for threads
Sys V  → use for across processes
```

---

## ═══════════════════════════════════
## SECTION 9 — MEMORY FUNCTIONS
## ═══════════════════════════════════

### mmap()
```
mmap(addr,      length,      prot,          flags,         fd,      offset)
      |            |            |               |             |          |
      |            |            |               |             |          └── off_t → offset in file
      |            |            |               |             └── int → file fd (-1 for anonymous)
      |            |            |               └── MAP_SHARED | MAP_PRIVATE | MAP_ANONYMOUS
      |            |            └── PROT_READ | PROT_WRITE | PROT_EXEC | PROT_NONE
      |            └── size_t → bytes to map
      └── NULL = let OS choose address

Returns: void* pointer = success | MAP_FAILED = failure
Common : mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED, -1, 0)
```

---

### munmap()
```
munmap(addr,         length)
        |               |
        |               └── size_t → bytes to unmap
        └── void* → address from mmap()

Returns: 0 = success | -1 = failure
```

---

## ═══════════════════════════════════
## QUICK MEMORY CARD
## ═══════════════════════════════════

```
FUNCTION          PARAMS                          RETURNS
────────          ──────                          ───────
pthread_create    &tid, attr, func, arg           0 or error
pthread_join      tid, &retval                    0 or error
pthread_exit      retval                          never
pthread_self      (none)                          pthread_t
pthread_detach    tid                             0 or error

mutex_init        &mutex, attr                    0 or error
mutex_lock        &mutex                          0 or error
mutex_unlock      &mutex                          0 or error
mutex_trylock     &mutex                          0 or EBUSY

cond_wait         &cond, &mutex                   0 or error
cond_signal       &cond                           0 or error
cond_broadcast    &cond                           0 or error

sem_init          &sem, pshared, value            0 or -1
sem_wait          &sem                            0 or -1
sem_post          &sem                            0 or -1
sem_getvalue      &sem, &val                      0 or -1

socket            domain, type, protocol          fd or -1
bind              sockfd, &addr, len              0 or -1
listen            sockfd, backlog                 0 or -1
accept            sockfd, &addr, &len             NEW fd or -1
connect           sockfd, &addr, len              0 or -1
send              sockfd, buf, len, flags         bytes or -1
recv              sockfd, buf, len, flags         bytes, 0, -1
sendto            sockfd, buf, len, flags, &addr, len     bytes or -1
recvfrom          sockfd, buf, len, flags, &addr, &len    bytes or -1

fork              (none)                          pid or 0 or -1
wait              &status                         child pid or -1
waitpid           pid, &status, options           child pid or -1
execvp            file, argv[]                    never or -1

open              path, flags, mode               fd or -1
read              fd, buf, count                  bytes, 0, -1
write             fd, buf, count                  bytes or -1
lseek             fd, offset, whence              offset or -1
dup2              oldfd, newfd                    newfd or -1

pipe              fds[2]                          0 or -1
shmget            key, size, flags                shmid or -1
shmat             shmid, addr, flags              void* or -1
mmap              addr, len, prot, flags, fd, off void* or MAP_FAILED
```

---

## THE ONE TRICK TO REMEMBER PARAMETERS

```
Think of it as a SENTENCE:

socket(WHERE,    HOW,      WHAT_PROTOCOL)
bind  (WHO_AM_I, MY_ADDR,  MY_ADDR_SIZE)
connect(WHO_AM_I, DEST,    DEST_SIZE)
send  (WHO_AM_I, WHAT,     HOW_MUCH, HOW)
recv  (WHO_AM_I, WHERE,    MAX,      HOW)
sendto(WHO_AM_I, WHAT, HOW_MUCH, HOW, DEST,     DEST_SIZE)
recvfrom(WHO_AM_I, WHERE, MAX, HOW,  FROM,      &FROM_SIZE)

pthread_create(STORE_ID_HERE, OPTIONS, FUNCTION, ARGUMENT)
pthread_join  (WAIT_FOR_THIS, STORE_RETURN_HERE)
sem_init      (SEMAPHORE, SHARED?, INITIAL_VALUE)
```

---

*Socket + Systems + Threads + IPC + Memory*
