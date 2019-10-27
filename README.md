# Buddy-Memory-allocator
Implementation of Buddy Memory allocator in C++

## Sample Output

Enter maximum memory available <=4096 bytes <br>
**2048** <br>
enter stuff <br>
**1 127** <br>
Memory allocated from 1 to 128. Total= 128 bytes <br>
**1 512** <br>
Memory allocated from 513 to 1024. Total= 512 bytes <br>
**1 512** <br>
Memory allocated from 1025 to 1536. Total= 512 bytes <br>
**2 513** <br>
Memory block from 513 freed <br>
**2 1025** <br>
Memory block from 1025 freed <br>
**3** <br>
Memory free of size 128 : <br>
129 to 256 <br>
Memory free of size 256 : <br>
257 to 512 <br>
Memory free of size 512 : <br>
1537 to 2048 <br>
513 to 1024 <br>
Memory allocated: <br>
1 to 2 <br>
**4** <br>
