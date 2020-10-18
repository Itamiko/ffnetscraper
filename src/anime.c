#include "anime.h"

#include <stdlib.h>
#include <myhtml.h>
#include <llhttp.h>
#include <myhtml/api.h>

int return_zero(void)
{
	return EXIT_SUCCESS;
}

int return_request(char html_file[])
{
	myhtml_t *myhtml = myhtml_create();
	myhtml_init(myhtml, MyHTML_OPTIONS_DEFAULT, 1 ,0);
	myhtml_tree_t *tree = myhtml_tree_create();
	myhtml_tree_init(tree, myhtml);
	myhtml_parse(tree, MyENCODING_UTF_8, html_file, strlen(html_file));
	mycore_string_raw_t str = {0};
	myhtml_serialization_tree_buffer(myhtml_tree_get_document(tree), &str);
	mycore_string_raw_destroy(&str, false);
	myhtml_tree_destroy(tree);
	myhtml_destroy(myhtml);

	return EXIT_SUCCESS;
}
