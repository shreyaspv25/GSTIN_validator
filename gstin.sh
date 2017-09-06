#!/bin/bash
selected_file=$(zenity --title="File Selector" --file-selection --file-filter=*.csv)
cat $PWD/$selected_file | sed 's/,/|/g' > gstin_abstract
rm $PWD/*.csv
$PWD/gstin gstin_abstract
if [ $? -eq 0 ]
then
	exit 0
else
	exit 1
fi
