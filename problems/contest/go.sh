if [ $# -eq 0 ]; then
	echo "Invalid folder";
else
	mkdir $1 2> /dev/null
	rm ./$1/*
	cp /home/fakhoury/Documents/competitive-programming/lib/misc/environment/bash.sh ./$1/test.sh
	cp /home/fakhoury/Documents/competitive-programming/lib/misc/environment/clion_template.cpp ./$1/sol.cpp
fi
