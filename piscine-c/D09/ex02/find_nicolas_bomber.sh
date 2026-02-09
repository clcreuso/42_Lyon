awk ' {print $1, $2, $3} ' contacts_easy.txt | grep -iE 'nicolas bauer|bauer nicolas' | cut -d' ' -f3 | sed 'n;d'
