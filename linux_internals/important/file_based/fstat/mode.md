### `st_mode` contains two things packed into one integer:

```
st_mode bits:
┌─────────────────────┬─────────────────────┐
│   file type bits    │  permission bits     │
│   (top bits)        │  (bottom 12 bits)    │
│   S_IFREG, S_IFDIR  │  rwxrwxrwx + sticky  │
└─────────────────────┴─────────────────────┘
```

For example a regular file with `644` permissions:
```
st_mode = 0100644
           │  └── 644 = permission bits
           └───── 100 = regular file type (S_IFREG)
```

---

### So:

```c
fchmod(dst_fd, st.st_mode);         // passes 0100644
                                     // fchmod sees file type bits too
                                     // undefined/wrong behavior

fchmod(dst_fd, st.st_mode & 0777);  // 0100644 & 0000777 = 0000644
                                     // masks out file type bits
                                     // only passes clean permission bits ✓
```

---

### The `& 0777` mask in binary:

```
0100644  =  001 000 000 110 100 100
0000777  =  000 000 000 111 111 111
                       &
0000644  =  000 000 000 110 100 100
                       ↑
                  only these bits survive
```

So `& 0777` zeroes out everything except the bottom 9 permission bits (`rwxrwxrwx`).
