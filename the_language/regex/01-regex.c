#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

int regex_match (char *pattern, const char *default_string);

int main(int argc, char *argv[])
{
    char *default_string = "C Language Programming";
    char *pattern = "guag";
    
    if (regex_match (pattern, default_string))
		printf ("La ricerca del pattern \'%s\' ha avuto successo; "
				"trovata corrispondenza nella stringa \'%s\'\n", pattern, default_string);
	else
		printf ("La ricerca del pattern \'%s\' non ha avuto successo; "
				"nessuna corrispondenza nella stringa \'%s\'\n",
				pattern, default_string);

    return(EXIT_SUCCESS);
}

int regex_match (char *pattern, const char *default_string)
{
    int status;
    regex_t preg;

    status = regcomp (&preg, pattern, REG_EXTENDED|REG_NOSUB);
    
	if (status != 0)
        return (EXIT_FAILURE);
    
	status = regexec(&preg, default_string, (size_t) 0, NULL, 0);
    
	if (status != 0)
      {
        regfree (&preg);
        return (EXIT_FAILURE);
      }

    regfree (&preg);
    
	return(EXIT_SUCCESS);
}
