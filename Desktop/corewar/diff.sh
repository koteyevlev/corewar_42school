./corewar -d $1 $2 > project_dump.txt;
./vm_champs/corewar -d $1 $2 > origin_dump.txt;
diff -q origin_dump.txt project_dump.txt
diff origin_dump.txt project_dump.txt > $1.diff