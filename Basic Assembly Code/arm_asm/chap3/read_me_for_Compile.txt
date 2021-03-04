If you want to compile the file without using the standard c library

gcc -nostdlib main.c -o a.out

If you want to generate the "Filename.S" Assembly source code file

gcc -nostdlib main.c -S -o main.s

If you want to remove the previous file first and then compile and view the output

rm main.s && gcc -nostdlib main.c -S -o main.s && cat main.s




