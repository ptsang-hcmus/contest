for ((i = 1; i <= 1; ++i)); do
    echo Testing $i ...
    diff -w <(./a.exe <./io/in$i) ./io/out$i || break
    echo Test $i: Accepted
done
