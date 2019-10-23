END=$2
for ((i = $1; i < END; i++)) do
	echo $i
	./corewar -d $i $3 > project_out.txt;
	./vm_champs/corewarNEW -d $i $3 > origin_out.txt;
	diff -q origin_out.txt project_out.txt
done
