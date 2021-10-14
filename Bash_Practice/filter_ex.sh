for i in ./*; do
	if [[ -d $i ]]; then
		echo "This is Directory"
	else
		filesize=$( wc $i | awk '{print $3}' )
		echo "$i filesize : $filesize"
		if [[ $filesize -lt 50 ]]; then
			echo "file smaller than 50"
		else
			echo "file bigger than 50 or same"
		fi
	fi	
done

