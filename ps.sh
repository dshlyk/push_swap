gcc libft/libft.a main.c
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"` ; ./a.out $ARG
#./a.out 10 5 18 20 19 8 13 14 17 4 16 12 3 2 1 7 15 11 6 9
