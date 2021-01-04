if [ $# -eq 0 ]; then
	MAX_PROB=15
else
    MAX_PROB=$(printf '%d' "'$1")
    MAX_PROB=$(( $MAX_PROB - 64 ))
fi


(mkdir "tasks") 2> /dev/null
(mkdir "output") 2> /dev/null

echo "Creating "$MAX_PROB" problems."
for counter in $(seq 1 $MAX_PROB); do
	i=$(( $counter + 64 ));
	c=$(printf \\$(printf '%03o' $i));
	c="tasks/"$c
	(mkdir $c) 2> /dev/null
	(cp "template.cpp" $c"/sol.cpp")
	(cp "bash.sh" $c"/test.sh")
	(chmod +x $c"/test.sh")
	echo "Created folder "$c
done