# include <string.h>
# include "word.h"
# include "line.h"

# define MAX_WORD_LEN 20

main(){
	char word[MAX_WORD_LEN + 2];
	int word_len;
	
	for(;;){
		read_word(word, MAX_WORD_LEN + 1);
		word_len = strlen(word);
		
		if(word_len == 0){
			flush_line();
			clear_line();
		}
		if(word_len > MAX_WORD_LEN)
			word[MAX_WORD_LEN] = '*';
		if(word_len + 1 > space_remaining()){
			write_line();
			clear_line();
		}
		
		add_word(word);
	}
}
