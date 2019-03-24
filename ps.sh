gcc libft/libft.a main.c
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"` ; ./a.out $ARG | wc -l
