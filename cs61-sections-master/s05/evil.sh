if [ $1 -le 1 ]; then echo $1; exit; fi
val=$(($(sh $0 $(($1 - 1))) + $(sh $0 $(($1 - 2)))))
>&2 echo "fib($1) = $val"
echo $val
