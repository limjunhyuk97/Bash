name=$1

find . -type f -name $1 | read file; if [[ -e $file ]]; then
	echo $file >> ./file_loc.txt
fi

