./vm_champs/corewarNEW -v $1 $2 > origin_out.txt;
./corewar -v $1 $2 > project_out.txt
diff -q origin_out.txt project_out.txt > test.diff