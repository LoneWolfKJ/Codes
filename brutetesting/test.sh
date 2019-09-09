for((i=1; i<=100;i++)); do
	# echo $i
	./gen $i > int
	diff -w <(./correct < int) <(./incorrect < int) || break
done
