gcc -o push main.c libft/libft.a
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"` ; ./push $ARG
#./a.out 10 5 18 20 19 8 13 14 17 4 16 12 3 2 1 7 15 11 6 9
