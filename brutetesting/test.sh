for((i=1; i<=100000;i++)); do
	echo $i
	./gen $i > int$i
	./correct <int$i> out$i
	./incorrect <int$i> outs$i
	diff -w out$i outs$i || break
	#diff -w <(./correct < int) <(./incorrect < int) || break
done
